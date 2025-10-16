# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -Iinclude
LDFLAGS = -lm

# Цели
TARGET = sequence_formula
TEST_TARGET = test_formula

# Исходные файлы
SRC_DIR = src
TEST_DIR = test
INC_DIR = include

SOURCES = $(SRC_DIR)/formula.c $(SRC_DIR)/tests.c $(SRC_DIR)/main.c
TEST_SOURCES = $(SRC_DIR)/formula.c $(TEST_DIR)/test_formula.c

# Объектные файлы
OBJECTS = $(SOURCES:.c=.o)
TEST_OBJECTS = $(TEST_SOURCES:.c=.o)

# Правило по умолчанию
all: $(TARGET)

# Сборка основной программы
$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

# Сборка тестов
$(TEST_TARGET): $(TEST_OBJECTS)
	$(CC) -o $@ $^ $(LDFLAGS)

# Компиляция .c файлов в .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Очистка
clean:
	rm -f $(TARGET) $(TEST_TARGET) $(OBJECTS) $(TEST_OBJECTS)

# Запуск тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Запуск основной программы
run: $(TARGET)
	./$(TARGET)

# Отладочная сборка
debug: CFLAGS += -g -DDEBUG
debug: clean $(TARGET)

# Профилировочная сборка
profile: CFLAGS += -pg
profile: LDFLAGS += -pg
profile: clean $(TARGET)

# Показать помощь
help:
	@echo "Доступные цели:"
	@echo "  all     - собрать основную программу (по умолчанию)"
	@echo "  test    - собрать и запустить тесты"
	@echo "  run     - собрать и запустить основную программу"
	@echo "  clean   - удалить скомпилированные файлы"
	@echo "  debug   - собрать с отладочной информацией"
	@echo "  profile - собрать с поддержкой профилирования"

.PHONY: all clean test run debug profile help
