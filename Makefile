
default: test_example

base_functions.o: base_functions.c base_functions.h
	gcc -c base_functions.c -o base_functions.o

base_functions_test.o: base_functions_test.c
	gcc -I./../libs/acutest/include -c base_functions_test.c -o base_functions_test.o

base_functions_test: base_functions_test.o base_functions.o
	gcc base_functions_test.o base_functions.o -o base_functions_test

test_example.o: test_example.c
	gcc -I./../libs/acutest/include -c test_example.c -o test_example.o

test_example: test_example.o
	gcc test_example.o -o test_example

clean:
	-rm -f base_functions.o
	-rm -f base_functions_test.o
	-rm -f base_functions_test
	-rm -f test_example.o
	-rm -f test_example
