from matplotlib import pyplot as PLT
from matplotlib import cm as CM
from matplotlib import mlab as ML
import numpy as NP
from scipy import stats as st
n = 1e3
x = y = NP.linspace(-10,10, int(n))
X, Y = NP.meshgrid(x, y)

Z1 = st.multivariate_normal((0,4),[[2,3],[3,25]])
Z1 = Z1.pdf(NP.dstack((X, Y)))
Z2 = st.multivariate_normal((4,4),[[22,5],[5,3]])
Z2 = Z2.pdf(NP.dstack((X, Y)))


ZD = Z2 - Z1
x = X.ravel()
y = Y.ravel()
z = ZD.ravel()
gridsize=50
PLT.subplot(111)

# if 'bins=None', then color of each hexagon corresponds directly to its count
# 'C' is optional--it maps values to x-y coordinates; if 'C' is None (default) then 
# the result is a pure 2D histogram 

PLT.hexbin(x, y, C=z, gridsize=gridsize, cmap=CM.jet, bins=None)
PLT.axis([x.min(), x.max(), y.min(), y.max()])

cb = PLT.colorbar()
cb.set_label('mean value')
PLT.show()   