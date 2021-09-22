CC:=gcc
EXE:=exercise4-11

HDR:=calc.h
SRC:= getch.c getop.c main.c stack.c

all: $(SRC) $(HDR)
	$(CC) $(SRC) $(HDR) -o $(EXE)
	./$(EXE)

clean:
	@rm -f $(EXE)
