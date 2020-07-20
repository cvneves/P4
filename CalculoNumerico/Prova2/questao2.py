import numpy as np
from numpy.linalg import solve
from numpy.linalg import norm

T = np.array([79,190,357,524,690])
k = np.array([1,0.932,0.839,0.759,0.693])

def getDividedDiff(x, y):
    n = x.size
    divDiff = np.zeros((n,n))

    k = 0
    for j in range(0,n):
        for i in range(j, -1,-1):
            if(i == j):
                divDiff[i][j] = y[i]
                continue
            divDiff[i][j] = (divDiff[i+1][j] - divDiff[i][j-1])/(x[j] - x[i])

    return divDiff

def newtonPolynomial(value,x, divDiff):
    n = x.size
    sumF = divDiff[0][0]
    productX = 1
    for i in range(0, n-1):
        productX = productX * (value - x[i])
        sumF = sumF + divDiff[0][i+1] * productX
        
    return sumF
        

print(getDividedDiff(T,k))
print(newtonPolynomial(222, T, getDividedDiff(T,k)))
