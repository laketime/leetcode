

CPP_SRC = $(wildcard *.cpp) 
CPP_OBJ = $(patsubst %.cpp, %, $(CPP_SRC))

.PHONY:all clean 

all: $(CPP_OBJ)

.cpp.o:
	g++ -o $@ $<

clean:
	@rm -f $(CPP_OBJ)
