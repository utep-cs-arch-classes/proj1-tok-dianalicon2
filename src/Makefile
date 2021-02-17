tokenizer.o: tokenizer.c tokenizer.h
	gcc -c tokenizer.c
GUI.o: GUI.c tokenizer.h
	gcc -c GUI.c
main: tokenizer.o GUI.o
	gcc -o test tokenizer.o GUI.o
clean:
	rm -f test *o *~ *#
