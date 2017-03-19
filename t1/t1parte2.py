# Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.

def adiciona_sr(lista): return list(map(lambda string: 'Sr. ' + string, lista))

# Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.

def operacoes_num(num): return list(map(lambda num: 3*num*2+2/num+1, num))

# Crie uma função que receba uma lista de nomes e retorne outra lista com somente aqueles nomes que terminarem com a letra 'a'.

def verifica_A(lista): return list(filter(lambda elem: elem[-1]=='a', lista))

# Escreva uma função que, dada uma lista de idades de pessoas no ano atual, retorne uma lista somente com as idades de quem nasceu depois de 1970.
# Para testar a condição, sua função deverá subtrair a idade do ano atual. Exemplo de uso:

def BornAfter1970(lista): return list(filter(lambda ano: 2017-ano>1970, lista))

# O código abaixo é escrito em Python imperativo. Escreva um código equivalente usando programação funcional.
#   numbers = [1, 2, 3, 4]
#   new_numbers = []
#   for number in numbers:
#   new_numbers.append(number * 2)
#   print(new_numbers)

def mult(numbers): return list(map(lambda num: num*2, numbers))

