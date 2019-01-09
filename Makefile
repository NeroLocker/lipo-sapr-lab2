# Compiler
CC=g++
# Flags to compile an object file from source file
CFLAGS=-c
# Flags to compile an executed file from object file
OFLAG=-o
# CppUnit library flags
CPPUNIT_FLAGS=-I$CPPUNIT_HOME/include -L$CPPUNIT_HOME/lib -lcppunit
# PCRE library flag
PCRE_FLAG=-lpcrecpp
# Object files folder
OBJ=obj
# Test files folder
TEST=test
# Source files folder
SRC=src
# Output executed file name
OFILE=main
# Test file
TESTFILE=test_find_macros

all: $(OFILE)

$(OFILE): $(OBJ)/main.o $(OBJ)/MacrosFinder.o $(OBJ)/MacrosFinderTest.o
	$(CC) $(OBJ)/main.o $(OBJ)/MacrosFinder.o $(OBJ)/MacrosFinderTest.o $(PCRE_FLAG) $(CPPUNIT_FLAGS) $(CPPFLAGS) $(OFLAG) $(OFILE)
	./$(OFILE) -t < $(TEST)/test_find_macros
	
$(OBJ)/main.o: $(SRC)/main.cpp
	$(CC) $(CFLAGS) $(SRC)/main.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/main.o
	
$(OBJ)/MacrosFinder.o: $(SRC)/MacrosFinder.cpp
	$(CC) $(CFLAGS) $(SRC)/MacrosFinder.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/MacrosFinder.o
	
$(OBJ)/MacrosFinderTest.o: $(SRC)/MacrosFinderTest.cpp
	$(CC) $(CFLAGS) $(SRC)/MacrosFinderTest.cpp $(CPPFLAGS) $(OFLAG) $(OBJ)/MacrosFinderTest.o
	
# Tests runs are already included inside output file!
test: $(OFILE)

compare: $(OFILE)
	./main.sh < $(TEST)/$(TESTFILE) > scriptout
	./$(OFILE) < $(TEST)/$(TESTFILE) | sort > cppout
	diff cppout scriptout

clean:
	rm -rf $(OFILE) $(OBJ)/* scriptout cppout