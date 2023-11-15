# Makefile para o projeto

# Compiler
CC = g++
# Compiler flags
CFLAGS = -std=c++11 -Wall

# Diretórios
SRCDIR = src
INCDIR = include
BINDIR = bin
OBJDIR = obj

# Arquivos fonte
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Alvo principal
TARGET = $(BINDIR)/a.out

# Diretórios de inclusão
INC = -I$(INCDIR)

# Regras
all: $(TARGET)

# Regra para construir o executável
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Regra para construir os objetos
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Alvo fictício para limpar o projeto
clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*

# Indica que 'all' e 'clean' não são nomes de arquivos
.PHONY: all clean