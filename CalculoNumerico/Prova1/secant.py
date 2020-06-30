import math

k = 631


def c1(x):
    return 0.631 + 8.2 * 10**(-5) * x + 6.3 * 10**(-7) * x ** 2 + 4 * 4.631 * 10 ** (-10) * x**3

def c2(x):
    return -0.22 - 2 * 6.631 * 10**(-5) * (1500 - x) - 3 * 8.631 * 10 ** (-7) * (1500-x)**2

def f(x):
    # return math.cos(x) - x/(k + x ** 2)
    # return x - k * math.exp(-x**2)
    return c1(x) + c2(x)

def iteratorFunction(x_1, x_2):
    return (x_2 * f(x_1) - x_1 * f(x_2)) / (f(x_1) - f(x_2))
    

precision = 10**(-4)
x_1 = 750
x_2 = 740
x_n = 0

print("\(x_{n-2}\), \(x_{n-1}\), \(x_n\), \(f(x_{n-2})\), \(f(x_{n-1})\), \(f(x_n)\), \(|x_{n-1} - x_{n-2}|\)")

while True:
    x_n = iteratorFunction(x_1, x_2)

    print(f'{x_2:9.10f}' + ",", f'{x_1:9.10f}' + ",", f'{x_n:9.10f}' + ",", f'{f(x_2):.2e}' + ",", f'{f(x_1):.2e}' + ",", f'{f(x_n):.2e}' + ",", f'{abs(x_2 - x_1):.2e}')
    # print(x_2, x_1, x_n, f(x_2), f(x_1), f'{f(x_n):.2e}')


    # if abs(f(x_n)) < precision and abs(x_1 - x_2) < precision:
    if abs(f(x_n)) < precision:
        break

    x_2 = x_1
    x_1 = x_n

# print(x_n, f(x_n)) 