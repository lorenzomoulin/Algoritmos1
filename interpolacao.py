from leitura import Leitura
import splines

l = Leitura.ler(Leitura)

nPontos, x, y, z, opcao = l
nPolinomios = nPontos - 1
#calcula todos os Δi e armazena
lista_dif_div = splines.dif_divididas(x, y, nPontos)

#armazena 6*(Δi - Δi-1) = vetor b
b = []
for i in range(1, nPolinomios):
    b += [6*(lista_dif_div[i] - lista_dif_div[i-1])]

h = splines.h
#gera matriz dos h's
H = [[2*(h(x, 0) + h(x, 1)), h(x, 1), 0]]

#da segunda até a penúltima linha
for i in range(1, nPolinomios-2):
    H += [[h(x, i), 2*(h(x, i) + h(x, i+1)), h(x, i+1)]]

#última linha
H += [[0, h(x, nPolinomios-2), 2*(h(x, nPolinomios-2) + h(x, nPolinomios-1))]]

#print("////----Matriz H:----////")
#for linha in H:
#    print(linha)
#print(H)


A, c = splines.triangulariza(H, b, nPolinomios-1)

print()

s2 = splines.retroativas(A, c, nPolinomios-1)

s2 = [0] + s2 + [0]

funcao_interpolada = splines.equacao(s2, x, lista_dif_div, y, nPolinomios)


splines.grafico(x, funcao_interpolada, nPontos, opcao)

s = splines.s(z, funcao_interpolada, x)
print("si(" + str(z) + ") = " + str(s))