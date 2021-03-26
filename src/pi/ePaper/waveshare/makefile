OBJ_C = $(wildcard *.c)
TARGET = epd
CC = gcc
MSG = -g -O0 -Wall
DEBUG = -D DEBUG
# DEBUG = 
CFLAGS = $(MSG) $(DEBUG) -lwiringPi -lm -D USE_WIRINGPI_LIB -D RPI
LIBFLAGS = $(CFLAGS) -D BUILD_AS_LIBRARY -fPIC -shared


${TARGET}:${OBJ_C}
	$(CC) $(CFLAGS) $(OBJ_C) -o $@
	$(CC) $(LIBFLAGS) $(OBJ_C) -o lib$@.so


clean:
	@[ -f ./$(TARGET) ] && rm $(TARGET) || true
	@[ -f ./lib$(TARGET).so ] && rm lib$(TARGET).so || true
