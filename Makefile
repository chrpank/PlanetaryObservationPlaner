
default: test_example

test_example.o: test_example.c
	gcc -I./../libs/acutest/include -c test_example.c -o test_example.o

test_example: test_example.o
	gcc test_example.o -o test_example

clean:
	-rm -f test_example.o
	-rm -f test_example
