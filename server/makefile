
BDIR = ./bin
SDIR = ./src
IDIR = ./inc
LDIR = ./lib
ODIR = ./src/obj

CFLAGS = -Wall -g -I$(IDIR)
# $< is dependencies (right) $@ is target
# -o means the next token is the name of the executable

all: ./bin/server

$(BDIR)/server : ./src/obj/server.o ./src/obj/chunks.o
	gcc $< -o $@ $(CFLAGS)

$(ODIR)/server.o : ./src/server.c 
	gcc -c $(CFLAGS) $< -o $@

$(ODIR)/chunks.o : ./src/chunks.c
	gcc -c $(CFLAGS) $< -o $@



#prevent anything from happening to a file named clean
.FAKE : clean

clean:
	$(RM) $(BDIR)/server $(ODIR)/*.o