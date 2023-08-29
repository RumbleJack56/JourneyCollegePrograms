import cv2
import torch
import numpy as np

img = cv2.imread("1.jpg")
print(img)

cv2.imshow("13",img)
rgbimg = cv2.cvtColor(img,cv2.COLOR_BGR2RGB)
imgtensor = torch.IntTensor(rgbimg)
