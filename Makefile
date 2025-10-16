# Компилятор и флаги
CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic
MATH_FLAG = -lm

# Директории
SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = test
BUILD_DIR = build

# Цели
TARGET = formula
TEST_TARGET = run_tests

# Исходные файлы
SRCS = $(SRC_DIR)/formula.c
MAIN_SRC = $(SRC_DIR)/main.c  # создайте этот файл для основной программы
TEST_SRC = $(TEST_DIR)/tests.c

# Объектные файлы
OBJS = $(BUILD_DIR)/formula.o
MAIN_OBJ = $(BUILD_DIR)/main.o
TEST_OBJ = $(BUILD_DIR)/tests.o

# Основная цель по умолчанию
all: $(BUILD_DIR) $(TARGET)

# Создание директории для сборки
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Компиляция основной программы
$(TARGET): $(MAIN_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN_OBJ) $(OBJS) $(MATH_FLAG)

# Компиляция объектного файла для основной программы
$(MAIN_OBJ): $(MAIN_SRC) $(INCLUDE_DIR)/formula.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(MAIN_SRC) -o $(MAIN_OBJ)

# Компиляция основного модуля
$(OBJS): $(SRCS) $(INCLUDE_DIR)/formula.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(SRCS) -o $(OBJS)

# Компиляция тестов
$(TEST_TARGET): $(TEST_OBJ) $(OBJS)
	$(CC) $(CFLAGS) -o $(TEST_TARGET) $(TEST_OBJ) $(OBJS) $(MATH_FLAG)

# Компиляция объектного файла тестов
$(TEST_OBJ): $(TEST_SRC) $(INCLUDE_DIR)/formula.h $(INCLUDE_DIR)/tests.h
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $(TEST_SRC) -o $(TEST_OBJ)

# Запуск тестов
test: $(TEST_TARGET)
	./$(TEST_TARGET)

# Запуск основной программы
run: $(TARGET)
	./$(TARGET)

# Очистка
clean:
	rm -rf $(BUILD_DIR) $(TARGET) $(TEST_TARGET)

# Пересборка
rebuild: clean all

# Справка
help:
	@echo "Доступные цели:"
	@echo "  all      - сборка основной программы (по умолчанию)"
	@echo "  test     - сборка и запуск тестов"
	@echo "  run      - сборка и запуск основной программы"
	@echo "  clean    - удаление собранных файлов"
	@echo "  rebuild  - полная пересборка"
	@echo "  help     - показать эту справку"

.PHONY: all test run clean rebuild help
