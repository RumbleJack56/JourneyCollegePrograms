#we use cv2 library for image processing
import cv2
#image path can be changed to whatever photograph
imgpath = "shape.jpg"

#function is defined
#input parameters are path of file to convert
#optionally one can also tell the name of the output file
#if no name is given, the output file is defaulted as
# "grey filename.jpg"
def bwImage(path,fname="default"):
    #default filename change code
    if fname=="default" : fname="grey "+path

    #reads file
    img = cv2.imread(path)
    #converst to greysacle
    grey = cv2.cvtColor(img,cv2.COLOR_BGR2GRAY)
    #write to file
    cv2.imwrite(fname, grey)
    #return image object, incase used by program
    return grey

#function call
bwImage(imgpath)