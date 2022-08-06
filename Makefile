IDIR = include
SDIR=src
CXX=clang++
CFLAGS=-I$(IDIR) -Wall -pedantic

ODIR=obj

_DEPS = node.h parser.h scanner.h token.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = main.o node.o scanner.o parser.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SDIR)/%.cpp $(DEPS)
	@mkdir -p obj
	$(CXX) -c -o $@ $< $(CFLAGS)

calc: $(OBJ)
	@mkdir -p bin
	$(CXX) -o bin/$@ $^ $(CFLAGS)
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 