from colorsys import rgb_to_hsv
import cv2
import numpy as np

#input
imagelist = ["1.jpg","2.jpg","3.jpg",'4.jpg']


"""
we create a class with the details for the scenario
the class has the following functions
findTrianges
begin
computePriority

Auxilary Functions:
showRaw,showGreen, showBrown
"""
############################################################################
#class declaration begins
class fireScene():
    def __init__(self,imPath,frameName):
        #initialise color bounds
        self.greenBounds = [np.array([50,50,0]) , np.array([90,255,255])]
        self.brownBounds = [np.array([1,100,5]) , np.array([35,255,150])]

        #make image, and hsv image matrices
        self.img = cv2.GaussianBlur(cv2.imread(imPath), (3,3), 0)
        self.hsvimg = cv2.cvtColor(self.img,cv2.COLOR_BGR2HSV_FULL)

        #marked image is used later as an output for parsing the triangles
        self.markedimg = self.img.copy()

        #name of Frame window and dimensions
        self.frameName=frameName
        self.dimensions=self.img.shape

        #MASKS
        #mask for green area
        self.greenMask = cv2.inRange(self.hsvimg,self.greenBounds[0],self.greenBounds[1])
        self.brownMask = cv2.inRange(self.hsvimg, self.brownBounds[0],self.brownBounds[1])
        
        #initialise colormask
        colormaskYellow = np.zeros(self.dimensions,dtype=np.uint8)
        colormaskCyan = np.zeros(self.dimensions,dtype=np.uint8)
        
        #set colors value with BGR format
        colormaskCyan[:] = (251,251,101)
        colormaskYellow[:] = (105,251,251)

        #colormasks are bitwise added, masking them, with the colormasks inplace
        colormaskYellow = cv2.bitwise_and(colormaskYellow,colormaskYellow,mask=self.brownMask)
        colormaskCyan = cv2.bitwise_and(colormaskCyan,colormaskCyan,mask=self.greenMask)

        #images are combined, but they still lack the triangle regions
        #currently triangles are black
        self.colormaskCombine = cv2.add(colormaskCyan,colormaskYellow)

        #to get color triangles, we invert a combined green and brown mask
        #then we select that from the original image and mask
        greenBrownMask = cv2.bitwise_not(cv2.bitwise_or(self.greenMask,self.brownMask))
        triangleSelect = cv2.bitwise_and(self.img,self.img,mask=greenBrownMask)

        #the triangle mask is also added to the combine imaged which is output by function
        self.colormaskCombine = cv2.add(self.colormaskCombine, triangleSelect)



        #shows burnt and safe region in orignal color    
        self.safeRegion = cv2.bitwise_and(self.img,self.img,mask=self.greenMask)
        self.burnRegion = cv2.bitwise_and(self.img,self.img,mask=self.brownMask)

    def showParsedImage(self):
        #shows the output image
        cv2.imshow("Parsed Image - "+self.frameName,self.colormaskCombine)
        #also returns the output image object for parsing further in program
        return self.colormaskCombine
    
    def findTriangles(self):

        #nested function to tell if a given HSV color is brown
        def isBrown(a,b,c):
            if a in range(self.brownBounds[0][0],self.brownBounds[1][0]+1):
                if b in range(self.brownBounds[0][1],self.brownBounds[1][1]+1):
                    if c in range(self.brownBounds[0][2],self.brownBounds[1][2]+1):
                        return True
            return False
        

        #nested function to tell if a given HSV color is green
        def isGreen(a,b,c):
            if a in range(self.greenBounds[0][0],self.greenBounds[1][0]):
                if b in range(self.greenBounds[0][1],self.greenBounds[1][1]):
                    if c in range(self.greenBounds[0][2],self.greenBounds[1][2]):
                        return True
            return False

        #first we seperate the color channels to find red and blue triangles
        #respective  colors in red and blue triangles will have a high threshold
        #we use that threshold to select that region and mask it
        
        #color channel seperation and unpacking
        b,g,r = cv2.split(self.img)
        #initialise list for storing output points
        outputPoints = []
        #iterates two loops for blue color and red color maps
        for mapColor,colorname in ([b,"blue"],[r,"red"]):
            #cv2 threshold function returns two values, we need the second value which is the heatmap of threshold function
            #we use the heatmap to mask the original image for specific color triangles
            trianglemask = cv2.threshold(mapColor,150,255,cv2.THRESH_BINARY)[1] #here the 1 signifies the second value
            #takes the colored image on threshold map
            img = cv2.bitwise_and(self.img,self.img,mask=trianglemask)
            # grayscale convert
            img = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)
            
            #now we take almost any non zero value in the threshold map
            #because it signifies presence of triangle
            #since this is a second heatmap, we have extreme control on accuracy
            #nesting heatmaps increases point granularity
            thresh = cv2.threshold(img,5,255,0)[1] #again we take second output of threshold function

            #now we take contours in threshold mapping
            #contour gives 2 outputs in a list, we need first one hence the [0] index
            contourList = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)[0]

            for c in contourList:
                #moment variables
                M = cv2.moments(c)

                #by documentation this is how we find the center of the triangle shape
                cX = int(M["m10"] / M["m00"])
                cY = int(M["m01"] / M["m00"])

                #take color from an offsetted point
                bd,gd,rd = self.img[cY+30][cX]
                #convert to HSV
                h,s,v = rgb_to_hsv(rd,gd,bd)
                #format to HSV FULL 
                h=int(h*255)
                s=int(s*255)
                v=int(v)

                #initialise printval
                printval = ""
                #check if house is burnt and append to outputPoints list
                if isBrown(h,s,v):
                    printval= colorname+" brown"
                    outputPoints.append(["b",colorname,cX,cY])
                #similarly if on green, append to outputPoints
                if isGreen(h,s,v):
                    printval=colorname+" green"
                    outputPoints.append(["g",colorname,cX,cY])
                
                #put c
                cv2.circle(self.markedimg, (cX, cY), 5, (255, 255, 255), -1)
                cv2.putText(self.markedimg, printval, (cX - 25, cY - 25),cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
        #return format = List of list[area=>("b" or "g"),color=>("blue" or "red"), x coordinate, y coordinate]
        return outputPoints
    def computePriority(self,hb,hg,bb,rb,bg,rg):
        #takes the output format and calculates the rescue ratio
        n_houses = [hb,hg]
        pb , pg = 2*bb+rb,2*bg+rg
        priority_houses = [pb,pg]
        priority_ratio = pb/pg
        #returns the houses priority and ratio of one case
        return n_houses , priority_houses , priority_ratio

    def begin(self):
        cv2.waitKey(0)
        cv2.destroyAllWindows

    #AUXILARY FUNCTIONS - unused in program, but useful in applications
    def safeRegionShow(self):
        cv2.imshow("Safe Region - "+self.frameName,self.safeRegion)
    def burnRegionShow(self):
        cv2.imshow("Burn Region - "+self.frameName,self.burnRegion)
    def showRaw(self):
        cv2.imshow("Base -"+self.frameName ,self.img)
    def showMarkings(self):
        cv2.imshow("Marked Image -"+self.frameName, self.markedimg)
#class definition ends here
#######################################################################################



#######################################################################################
#function declarations
def uasTask(inputimages):
    #makes a big list for houses priority and ratio
    n_houses , priority_houses, priority_ratio = [] , [] , []
    # dictionary for keying image to rescue ratio
    image_ratio_dict = {}

    #
    for imageindex in range(len(inputimages)):
        #creates and object of the class
        scene = fireScene(inputimages[imageindex],str(inputimages[imageindex])) 
        #displays parsed image
        scene.showParsedImage()

        # finds triangles using function
        data = scene.findTriangles()
        
        #show markings
        scene.showMarkings()
        #initialise counter variables
        Hburn , Hgrass , Bburn , Rburn , Bgreen , Rgreen = 0 , 0 , 0 , 0 , 0 , 0
        #increment counters when case fulfills
        for k in data:
            if k[0]=="b":
                Hburn+=1
                if k[1] =="blue": Bburn+=1
                if k[1] =="red":  Rburn+=1
            if k[0]=="g":
                Hgrass+=1
                if k[1] =="blue": Bgreen+=1
                if k[1] =="red":  Rgreen+=1
        #computes priority using counters
        house , priority , ratio = scene.computePriority(Hburn , Hgrass , Bburn , Rburn , Bgreen , Rgreen)
        #appends the data to main lists
        n_houses.append(house)
        priority_houses.append(priority)
        priority_ratio.append(ratio)
        #inputs a key value pair to dictionary for keying
        image_ratio_dict[inputimages[imageindex]]=ratio
    #image by rescue ratio using sorted function and lambda keying
    image_by_rescue_ratio = sorted(inputimages,key= lambda x:image_ratio_dict[x],reverse=True)
    #returns required paraments
    return n_houses , priority_houses, priority_ratio , image_by_rescue_ratio
###########################################################################################################
#actual programs

#function call
answer = uasTask(imagelist)
#print answer
[print(values) for values in answer]
#make the windows stay
cv2.waitKey(0)
cv2.destroyAllWindows()
