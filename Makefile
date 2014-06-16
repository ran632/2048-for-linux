
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
BIN_DIR := bin
OBJC=$(SOURCES:%.c=${BUILD_DIR}/%.o)

# executable name
EXECUTABLE=2048

.PHONY: all

all:	$(EXECUTABLE)

$(EXECUTABLE): $(OBJC)
	@echo "Building target" $@
	@mkdir -p $(BIN_DIR)
	@$(CC) $(LDFLAGS) -o $(BIN_DIR)/$@ $(OBJC) $(LIBS)
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

bclean: clean
	@echo "Ceaning all"
	@rm -rf *.dat ${BIN_DIR}
	@echo "Done."

rebuild: bclean all


install: all
	@echo "Installing 2048: "	
	@echo "coping exec to /usr/bin/"
	@sudo cp ./bin/2048 /usr/bin/
	@mkdir -p /home/$(USER)/.2048/
	@mkdir -p /home/$(USER)/.icons/
	@cp ./res/2048.png /home/$(USER)/.icons/
	@cp 2048.desktop.desktop /home/$(USER)/.local/share/applications/
	@echo
	@echo
	@echo
	@echo "Done. enjoy your new game - run 2048 from terminal."

uninstall: bclean
	@echo "Uninstalling 2048: "	
	@echo "Deleting ecec from /usr/bin/"
	@sudo rm -f  /usr/bin/2048
	@rm -rf /home/$(USER)/.2048/
	@rm -rf /home/$(USER)/.icons/2048.png
	@rm -rf /home/$(USER)/.local/share/applications/2048.desktop.desktop
	@echo
	@echo
	@echo
	@echo "Done."



