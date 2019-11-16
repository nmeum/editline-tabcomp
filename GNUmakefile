CFLAGS += -std=c99 -D_POSIX_C_SOURCE=200809L
CFLAGS += -Wpedantic -Wall -Wextra \
	      -Wmissing-prototypes -Wpointer-arith \
	      -Wstrict-prototypes -Wshadow -Wformat-nonliteral

LDLIBS += -ledit -lncurses

example: example.o complete.o
%.o: %.c complete.h
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $<
