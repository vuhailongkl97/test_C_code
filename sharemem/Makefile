.PHONY: clean all test read write

READ_SRC := read.c
WRITE_SRC := write.c

all: read write

read:
	$(CC) $(READ_SRC) -o $@

write:
	$(CC) $(WRITE_SRC) -o $@

test:
	./write
	./read

clean:
	rm -f ./*.o ./read ./write

