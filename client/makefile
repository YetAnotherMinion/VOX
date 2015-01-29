
BIN = ./bin/
SRC = ./src/
#INC = ./inc/
CFLAGS = -g -Wall

LIB = -lGL -lglfw

# $< is dependencies (right) $@ is target
$(BIN)client : $(SRC)client.cpp
	g++ $(INC) $< $(CFLAGS) -o $@ $(LIB)

clean:
	$(RM) $(BIN)client 