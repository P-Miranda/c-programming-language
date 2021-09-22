CC:=gcc
EXE:=example4-4

HDR:=calc.h
SRC:= getch.c getop.c main.c stack.c

all: $(SRC) $(HDR)
	$(CC) $(SRC) $(HDR) -o $(EXE)
	./$(EXE)

clean:
	@rm -f $(EXE)
