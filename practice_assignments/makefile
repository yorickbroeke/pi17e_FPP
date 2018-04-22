DIRS=bin build

$(shell mkdir -p $(DIRS))

game : main.o task1_conversion.o task2_lottery.o task3_adventure.o
	cc -o ./bin/game ./build/main.o ./build/task1_conversion.o ./build/task2_lottery.o ./build/task3_adventure.o

main.o : main.c
	cc -c main.c -o ./build/main.o

task1_conversion.o : task1_conversion.c
	cc -c task1_conversion.c -o ./build/task1_conversion.o

task2_lottery.o : task2_lottery.c
	cc -c task2_lottery.c -o ./build/task2_lottery.o

task3_adventure.o : task3_adventure.c
	cc -c task3_adventure.c -o ./build/task3_adventure.o

clean :
	rm ./bin/game ./build/main.o ./build/task1_conversion.o ./build/task2_lottery.o ./build/task3_adventure.o
