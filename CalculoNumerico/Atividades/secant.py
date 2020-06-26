import math

k = 631

def f(x):
    # return -k * math.exp(x) - 3*x
    return x**4 - 16*x**3 + 500*x**2 - 8000*x + 32000


def iteratorFunction(x_1, x_2):
    return x_1 - f(x_1)  * (x_1 - x_2) / (f(x_1) - f(x_2))
    

precision = 10**(-5)
x_1 = 12
x_2 = 11.5
x_n = 0

while True:
    x_n = iteratorFunction(x_1, x_2)

    print(f'{x_2:9.5f}', f'{x_1:9.5f}', f'{x_n:9.5f}', f'{f(x_2):.2e}', f'{f(x_1):.2e}', f'{f(x_n):.2e}')
    # print(x_2, x_1, x_n, f(x_2), f(x_1), f'{f(x_n):.2e}')

    x_2 = x_1
    x_1 = x_n

    if abs(f(x_n)) < precision:
        break

#print(x_n, f(x_n)) 