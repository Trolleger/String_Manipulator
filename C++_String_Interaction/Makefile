SFML_DIR = ../SFML-3.0.0-windows-gcc-14.2.0-mingw-64-bit/SFML-3.0.0

CXX = g++
CXXFLAGS = -I"$(SFML_DIR)/include" -Wall -Wextra
LDFLAGS = -L"$(SFML_DIR)/lib"
LIBS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = main.exe

.PHONY: all clean run

all: $(EXEC) run

$(EXEC): $(OBJ)
	$(CXX) $(OBJ) $(LDFLAGS) $(LIBS) -o $(EXEC)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(EXEC)
	./$(EXEC)

clean:
	del /Q $(OBJ) $(EXEC)
