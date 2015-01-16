
BDIR = ./bin
SDIR = ./src
IDIR = ./inc
LDIR = ./lib
ODIR = ./src/obj

CFLAGS = -Wall -g -I$(IDIR)
# $< is dependencies (right) $@ is target
# -o means the next token is the name of the executable

#use DEPS to require a rebuild whenever a header file changes
_DEPS = chunks.h octree.h ellipsoid.h
DEPS = $(patsubst %, $(IDIR)/%, $(_DEPS))

#hold all the objects other than server
#this is so that whenever something changes the server is recompiled
_OBJ = chunks.o octree.o ellipsoid.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

all: ./bin/server

$(BDIR)/server : ./src/obj/server.o $(OBJ)
	gcc $< -o $@ $(CFLAGS)

$(ODIR)/server.o : ./src/server.c 
	gcc -c $(CFLAGS) $< -o $@

$(ODIR)/chunks.o : $(SDIR)/chunks.c $(DEPS)
	gcc -c $(CFLAGS) $< -o $@

$(ODIR)/octree.o : $(SDIR)/octree.c $(DEPS)
	gcc -c $(CFLAGS) $< -o $@

$(ODIR)/ellipsoid.o : $(SDIR)/ellipsoid.c $(DEPS)
	gcc -c $(CFLAGS) $< -o $@

#prevent anything from happening to a file named clean
.FAKE : clean

clean:
	$(RM) $(BDIR)/server $(ODIR)/*.o