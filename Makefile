CPP = g++
CPPFLAGS = -Wall

TRABALHOOBJS = main.o nacional.o estadual.o

trabalho: $(TRABALHOOBJS)
	$(CPP) $(CPPFLAGS) -o $@ $(TRABALHOOBJS)


