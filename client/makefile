
BIN = ./bin/
SRC = ./src/
#INC = ./inc/
CFLAGS = -g -Wall

LIB = -lGL

# $< is dependencies (right) $@ is target
$(BIN)client : $(SRC)client.cpp
	g++ $(INC) $< $(CFLAGS) -o $@ $(LIB)

clean:
	$(RM) $(BIN)client 