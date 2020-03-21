
default: test_example

configuration_manager.o: configuration_manager.c configuration_manager.h
	gcc -c configuration_manager.c -o configuration_manager.o

date_manager.o: date_manager.c date_manager.h
	gcc -c date_manager.c -o date_manager.o
	
date_manager_test.o: date_manager_test.c
	gcc -I./../libs/acutest/include -c date_manager_test.c -o date_manager_test.o

date_manager_test: date_manager_test.o date_manager.o base_functions.o
	gcc date_manager_test.o date_manager.o base_functions.o -o date_manager_test

scenario_functions.o: scenario_functions.c scenario_functions.h
	gcc -c scenario_functions.c -o scenario_functions.o

scenario_functions_test.o: scenario_functions_test.c
	gcc -I./../libs/acutest/include -c scenario_functions_test.c -o scenario_functions_test.o

scenario_functions_test: scenario_functions_test.o base_functions.o scenario_functions.o
	gcc scenario_functions_test.o base_functions.o scenario_functions.o -o scenario_functions_test

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
	-rm -f date_manager.o
	-rm -f date_manager_test.o
	-rm -f date_manager_test
	-rm -f scenario_functions.o
	-rm -f scenario_functions_test.o
	-rm -f scenario_functions_test
	-rm -f base_functions.o
	-rm -f base_functions_test.o
	-rm -f base_functions_test
	-rm -f test_example.o
	-rm -f test_example
