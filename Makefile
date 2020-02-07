
default: AcutestExample

AcutestExample.o: AcutestExample.c
	gcc -I./../libs/acutest/include -c AcutestExample.c -o AcutestExample.o

AcutestExample: AcutestExample.o
	gcc AcutestExample.o -o AcutestExample

clean:
	-rm -f AcutestExample.o
	-rm -f AcutestExample
