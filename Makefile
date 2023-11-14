# Makefile para o projeto

# Compiler
CC = g++

# Compiler flags
CFLAGS = -std=c++11 -Wall

# Directories
SRCDIR = src
INCDIR = include
BINDIR = bin
OBJDIR = obj

# Source files
SRCS = $(wildcard $(SRCDIR)/*.cpp)
OBJS = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRCS))

# Main target
TARGET = $(BINDIR)/tp2.out

# Include directories
INC = -I$(INCDIR)

# Rules
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Phony target to clean the project
clean:
	rm -rf $(BINDIR)/* $(OBJDIR)/*

.PHONY: all clean
