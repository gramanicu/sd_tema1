# Copyright 2019 Grama Nicolae

.PHONY: gitignore check purge clean memory update beauty pack run
.SILENT: purge update beauty pack clean memory gitignore

# Compilation variables
CC = g++
CFLAGS = -Wall -Wextra -pedantic -O3 -g
EXE = tema1
SRC = $(wildcard *.cpp) $(wildcard */*.cpp)
OBJ = $(SRC:.cpp=.o)

# Variables related to the checker
# NOTE - the following line has more than 80 chars, and it's no problem
# according to google styleguide, because it contains and URL
CHECKER = https://ocw.cs.pub.ro/courses/_media/sd-ca/teme/checker-tema1-2019-v3.zip
CARCHIVE = checker-tema1-2019-v3.zip

# Variables related to the archive (with the homework)
ANAME = 312CA_GramaNicolae_Tema1.zip
ACONTENTS = README Makefile sources/ headers/
AFLAGS = -FSr 

# Compiles the program
build: $(OBJ)
	$(info Compiling code...)
	@$(CC) -o $(EXE) $^ $(LFLAGS) $(CFLAGS) ||:
	$(info Compilation successfull)
	-@rm -f *.o ||:
	@$(MAKE) -s gitignore ||:

# Executes the binary
run: build
	./$(EXE)

# Archives the homework
pack:
	if [ ! -f README ]; then cp Readme.md README; fi
	zip $(AFLAGS) $(ANAME) $(ACONTENTS)
	rm README

# Deletes the binary and object files
clean:
	rm -f $(EXE) $(OBJ)
	echo "Deleted the binary and object files"

# Automatic coding style, using google standard.
beauty:
	clang-format -i -style=file */*.cpp
	clang-format -i -style=google */*.h

# Downloads the checker archive and "installs" it
# It will ask for the password, because it needs to give execution
# rights to the checker.
update:
	wget $(CHECKER)
	unzip -o $(CARCHIVE)
	sudo chmod 755 check.sh
	sudo chmod 755 cpplint.py
	dos2unix cpplint.py
	rm -f $(CARCHIVE)*

# Checks the memory for leaks
MFLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes
memory:build
	valgrind $(MFLAGS) ./$(EXE)

# Verifies the homework using the checker
check:update build
	if [ ! -f README ]; then cp Readme.md README; fi
	./check.sh
	rm README

# Removes all files that won't appear in the git repository
purge:
	rm -f $(EXE) $(OBJ)
	rm -rfd ./ref
	rm -rfd ./input
	rm -f cpplint.py
	rm -f checkstyle.txt
	rm -f check.sh
	rm -f README
	rm -f *.out *.in
	rm -f $(ANAME)
	rm -f $(CARCHIVE)*
	rm -f time.err
	echo "All files were removed"

# Adds and updates gitignore rules
gitignore:
	@echo "checkstyle.txt" > .gitignore ||:
	@echo "races.in" >> .gitignore ||:
	@echo "check.sh" >> .gitignore ||:
	@echo "input*" >> .gitignore ||:
	@echo "ref*" >> .gitignore ||:
	@echo "cpplint.py" >> .gitignore ||:
	@echo "README" >> .gitignore ||:
	@echo "$(ANAME)" >> .gitignore ||:
	@echo "$(EXE)" >> .gitignore ||:
	@echo "sources/*.o" >> .gitignore ||:
	@echo ".vscode*" >> .gitignore ||:	
	@echo "time.err*" >> .gitignore ||:
	@echo "races.out*" >> .gitignore ||:
	@find . -executable -type f -not -path "*/.git/*" | cut -c 3- >>.gitignore ||:
	echo "Updated .gitignore"
