src=main.c

obj=$(patsubst %.c,%.o,$(src))

.c.o:
	$(CC) $^ -c -D$(PARA)

	
main:$(obj)
	echo $^ -D$(PARA)
	$(CC) $^ -D$(PARA)

