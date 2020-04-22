cc = g++
target = main
objects = main.o LinkedList.h Stack.h

$(target) : $(objects)
	$(cc) -o $(target) $(objects)

$(target).o: main.cpp
	$(cc) -c main.cpp

.PHONY : clean
clean:
	rm $(target) $(objects)

