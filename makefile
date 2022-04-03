compile: main.o BinaryTree.o
	g++ -Wall -pedantic-errors -o main main.o BinaryTree.o

main.o: main.cpp BinaryTree.h
	g++ -Wall -pedantic-errors -c -g main.cpp

BinaryTree.o: BinaryTree.cpp BinaryTree.h
	g++ -Wall -pedantic-errors -c -g BinaryTree.cpp

clean:
	rm -f main
	rm -f *.o
