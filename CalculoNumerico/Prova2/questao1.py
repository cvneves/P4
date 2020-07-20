import numpy as np
from numpy.linalg import solve
from numpy.linalg import norm

alpha = 0.7071
beta = 0.6585
gamma = 0.7526

sparseMat  = []
sparseMat.append([2,1,1])
sparseMat.append([1,1,alpha])
sparseMat.append([2,2,-1])
sparseMat.append([6,2,1])
sparseMat.append([3,3,1])
sparseMat.append([4,4,1])
sparseMat.append([5,4,beta])
sparseMat.append([1,4,-alpha])
sparseMat.append([1,5,alpha])
sparseMat.append([3,5,1])
sparseMat.append([5,5,gamma])
sparseMat.append([7,6,1])
sparseMat.append([8,6,beta])
sparseMat.append([4,6,-1])
sparseMat.append([8,7,gamma])
sparseMat.append([9,7,1])
sparseMat.append([10,8,1])
sparseMat.append([5,8,-beta])
sparseMat.append([6,8,-1])
sparseMat.append([9,9,1])
sparseMat.append([5,9,gamma])
sparseMat.append([11,10,alpha])
sparseMat.append([7,10,-1])
sparseMat.append([11,11,alpha])
sparseMat.append([12,11,1])
sparseMat.append([12,12,1])
sparseMat.append([8,12,gamma])
sparseMat.append([13,13,1])
sparseMat.append([11,13,alpha])

sparseRhs = [];
sparseRhs.append([3,2000])
sparseRhs.append([5,-1000])
sparseRhs.append([7,-500])
sparseRhs.append([9,4000])
sparseRhs.append([11,-500])
sparseRhs.append([12,2000])

n = 13

A = np.zeros((n,n))
b = np.zeros(n)

for element in sparseMat:
    A[element[1] - 1][element[0] - 1] = element[2]

for element in sparseRhs:
    b[element[0]-1] = element[1]


# A = np.array([
#     [55, -5, -30], 
#     [-5, 70, -15], 
#     [-30,-15,45]]
# )

# b = np.array([0,0,120])
x = solve(A,b)

print(x)
print(np.linalg.norm(x))
