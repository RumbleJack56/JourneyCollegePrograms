initDist = getFwdDist()
if initDist < 1.2:
    right()
forward(0.5)
newdist= getFwdDist()
v = 2 * (initDist - newDist)
s=0
while True:
    forward(0.1)
    s+=v*0.1
    newdist=getFwdDist()
    if newdist < 1.2 and s>5:
        left()
    elif newdist < 1.2:
        right()
    