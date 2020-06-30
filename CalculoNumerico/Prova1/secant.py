import math

k = 631

def f(x):
    # return math.cos(x) - x/(k + x ** 2)
    return x - k * math.exp(-x**2)

def iteratorFunction(x_1, x_2):
    return (x_2 * f(x_1) - x_1 * f(x_2)) / (f(x_1) - f(x_2))
    

precision = 10**(-8)
x_1 = 2.4
x_2 = 2.3
x_n = 0

while True:
    x_n = iteratorFunction(x_1, x_2)

    print(f'{x_2:9.10f}', f'{x_1:9.10f}', f'{x_n:9.10f}', f'{f(x_2):.2e}', f'{f(x_1):.2e}', f'{f(x_n):.2e}')
    # print(x_2, x_1, x_n, f(x_2), f(x_1), f'{f(x_n):.2e}')

    x_2 = x_1
    x_1 = x_n

    if abs(f(x_n)) < precision:
        break

# print(x_n, f(x_n)) 