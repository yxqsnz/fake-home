CC      = clang

TARGET  = fake.so
SOURCES = fake.c libfake/passwd.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS  = -O2 -Wall


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -shared -nostartfiles -fPIC

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJECTS)
