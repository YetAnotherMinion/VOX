
BIN = ./bin/
SRC = ./src/
#INC = ./inc/
CFLAGS = -g -Wall

LIB = -lGL

$(BIN)client : $(SRC)client.cpp
	g++ $(INC) $< $(CFLAGS) -o $@ $(LIB)

clean:
	$(RM) $(BIN)client 