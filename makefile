CXX=g++
CXXFLAGS=-g

SRC=./src
OBJ=obj
INCL=C:\SFML-2.5.1\include
SRCS=$(wildcard $(SRC)/*.cpp)
OBJS=$(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

HDRS += $(foreach includedir, $(INCL), $(wildcard $(includedir)/*.h))



LIB_DIR=C:\SFML-2.5.1\lib

LIBS=sfml-graphics sfml-window sfml-system

DEBUGLIBS=sfml-graphics-d sfml-window-d sfml-system-d


LDFLAGS+=$(foreach librarydir,$(LIB_DIR),-L$(librarydir))
LDFLAGS+=$(foreach library,$(LIBS),-l$(library))

LDDEBUGFLAGS+=$(foreach librarydir,$(LIB_DIR),-L$(librarydir))
LDDEBUGFLAGS+=$(foreach library,$(DEBUGLIBS),-l$(library))

INCFLAGS:=$(addprefix -I,$(INCL))

BIN=BIN/application

BINDEBUG=$(BIN)

.PHONY: all debug

all: $(BIN)

debug: $(BINDEBUG)

$(BINDEBUG): $(OBJS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDDEBUGFLAGS)

$(BIN): $(OBJS) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp $(OBJ) $(HDRS)
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -o $@ -c $<

$(OBJ):
	mkdir -p $@

clean:
	rm -f -r $(OBJ)
	rm -f $(BIN)



