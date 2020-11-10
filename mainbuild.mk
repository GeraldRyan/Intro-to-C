SRC=$(wildcard *.c)
# Wildcard function is wildcard pattern. This string used anywhere in makefile is replaced by space separated list of names of existing files that match. This gives a list of all C source files in directory. Therefore SRC is all source files in directory. So it is dependent on the directory it's called in, the cwd when command is run. i.e. environmental variable. 
EXE=$(subst .c,,$(SRC))
# Performs a text substitution from .c to Null this text SRC. Each occurence of .c is replaced by the second arg. In other words, in this case, it strips the c value from it. In other words the EXE files are just the source files stripped of their extension. So it should create one new no extension binary for each c file....... but for each one in each directory, not each one included? 


$(EXE): $(SRC)
	gcc -Wall -Wextra -std=c99 -g -o $@ $^
# -g is debugging option to emit extra info for use by debugger. 
# -o place the primary output in file following this argument, in this case $@ or $^
# $@ is name of file to be made. (meaning what? ) 
# $^ Unidentified
# 

test: tests
 
.PHONY: clean test tests

# Sean's testing stuff below:

CFLAGS=-g -O2 -Wall -Wextra -I. -DTESTING -DNDEBUG $(OPTFLAGS)
LIBS=-ldl $(OPTLIBS)
PREFIX?=/usr/local

SOURCES=$(wildcard *.c)
OBJECTS=$(patsubst %.c,%.o,$(SOURCES))

TEST_SRC=$(wildcard tests/*_tests.c)
TESTS=$(patsubst %.c,%,$(TEST_SRC))

TARGET=build/liblcthw.a
SO_TARGET=$(patsubst %.a,%.so,$(TARGET))

# The Target Build
tests: clean $(TARGET) $(SO_TARGET) tests2

dev: CFLAGS=-g -std=c99 -Wall -Isrc -Wall -Wextra %(OPTFLAGS)
dev: all

$(TARGET): CFLAGS += -fPIC
$(TARGET): build $(OBJECTS)
	ar rcs $@ $(OBJECTS)
	ranlib $@
$(SO_TARGET): $(TARGET) $(OBJECTS)
	$(CC) -shared -o $@ $(OBJECTS)

build:
	@mkdir -p build
	@mkdir -p bin

# The Unit Tests
.PHONY: tests
#tests2: CFLAGS += $(TARGET)
tests2: $(TESTS)
	sh ./tests/runtests.sh

$(TESTS): $(TEST_SRC)
	$(CC) $(CFLAGS) $^ $(TARGET) -o $@

# The Cleaner
clean:
	rm -rf build $(OBJECTS) $(TESTS)
	rm -f tests/tests.log
	find . -name "*.gc" -exec rm -f {} \;
	rm -rf `find . -name "*.dSYM" -print`
	rm -f $(EXE)
