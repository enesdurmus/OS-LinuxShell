all:
	gcc myshell.c  -o myshell -lreadline
	gcc repeat.c -o repeat
	gcc operation.c -o operation
	gcc addition.c -o addition
	gcc subtraction.c -o subtraction
