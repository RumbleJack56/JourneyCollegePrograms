import cv2
import numpy as np
from colorsys import rgb_to_hsv

im = cv2.imread("1.jpg")
hsvim = cv2.cvtColor(im, cv2.COLOR_BGR2HSV)
greenMask = cv2.inRange(hsvim,np.array([50,50,0]),np.array([90,255,255]))
brownMask = cv2.inRange(hsvimg, self.brownBounds[0],self.brownBounds[1])




def findTriangles(originalImg):
    greenBounds = [np.array([50,50,0]) , np.array([90,255,255])]
    brownBounds = [np.array([1,100,5]) , np.array([35,255,150])]

    #nested function to tell if a given HSV color is brown
    def isBrown(a,b,c):
            if a in range(brownBounds[0][0],brownBounds[1][0]+1):
                if b in range(brownBounds[0][1],brownBounds[1][1]+1):
                    if c in range(brownBounds[0][2],brownBounds[1][2]+1):
                        return True
            return False
    
    #nested function to tell if a given HSV color is green
    def isGreen(a,b,c):
            if a in range(greenBounds[0][0],greenBounds[1][0]):
                if b in range(greenBounds[0][1],greenBounds[1][1]):
                    if c in range(greenBounds[0][2],greenBounds[1][2]):
                        return True
            return False
    
    #first we seperate the color channels to find red and blue triangles
    #respective  colors in red and blue triangles will have a high threshold
    #we use that threshold to select that region and mask it
    
    #color channel seperation and unpacking
    b,g,r = cv2.split(originalImg)


    triangleDataToFind = [b,"blue"],[r,"red"]

    for mapColor,colorname in (triangleDataToFind):
        trianglemask = cv2.threshold(mapColor,150,255,cv2.THRESH_BINARY)[1]
        outImg = cv2.bitwise_and(originalImg,originalImg,mask=trianglemask)
        outImg = cv2.cvtColor(outImg, cv2.COLOR_BGR2GRAY)
        thresh = cv2.threshold(outImg,5,255,0)[1]
        contourList = cv2.findContours(thresh,cv2.RETR_TREE,cv2.CHAIN_APPROX_SIMPLE)[0]
        for c in contourList:
            M = cv2.moments(c)
            cX = int(M["m10"] / M["m00"])
            cY = int(M["m01"] / M["m00"])
            bd,gd,rd = originalImg[cY+30][cX]
            h,s,v = rgb_to_hsv(rd,gd,bd)
            h=int(h*255)
            s=int(s*255)
            v=int(v)
            printval = ""
            if isBrown(h,s,v):
                printval= colorname+" brown"
                print(["b",colorname,cX,cY])
            if isGreen(h,s,v):
                printval=colorname+" green"
                print(["g",colorname,cX,cY])
            cv2.circle(originalImg, (cX, cY), 5, (255, 255, 255), -1)
            xcor , ycor = cX - 25, cY - 25
            tColor = (255, 255, 255)
            font = cv2.FONT_HERSHEY_SIMPLEX
            cv2.putText(originalImg,printval,(xcor,ycor),font,0.5 ,tColor, 2)
    cv2.imshow("window",originalImg)
    cv2.waitKey(0)
    cv2.destroyAllWindows()

