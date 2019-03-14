# Copyright 2019 Grama Nicolae

.PHONY: gitignore check purge clean memory update beauty pack run
.SILENT: purge update beauty pack clean memory gitignore

# Informatii program
CC = g++
CFLAGS = -Wall -Wextra -pedantic -O3
#FLAGS = -lm
EXE = tema1
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

# Informatii arhiva cu checkerul
CHECKER = https://ocw.cs.pub.ro/courses/_media/sd-ca/teme/checker_tema1_2019.zip
CARCHIVE = checker_tema1_2019.zip

# Informatii arhiva cu tema
ANAME = 312CA_GramaNicolae_Tema1.zip
ACONTENTS = README Makefile *.cpp *.h
AFLAGS = -FSr 

# Compilarea programului
build: $(OBJ)
	$(info Compiling code...)
	@$(CC) -o $(EXE) $^ $(LFLAGS) $(CFLAGS) ||:
	$(info Compilation successfull)
	-@rm -f *.o ||:
	@$(MAKE) -s gitignore ||:

# Ruleaza programul
run: build
		./$(EXE)

# Arhiveaza tema
pack: build
	cp Readme.md README
	zip $(AFLAGS) $(ANAME) $(ACONTENTS)
	rm README

# Sterge executabilul si fisierele obiect
clean:
	rm -f $(EXE) $(OBJ)
	echo "Deleted the binary and object files"

# Face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty:
	clang-format -i -style=file *.cpp *.h

# Descarca arhiva cu checkerul si o pregateste 
update:
	wget $(CHECKER)
	unzip -o $(CARCHIVE)
	sudo chmod 755 check.sh
	rm -f $(CARCHIVE)*

# Verifica memoria pentru leak-uri
MFLAGS = --leak-check=full --show-leak-kinds=all 
memory:build
	valgrind $(MFLAGS) ./$(EXE)

# Foloseste checkerul pentru a verifica tema
check:update build
	cp Readme.md README
	./check.sh
	rm README

# Sterge toate fisierele care nu o sa apara in repository
purge:
	rm -f $(EXE) $(OBJ)
	rm -rfd ./ref
	rm -rfd ./input
	rm -f cpplint.py
	rm -f checkstyle.txt
	rm -f check.sh
	rm -f README
	rm -f $(ANAME)
	echo "All files were removed"

# Adauga toate fisierele care nu trebuie sa fie include in repository
# la .gitignore
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
	@find . -executable -type f -not -path "*/.git/*" | cut -c 3- >>.gitignore ||:
	echo "Updated .gitignore"
