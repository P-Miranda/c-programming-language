CHAPTER?=1

ifndef EXAMPLE
ifndef EXERCISE
	RUN_PATH:=./Chapter$(CHAPTER)/Example1-1
else
	RUN_PATH:=./Chapter$(CHAPTER)/Exercise$(EXERCISE)
endif
else
	RUN_PATH:=./Chapter$(CHAPTER)/Example$(EXAMPLE)
endif

all:
	make -C $(RUN_PATH) all

clean:
	make -C $(RUN_PATH) clean
