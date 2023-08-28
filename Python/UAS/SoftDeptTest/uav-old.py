from colorsys import rgb_to_hsv
import cv2
import numpy as np

imagepath='3.jpg'


class FireScene():
    def __init__(self, imPath,frameName):
        self.greenBounds = [np.array([50,50,0]) , np.array([90,255,255])]
        self.brownBounds = [np.array([1,100,5]) , np.array([35,255,150])]


        #original image, blurred to 3px square, guassian
        self.img = cv2.GaussianBlur(cv2.imread(imPath), (3,3), 0)
        #marked image is used later as an output for parsing the triangles
        self.markedimg = self.img.copy()
        #
        self.hsvimg = cv2.cvtColor(self.img,cv2.COLOR_BGR2HSV_FULL)
        self.frameName=frameName



        ##################################################################################
        #MASKS
        self.gmask = cv2.inRange(self.hsvimg,self.greenBounds[0],self.greenBounds[1])
        self.safeRegion = cv2.bitwise_and(self.img,self.img,mask=self.gmask)

        self.bmask = cv2.inRange(self.hsvimg, self.brownBounds[0],self.brownBounds[1])
        self.burnRegion = cv2.bitwise_and(self.img,self.img,mask=self.bmask)

    
        ##################################################################################

        bMap,gMap,rMap = cv2.split(self.img)

    def safeRegionShow(self):
        cv2.imshow("Safe Region - "+self.frameName,self.safeRegion)
    def burnRegionShow(self):
        cv2.imshow("Burn Region - "+self.frameName,self.burnRegion)
    def showRaw(self):
        cv2.imshow("Base -"+self.frameName ,self.img)
    def begin(self):
        cv2.waitKey(0)
        cv2.destroyAllWindows()
    
    def findTriangles(self):
        def isBrown(a,b,c):
            if a in range(self.brownBounds[0][0],self.brownBounds[1][0]+1):
                if b in range(self.brownBounds[0][1],self.brownBounds[1][1]+1):
                    if c in range(self.brownBounds[0][2],self.brownBounds[1][2]+1):
                        return True
            return False
        
        def isGreen(a,b,c):
            if a in range(self.greenBounds[0][0],self.greenBounds[1][0]):
                if b in range(self.greenBounds[0][1],self.greenBounds[1][1]):
                    if c in range(self.greenBounds[0][2],self.greenBounds[1][2]):
                        return True
            return False
        

        b,g,r = cv2.split(self.img)
        outPoints = []
        for mapType,color in ([b,"blue"],[r,"red"]):
            trianglemask = cv2.threshold(mapType,150,255,cv2.THRESH_BINARY)[1]

            img = cv2.bitwise_and(Case.img,Case.img,mask=trianglemask)
            gray_image = cv2.cvtColor(img, cv2.COLOR_BGR2GRAY)


            thresh = cv2.threshold(gray_image,5,255,0)[1]

            #temp


            # find contours in the binary image
            a = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)
            for c in a[0]:
                M = cv2.moments(c)
            
                cX = int(M["m10"] / M["m00"])
                cY = int(M["m01"] / M["m00"])

                bd,gd,rd = self.img[cY+30][cX]
                h,s,v = rgb_to_hsv(rd,gd,bd)
                h=int(h*255)
                s=int(s*255)
                v=int(v)

                #temp
                print(cX,cY, h,s,v)


                
                printval = ""
                if isBrown(h,s,v):
                    printval= color+" brown "+str(cX)+" "+str(cY)
                    outPoints.append(["b",color,cX,cY])
                if isGreen(h,s,v):
                    printval=color+" green "+str(cX)+" "+str(cY)
                    outPoints.append(["g",color,cX,cY,])



                cv2.circle(self.markedimg, (cX, cY), 5, (255, 255, 255), -1)
                cv2.putText(self.markedimg, printval, (cX - 25, cY - 25),cv2.FONT_HERSHEY_SIMPLEX, 0.5, (255, 255, 255), 2)
        # display the image
        cv2.imshow("points on image",self.markedimg)
        return self.markedimg , outPoints
     



Case = FireScene(imagepath,"UAV")
Case.safeRegionShow()
Case.burnRegionShow()
print(Case.findTriangles()[1])
Case.begin()

