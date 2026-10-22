TARGET = lonzo
TEST_TARGET = tests
SRC = sslice.c token.c lexer.c repl.c ast.c parser.c sbuilder.c
CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(TARGET): main.c $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) main.c $(SRC)

run: $(TARGET)
	./$(TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

clean:
	rm -f $(TEST_TARGET) $(TARGET)

tests: tests.c $(SRC)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) tests.c $(SRC)
