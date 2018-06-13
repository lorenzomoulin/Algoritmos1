class Leitura(object):

    def __init__(self):
        pass

    def ler(self):
        mensagem = "Digite uma opção:\n1 - Ler dados via teclado\n2 - Ler dados via arquivo\n3 - Sair\nEscolha:"
        opcao = input(mensagem)
        if opcao == "1":
            n = int(input())
            x = [float(i) for i in input().split()]
            y = [float(i) for i in input().split()]
            z = float(input())
            return n, x, y, z, '1'
        elif opcao == "2":
            mensagem2 = "Digite uma opção:\n1 - Ler arquivo dados1.txt\n2 - Ler arquivo dados2.txt\n3 - Sair\nEscolha:"
            nova_opcao = input(mensagem2)
            if nova_opcao == "1":
                try:
                    with open("dados1.txt") as f:
                        n = int(f.readline())
                        x = [float(i) for i in f.readline().split()]
                        y = [float(i) for i in f.readline().split()]
                        z = float(f.readline())

                        return n, x, y, z, '21'
                except FileNotFoundError:
                    print("Arquivo nao encontrado!")
                    exit()
            elif nova_opcao == "2":
                try:
                    with open("dados2.txt") as f:
                        n = int(f.readline())
                        x = [float(i) for i in f.readline().split()]
                        y = [float(i) for i in f.readline().split()]
                        z = float(f.readline())
                        return n, x, y, z, '22'
                except FileNotFoundError:
                    print("Arquivo nao encontrado!")
                    exit()
            elif nova_opcao == "3":
                exit()
            else:
                print("Opção inválida!")
                exit()
        elif opcao == "3":
            exit()
        else:
            print("Opção inválida!")
            exit()