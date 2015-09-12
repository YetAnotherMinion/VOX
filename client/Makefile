
BIN = ./bin
SRC = ./src
INC = ./inc
OBJ = ./obj
CFLAGS = -g -Wall

LIB = -lGL

# $< is dependencies (right) $@ is target
$(BIN)/client : $(SRC)/client.cpp
	$(CXX) -I $(INC) $< $(CFLAGS) -o $@ $(LIB)

clean:
	$(RM) $(BIN)client 
