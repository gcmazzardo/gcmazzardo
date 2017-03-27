#Defina uma função addSuffix(suf,nomes) que retorne a lista de nomes com o sufixo suf adicionado.

def addSuffix(suf, nomes): return [x+suf for x in nomes]

#Escreva uma função countShorts(words), que receba uma lista de palavras e retorne a quantidade de palavras dessa lista que possuem menos de 5 caracteres.

def countShorts(words): return len(list(filter(lambda i: i<5, [len(x) for x in words])))

#Defina uma função stripVowels(s) que receba uma string e retire suas vogais, conforme os exemplos abaixo:

def stripVowels(s): return ''.join([x for x in s.lower() if x not in ['a', 'e', 'i', 'o', 'u']])

#Defina uma função hideChars(s) que receba uma string, possivelmente contendo espaços, e que retorne outra string substituindo os demais caracteres por '-', mas mantendo os espaços. Exemplos:

def hideChars(s): return ''.join(['-' if x!=' ' else ' ' for x in s])

#Defina uma função que receba um número n e retorne uma tabela de números de 1 a n e seus quadrados, conforme os exemplos abaixo (você vai usar tuplas em Python):

def genTable(num): return [(x, x**2) for x in range(1,num+1)]

#Defina uma função que receba uma lista de palavras e retorne uma string contendo o primeiro e o último caracter de cada palavra da lista.

def genCode(words): return ''.join(list([x[0]+x[-1] for x in words]))

#Defina uma função myZip(l1,l2) que reproduza o comportamento da função zip do Python:

def myZip(l1, l2): return [(l1[x], l2[x]) for x in range(0, len(l1))]

#Escreva uma função enumerate(words) que numere cada palavra da lista recebida:

def enumerate(words): return [(words.index(x),x) for x in words]

#Escreva uma função isBin(s) que verifique se a string recebida representa um número binário.

def isBin(num): return len(num) == len(''.join([x for x in num if x in '01']))

#Escreva uma função bin2dec(digits), que receba uma lista de dígitos representando um número binário e retorne seu equivalente em decimal.

def bin2dec(lista): return int(''.join(str(x) for x in lista), 2)

