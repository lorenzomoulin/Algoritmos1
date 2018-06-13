import matplotlib.pyplot as plt

def dif_divididas(x, y, n):
    matrix = []
    for i in range(n-1):
        matrix += [(y[i+1] - y[i])/(x[i+1] - x[i])]
    return matrix

def h(x, i):
    return x[i+1] - x[i]

def triangulariza(A, b, n):
    for i in range(n-1):
        m = A[i + 1][i % 3] / A[i][i % 3]
        A[i + 1][i % 3] -= m * A[i][i % 3]
        A[i + 1][(i + 1) % 3] -= m * A[i][(i + 1) % 3]
        b[i + 1] -= m * b[i]
    return A, b

def retroativas(A, b, n):
    x = [0 for i in range(n)]
    x[n-1] = b[n-1]/A[n-1][(n-1) % 3]
    for i in range(n-2, -1, -1):
        x[i] = (b[i] - A[i][(i + 1) % 3] * x[i + 1]) / A[i][i % 3]
    return x

#gera todos os coeficientes de cada spline
def equacao(s2, x, dif_div, y, n):
    splines = []
    for i in range(n):
        splines += [[(s2[i+1] - s2[i])/(6*h(x, i)), s2[i]/2, dif_div[i]-(s2[i+1] + 2*s2[i])*h(x, i)/6, y[i]]]
    return splines

def grafico(x, splines, n, opcao):
    if opcao == '1' or opcao == '21':
        passo = (x[-1] - x[0])/50
    else:
        passo = (x[-1] - x[0]) / 100
    xi = x[0]
    y = []
    hs = [xi]

    g = open("grafico.txt", 'w')
    g.write("x         y\n\n")
    for i in range(n-1):
        while xi <= x[i+1]:
            si = splines[i][0]*(xi - x[i])**3 + splines[i][1]*(xi - x[i])**2 + splines[i][2]*(xi - x[i]) + splines[i][3]
            y += [si]
            g.write("%.3f   %.3f\n" % (xi, si))
            xi += passo
            hs += [xi]
    plt.plot(hs[0:-1], y, 'o')
    plt.show()
    g.close()
def s(z, splines, x):
    intervalo = [e for e in x if e < z] + [z] + [e for e in x if e >= z]
    posicao = intervalo.index(z) - 1
    return splines[posicao][0]*(z - x[posicao])**3 + splines[posicao][1]*(z - x[posicao])**2 + splines[posicao][2]*(z - x[posicao]) + splines[posicao][3]