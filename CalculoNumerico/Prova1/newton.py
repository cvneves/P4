import math

k = 631

def c1(x):
    0.631 + 8.2 * 10**(-5) * x + 6.3 * 10**(-7) * x ** 2 + 4 * 4.631 * 10 ** (-10) * x**3

def c2(x):
    -0.22 - 2 * 6.631 * 10**(-5) * (1500 - x) - 3 * 8.631 * 10 ** (-7) * (1500-x)**2

def f(x):
    return math.cos(x) - x/(k + x**2)
    # return x - k * math.exp(-x**2)


def iteratorFunction(x):
    return x - f(x)/(-math.sin(x) - (k - x**2) / (k + x**2)**2)
    # return x - f(x) / (1 + 2 * k * math.exp(-x**2) * x )

precision = 10**(-6)
x_n = 1.6
print("\(x_{n-1}\), \(x_n\), \(f(x_n)\), \(|x_{n} - x_{n-1}|\)")
while True:
    x_a = x_n
    x_n = iteratorFunction(x_n)
    print(f'{x_a:9.10f}' + ",", f'{x_n:9.10f}' + ",", f'{f(x_n):.2e}' + ",", f'{x_n - x_a : .2e}')
   
    if abs(f(x_n)) < precision and abs(x_n - x_a) < precision:
        break

#print(f'{x_n:9.10f}', f'{f(x_n):.2e}')