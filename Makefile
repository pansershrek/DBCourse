all: hello
hello:
	gcc -std=c11 mmain.c test_mid_hash.c my_list.c test_my_list.c table.c -o prog.o -lm
clean:
	rm -rf *.o hello

