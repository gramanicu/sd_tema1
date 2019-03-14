# Copyright 2019 Grama Nicolae

# Informatii program
CC = g++
CFLAGS = -Wall -Wextra -pedantic -O3
#FLAGS = -lm
EXE = snowfight
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
	$(CC) -o $(EXE) $^ $(LFLAGS) $(CFLAGS)
	rm -f *.o

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

# Face coding-style automat, la standardul google, cu o mica modificare
# (4 spatii in loc de 2 la alineate)
beauty: 
	clang-format -i -style=file *.cpp *.h

# Descarca arhiva cu checkerul si o pregateste 
update:
	wget $(CHECKER)
	unzip -o $(CARCHIVE)
	rm -f $(CARCHIVE)*

# Verifica memoria pentru leak-uri
MFLAGS = --leak-check=full --show-leak-kinds=all 
memory:build
	valgrind $(MFLAGS) ./$(EXE)

# Foloseste checkerul pentru a verifica tema
check:update build prepare
	./check.sh

# Sterge toate fisierele care nu o sa apara in repository
purge:
	rm -f $(EXE) $(OBJ)
	rm -rfd ./ref
	rm -rfd ./input
	rm -f cpplint.py
	rm -f README
	rm -f $(ANAME)

# Adauga toate fisierele care nu trebuie sa fie include in repository
# la .gitignore
gitignore:
	echo "check.sh" > .gitignore
	echo "input*" >> .gitignore
	echo "ref*" >> .gitignore
	echo "cpplint.py" >> .gitignore
	echo "README" >> .gitignore
	echo "$(ANAME)" >> .gitignore
	echo "$(EXE)" >> .gitignore
	find . -executable -type f -not -path "*/.git/*" | cut -c 3- >>.gitignore

.PHONY: gitignore check purge clean memory update beauty pack run