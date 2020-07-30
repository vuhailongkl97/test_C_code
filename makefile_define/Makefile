DEFAULT_FLAG=SERIAL

ifneq ($(FLAG),)
DFLAG=-D$(FLAG)
else
DFLAG:=-D$(DEFAULT_FLAG)
endif

all:
	gcc main.c $(DFLAG)
