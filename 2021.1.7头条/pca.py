import numpy as np
from numpy import linalg as la

def pca(features, k):
    A = np.dot(features.T, features)/float(features.shape[0])
    U,sigma,UT = la.svd(A)
    U = U[:, :k]
    sigma = sigma[::k]
    return np.dot(features, U)

features = np.array([[-1,-2],[-1,0],[0,0],[2,1],[0,1]])
print(pca(features, 1))
