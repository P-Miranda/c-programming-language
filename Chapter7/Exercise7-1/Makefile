CC:=gcc
EXE:=exercise7-1

SRC:=exercise7-1.c 

all: $(SRC)
	$(CC) $(SRC) -o $(EXE) -lm
	./$(EXE)

lower: $(SRC)
	$(CC) $(SRC) -o lower
	./lower

upper: $(SRC)
	$(CC) $(SRC) -o upper
	./upper

clean:
	@rm -f $(EXE)
	@rm -f lower upper
