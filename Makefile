
#HOW-TO:
#	make			to compile
#	make clean		cleaning objects directory
#	make bclean		cleaning all files
#	make rebuild	clean and remake

# compiler
CC = gcc

# compile arguments
CFLAGS = -Wall -g 

# linker flags
LDFLAGS = 

# libraries
LIBS = -lncurses

#our source files
SOURCES = $(wildcard *.c)

# a macro to define the objects from sources
BUILD_DIR := build
OBJC=$(SOURCES:%.cpp=${BUILD_DIR}/%.o)

# executable name
EXECUTABLE=2048

.PHONY: all

all:	$(EXECUTABLE)

$(EXECUTABLE): $(OBJC)
	@echo "Building target" $@
	@$(CC) $(LDFLAGS) -o $@ $(OBJC) $(LIBS)
	@echo "Done."

# a rule for generating object files given their c files
#.cpp.o: /$(OBJCDIR)
${BUILD_DIR}/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Ceaning up *.o Files"
	@rm -rf ${BUILD_DIR}
	@echo "Done."

bclean:
	@echo "Ceaning all"
	@rm -rf $(EXECUTABLE) ${BUILD_DIR}
	@echo "Done."

rebuild: bclean all


