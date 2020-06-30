import math

k = 631

def f(x):
    # return math.cos(x) - x/(k + x**2)
    return x - k * math.exp(-x**2)


def iteratorFunction(x):
    # return x - f(x)/(-math.sin(x) - (k - x**2) / (k + x**2)**2)
    return x - f(x) / (1 + 2 * k * math.exp(-x**2) * x )

precision = 10**(-8)
x_n = 2.3
print("\(x_{n-1}\), \(x_n\), \(f(x_n)\), \(|x_{n} - x_{n-1}|\)")
while True:
    x_a = x_n
    x_n = iteratorFunction(x_n)
    print(f'{x_a:9.10f}' + ",", f'{x_n:9.10f}' + ",", f'{f(x_n):.2e}' + ",", f'{x_n - x_a : .2e}')
   
    if abs(f(x_n)) < precision and abs(x_n - x_a) < precision:
        break

#print(f'{x_n:9.10f}', f'{f(x_n):.2e}')