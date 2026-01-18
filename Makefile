# Compiler
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Directories
SRC_DIR = src
BUILD_DIR = build
OUTPUT_DIR = output

# Source files
SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/ui/Menu.cpp \
          $(SRC_DIR)/services/QueueService.cpp \
          $(SRC_DIR)/services/RiwayatService.cpp \
          $(SRC_DIR)/services/PaymentService.cpp \
          $(SRC_DIR)/utils/InputHelper.cpp

# Output
TARGET = $(OUTPUT_DIR)/SistemAntrianSIM.exe

# Default target
all: $(TARGET)

$(TARGET): $(SOURCES)
	@if not exist $(BUILD_DIR) mkdir $(BUILD_DIR)
	@if not exist $(OUTPUT_DIR) mkdir $(OUTPUT_DIR)
	$(CXX) $(CXXFLAGS) -I$(SRC_DIR) $(SOURCES) -o $(TARGET)

# Clean
clean:
	@if exist $(BUILD_DIR) rmdir /s /q $(BUILD_DIR)
	@if exist $(TARGET) del $(TARGET)

# Run
run: $(TARGET)
	$(TARGET)

.PHONY: all clean run
