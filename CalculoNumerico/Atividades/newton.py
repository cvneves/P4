import math

k = 631

def f(x):
    #return -k * math.exp(x) - 3*x
    return x**4 - 16*x**3 + 500*x**2 - 8000*x + 32000

def iteratorFunction(x):
    #return k * math.exp(x) * (x - 1) / (k * math.exp(x) + 3)
    # return x - (x**4 - 16*x**3 + 500*x**2 - 8000*x + 32000) / (4*x**3 - 48*x**2 + 1000*x - 8000)
    return (-32000 + 500*x**2 - 32*x**3 + 3*x**4) / (4 * x**3 - 48 * x**2 + 1000 * x - 8000)

precision = 10**(-5)
x_n = 11.5
while True:
    print(f'{x_n:9.10f}', f'{f(x_n):.2e}')
    x_n = iteratorFunction(x_n)
    if abs(f(x_n)) < precision:
        break

print(f'{x_n:9.10f}', f'{f(x_n):.2e}')