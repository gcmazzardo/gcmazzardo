# Defina uma função somaQuad(x,y) que calcule a soma dos quadrados de dois números x e y.

def somaQuad(x,y): return x*x+y*y

# Crie uma função hasEqHeads(l1,l2) que verifique se as listas l1 e l2 possuem o mesmo primeiro elemento.

def hasEqHeads(l1,l2): return l1[0]==l2[0]

# Escreva uma função que receba uma lista de nomes e retorne uma lista com a string "Sr. " adicionada ao início de cada nome.
# Defina uma função auxiliar para ajudar neste exercício.

def add_sr(elem): return 'Sr. ' + elem
def aux_sr(lista): return list(map(add_sr, lista))

# Crie uma função que receba uma string e retorne o número de espaços nela contidos.
# Defina uma função auxiliar para ajudar neste exercício.

def espaços(elem): return elem == ' '
def aux_espaços(lista): return len(list(filter(espaços, lista)))

# Escreva uma função que, dada uma lista de números, calcule 3n*2 + 2/n + 1 para cada número n da lista.
# Defina uma função auxiliar para ajudar neste exercício.

def operacoes(n): return 3*n*2+2/n+1
def numeros(lista): return list(map(operacoes, lista))

# Escreva uma função que, dada uma lista de números, retorne uma lista com apenas os que forem negativos.
# Defina uma função auxiliar para ajudar neste exercício.

def verifica_negativos(x): return x<0
def lista_nums(lista): return list(filter(verifica_negativos, lista))

# Escreva uma função que receba uma lista de números e retorne somente os que estiverem entre 1 e 100, inclusive.
# Defina uma função auxiliar para ajudar neste exercício.

def entre1e100(x): return 0<x<101
def nums_verif_1a100(lista): return list(filter(entre1e100, lista))

# Escreva uma função que receba uma lista de números e retorne somente aqueles que forem pares.
# Defina uma função auxiliar para ajudar neste exercício.

def retorna_pares(x): return x%2==0
def verif_pares(lista): return list(filter(retorna_pares, lista))

# Crie uma função charFound(c,s) que verifique se o caracter c está contido na string. O resultado deve ser True ou False.
# Você não deve usar o operador in. Defina uma função auxiliar para ajudar neste exercício.

def charFound(c,s):
	def char(x): return x==c
	return len(list(filter(char, s)))>0

# Escreva uma função que receba uma lista de strings e retorne uma nova lista com adição de marcações HTML (p.ex.: <B> e </B>) antes e depois de cada string.

def marc_html(elem): return '<B>' + elem + '</B>'
def add_marc(lista): return list(map(marc_html, lista))
