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

# LDFLAGS+= -lGL -lglut -lpng -lz -lm


LDDEBUGFLAGS+=$(foreach librarydir,$(LIB_DIR),-L$(librarydir))
LDDEBUGFLAGS+=$(foreach library,$(DEBUGLIBS),-l$(library))

INCFLAGS:=$(addprefix -I,$(INCL))

DEPS := $(OBJS:.o=.d)

CFLAGS = -MMD 

BIN=BIN/application

BINDEBUG=$(BIN)

.PHONY: all debug

all: $(BIN)

debug: $(BINDEBUG)

$(BINDEBUG): $(OBJ) 
	$(CXX) $(CXXFLAGS) -o $@ $(LDDEBUGFLAGS)

-include $(DEPS)

$(BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $@ $(LDFLAGS)

$(OBJ)/%.o: $(SRC)/%.cpp 
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -c $< -o $@

$(OBJ)/%.d: $(SRC)/%.cpp 
	$(CXX) $(CXXFLAGS) $(INCFLAGS) -MM -MT "$(OBJ)/$(<:.c=.o) $(OBJ)/$(<:.c=.d)" "$<" > "$@"

$(OBJ):
	mkdir $@

clean:
	rm -f -r $(OBJ)
	rm -f $(BIN)


rebuild:
	+@make clean
	+@make
	
run: $(BIN)
	./$(BIN) $(PARAM) $(ARG)
