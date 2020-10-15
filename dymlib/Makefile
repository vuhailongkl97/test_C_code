LIB=liboverwrite.so
OBJ=liboverwrite.o

$(LIB):$(OBJ)
	$(CC) -fPIC -shared $^ -o $(LIB) -ldl

liboverwrite_pthread.so : liboverwrite_pthread.o
	$(CC) -fPIC -shared $^ -o $@ -ldl

%.o:%.c
	$(CC)  -c $^

clean:
	rm -f $(LIB) $(OBJ) a.out

a.out: main.c
	$(CC) $^ -o $@ -lpthread

test: a.out
	LD_PRELOAD=./liboverwrite.so ./a.out

test_pthread:liboverwrite_pthread.so a.out
	LD_PRELOAD=./liboverwrite_pthread.so ./a.out
