import math

k = 631

def f(x):
    #return 631 * math.cos(x) - math.exp(2*x)
    # return 2*math.sin(x) - 3*(x**2)
    return - k * math.exp(x) - 3*x

def mediaAritmetica(x1, x2):
    return (x1+x2)/2

def mediaPonderada(x1, x2):
    return (x1*f(x2) - x2 * f(x1))/(f(x2) - f(x1))

a = -4.1
b = -3.9
precisao = 10**(-4)

min_iter = (math.log10(b - a) - math.log10(precisao)) / (math.log10(2))
min_iter = math.ceil(min_iter)

print("Min iter: ", min_iter)


x1,x2 = a, b
f1 = f(x1); f2 = f(x2)

# print("[a,b] = ["+ str(a)+", ", str(b)+ "]")

#0 = bisseccao
#1 = posicaofalsa
modo = 0

n = 15

for i in range(0,n):
    if modo == 0:
        x3 = mediaAritmetica(x1,x2)
    else:
        x3 = mediaPonderada(x1,x2)

  
    f3 = f(x3)

    print(f'{x1:9.5f}', f'{x2:9.5f}', f'{x3:9.5f}', f'{f(x1):.2e}', f'{f(x2):.2e}', f'{f(x3):.2e}')


    # print("Iteração ", str(i + 1) + ": x1 =", str(x1)+ ", x2 =",str(x2) + ", x3 =", x3)
    # print("f(x1) =", str(f(x1))+ ", f(x2) =",str(f(x2)) + ", f(x3) =", f(x3))


    if(f3 == 0):
        x1 = x2 = x3
        break

    if(f1 * f3 > 0):
        a = x3
        b = x2
        x1 = x3
        f1 = f(x1)
    else:
        b = x3
        a = x1
        x2 = x3
        f2 = f(x2)

e_menor = ">="
if abs(f(x3)) < precisao:
    e_menor = "<"

print(x3)
print("|f(x3)| =", abs(f(x3)), e_menor, precisao)

#print(x1,x3,x2, abs(a - b))
