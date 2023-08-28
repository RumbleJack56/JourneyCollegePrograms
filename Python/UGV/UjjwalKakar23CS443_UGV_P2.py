#we use cv2 library for image processing
import cv2
import numpy as np
#image path can be changed to whatever photograph
imgpath = "scene.jpg"

#function for average color
def avcolor(path):
    #nested function for summing pixel values in a matrix
    def sumC(m):
        c=0
        #basic 2d array summation with a counter variable and return
        for x in m:
            for y in x:
                c+=y
        return c
    #read image
    img= cv2.imread(path)
    #take number of pixels byt multiplying resolution
    pixelcount = img.shape[0] *img.shape[1]
    #split color channels for individual computuation
    b,g,r = cv2.split(img)
    #average by sum/total
    bavg = sumC(b)/pixelcount
    gavg = sumC(g)/pixelcount
    ravg = sumC(r)/pixelcount
    #prints value and return too
    print(ravg,gavg,bavg)
    #black 100x100 image
    outcolor = np.zeros((300, 300, 3), np.uint8)
    #set color to avg value
    outcolor[:] = (int(bavg),int(gavg),int(ravg))
    #display color on screen
    cv2.imshow("Average Color",outcolor)
    cv2.waitKey(0)
    cv2.destroyAllWindows()
    return ravg,gavg,bavg
#function call
avcolor(imgpath)
