CC=gcc
src = ./src
DSPath=./DS/src
stackPath=$(DSPath)/stack
testPath=$(src)/test
regexPath=$(src)/regex

test: $(stackPath)/stack.o $(testPath)/testStack.o $(testPath)/mainTest.o $(src)/regex.o
	$(CC) $(stackPath)/stack.o $(testPath)/testStack.o $(testPath)/mainTest.o $(src)/regex.o -o $(testPath)/runTest

stack: $(stackPath)/stack.c
	$(CC) -c $(stackPath)/stack.c

regex: $(src)/regex.c
	$(CC) -c $(src)/regex.c

testStack: $(testPath)/testStack.c
	$(CC) -c $(testPath)/testStack.c

mainTest: $(testPath)/mainTest.c
	$(CC) -c $(testPath)/mainTest.c



clean:
	rm $(stackPath)/stack.o $(testPath)/testStack.o $(testPath)/mainTest.o