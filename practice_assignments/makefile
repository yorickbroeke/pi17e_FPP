game : main.o task1_conversion.o task2_lottery.o task3_adventure.o
	cc -o ./bin/game ./build/main.o ./build/task1_conversion.o ./build/task2_lottery.o ./build/task3_adventure.o

main.o : main.c
	cc -c main.c

task1_conversion.o : task1_conversion.c
	cc -c task1_conversion.c

task2_lottery.o : task2_lottery.c
	cc -c task2_lottery.c

task3_adventure.o : task3_adventure.c
	cc -c task3_adventure.c

clean : rm game main.o task1_conversion.o task2_lottery.o task3_adventure.o
