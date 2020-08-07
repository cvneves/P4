import math
import numpy as np

# INTEGRAIS

def f1(x):
    return (1/(x**4 + 1))

def f2(x):
    return 2 * math.sin(2 * x)

def simpsonComposto(f, a, b, n):
    soma = 0
    h = (b-a)/n
    for j in range(1, int(n/2) + 1):
        soma += f(a + (2*j - 2) * h) + 4 * f(a + (2*j - 1) * h) + f(a + (2*j) * h)
    soma = soma * h / 3
    return soma

def trapezioComposto(f, a, b, n):
    soma = 0
    h = (b - a) / n
    for j in range(0, n + 1):
        t = 2
        if j == 0 or j == n:
            t = 1
        soma += t * f(a + h * j)
    soma *= h/2
    return soma

# EDO

def f3(x,y):
    return (2000 - 2*y)/(200 - x)

def f4(x,y):
    return 2e-6*(100000 - y)*y

def eulerAperfeicoado(f, h, x0, y0, x):
    xn = x0
    yn = y0
    while abs(xn - x) > 1e-8:
        k1 = f(xn, yn)
        k2 = f(xn + h, yn + h * k1)

        xn += h
        yn += (k1 + k2) * h/2
     
    return yn

def krutaOrdem4(f, h, x0, y0, x):
    xn = x0
    yn = y0
    while abs(xn - x) > 1e-8:
        k1 = np.float32(h * f(xn, yn))
        k2 = np.float32(h * f(xn + h/2, yn + k1/2))
        k3 = np.float32(h * f(xn + h/2, yn + k2/2))
        k4 = np.float32(h * f(xn + h, yn + k3))
        
        yn += (k1 + 2*k2 + 2*k3 + k4)/6
        xn += h
        # print(xn,yn,k1,k2,k3,k4)

    return yn

# Questao 1
print("Integral estimada: ", simpsonComposto(f1, -1, 1, 8))

# Questao 2
print("Simpson: ", simpsonComposto(f2, 0, math.pi, 6))
print("Trapezio: ", trapezioComposto(f2, 0, math.pi, 6))

# Questao 3
print(eulerAperfeicoado(f3, 0.5, 0, 0, 5))
print(krutaOrdem4(f3, 0.5, 0,0,5))

# Questao 4
print(krutaOrdem4(f4, 0.5, 0,1000,5))