PROJDIR  := .
LIBDIR   :=./lib
BUILD_TARGET  := t
SRCFILES =main.c
LIBFILES=link_list.c
OBJFILES := $(patsubst %.c,%.o,$(SRCFILES))
LIBOBJFILES := $(patsubst %.c,%.o,$(LIBFILES))
CFLAGS   := -llink_list -Wall
CC 	 := gcc

all: $(OBJFILES) $(LIBOBJFILES)
	$(CC)  $(OBJFILES)  $(CFLAGS) -o $(BUILD_TARGET) -L./ -Wl,-rpath=$(PWD)
clean:
	rm -f $(OBJFILES) $(BUILD_TARGET)
%.o: %.c
	$(CC) -c -I $(LIBDIR) $< -o $@ $(DFLAG)

lib: $(LIBOBJFILES)
	$(CC) -shared -o liblink_list.so -fPIC $(LIBFILES) -Wall -Wl,-rpath=$(PWD)

