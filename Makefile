all: twentyfortyeight

clean:
	rm -f *.o

twentyfortyeight: main.c menu.o checks.o generate_next_grid.o generate_first_grid.o
	gcc main.c menu.o checks.o generate_next_grid.o generate_first_grid.o -o twentyfortyeight

menu.o: menu.c
	gcc -c menu.c -Wall

checks.o: checks.c
	gcc -c checks.c -Wall

generate_next_grid.o: generate_next_grid.c
	gcc -c generate_next_grid.c -Wall

generate_first_grid.o: generate_first_grid.c
	gcc -c generate_first_grid.c -Wall