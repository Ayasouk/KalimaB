#include <stdio.h>
#include <stdlib.h>

# sequence d'echappement commence par : \033
# marque de debut de definition de couleur par [
# suivi de couleur du text suivi de ; ensuite couleur de fond avec un m
#\u @ -> user @
Pour ajouter de la couleur dans les programmes : utiliser slang ou ncurses
#	TEXTE 	FOND
Noir	30	40
Rouge	31	41
Vert	32	42
Jaune	33	43
Bleu	34	44
Magenta	35	45
Cyan	36	46
Blanc	37	47

# \033[2J equivaut system(clear) sans utiliser unistd.h
# \033[1K efface une ligne

# voir ansi escape code


