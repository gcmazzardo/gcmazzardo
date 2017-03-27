#!/usr/bin/env python3
import itertools
import random

'''
   Programacao funcional para gerar SVG:
   - gera uma lista de coordenadas de retangulos
   - define uma lista de estilos (cores), em qualquer quantidade
   - aplica os estilos aos retangulos, gerando uma lista com todos os dados para o SVG
   - coloca os dados no formato SVG, concatenando strings
'''

def svgRect(rs):
   (((x,y),w,h),style) = rs
   return "<rect x='%.3f' y='%.3f' width='%.2f' height='%.2f' style='%s'/>\n" % (x,y,w,h,style)

def svgImage(w, h, rs):
   return "<svg width='%.2f' height='%.2f' xmlns='http://www.w3.org/2000/svg'>\n" % (w,h) + \
          ''.join(map(svgRect, rs)) + "</svg>"

def applyStyles(rects, styles):
   return list(zip(rects, itertools.cycle(styles)))

# TODO: modifique essa funcao para gerar mais retangulos
def genRects(n, w, h):
   return [((w*x,0),w,h) for x in range(0,n)]

def writeFile(fname, contents):
   f = open(fname, 'w')
   f.write(contents)
   f.close()

#FUNÇÃO DAS CORES RANDOM ABAIXO
def sorteia_cor(n):
   return ['fill:rgb('+str(140)+','+str(random.randrange(0,255))+','+str(100)+')' for x in range(1, n+1)]

#OBS: Deixei a variável "styles" abaixo recebendo a versão dos retângulos com cores randomicas, pedidas no item (2) da parte 2.
#Mas, como no item anterior (item 1) há a menção "A figura produzida deverá ser igual a colors.svg", não sabia em qual deixar.
#Caso queira conferir que o item 1 está certo, basta substituir a linha pela original, que é:
# styles = ["fill:rgb(140,0,0)","fill:rgb(0,140,0)"]
# Obrigado. Abraço!

def main():
   maxWidth = 1000
   maxHeight = 100
   rects = genRects(10,50,50)
   styles = sorteia_cor(3)
   rectstyles = applyStyles(rects, styles)
   writeFile("mycolors.svg", svgImage(maxWidth, maxHeight, rectstyles))
   

if __name__ == '__main__':
   main()
