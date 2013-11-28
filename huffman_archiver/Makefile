CXX = g++
CXXFLAGS = -Wall -O2

SRCDIR = src
OUTDIR = bin

EXEC = $(OUTDIR)/arj
SOURCES = $(wildcard src/*.cpp)
OBJECTS  := $(SOURCES:$(SRCDIR)/%.cpp=$(OUTDIR)/%.o)

all: MKDIR $(EXEC)

MKDIR:
	mkdir -p $(OUTDIR)

$(EXEC): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(EXEC)

$(OBJECTS): $(OUTDIR)/%.o : $(SRCDIR)/%.cpp
	$(CXX) -c $(CXXFLAGS) $< -o $@

clean:
	rm -rf $(OUTDIR)

.PHONY: clean
