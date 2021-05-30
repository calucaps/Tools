all: pwg emot t

pwg: pwgd/pwg.c
	gcc pwgd/pwg.c -o pwg
emot: emoji/emot.c emoji/emo.c emoji/emo.h
	gcc -g emoji/emot.c emoji/emo.c -o emot
t: emoji/t.c emoji/emo.c emoji/emo.h
	gcc -g emoji/emo.c emoji/t.c -o t

