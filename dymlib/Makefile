LIB=liboverwrite.so
OBJ=liboverwrite.o

$(LIB):$(OBJ)
	$(CC) -fPIC -shared $^ -o $(LIB) -ldl
%.o:%.c
	$(CC)  -c $^

all: $(LIB)

clean:
	rm -f $(LIB) $(OBJ) a.out

a.out: main.c
	$(CC) $^ -o $@

test: a.out
	LD_PRELOAD=./liboverwrite.so ./a.out


