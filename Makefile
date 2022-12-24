CC      = clang

TARGET  = fake.so
SOURCES = libfake/passwd.c libfake/getenv.c ./libfake/envp.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS  = -O2 -Wall


all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ -shared -nostartfiles -fPIC

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(TARGET) $(OBJECTS)
