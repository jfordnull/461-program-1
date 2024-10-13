CXX = g++
# -g : debug info, c++11 standard
CXXFLAGS = -g -std=c++11
SRC_DIR = src
BUILD_DIR = build
TARGET = $(BUILD_DIR)/main

# Source files
SRCS = $(SRC_DIR)/main.cpp $(SRC_DIR)/graph.cpp $(SRC_DIR)/bfs.cpp $(SRC_DIR)/util.h

# Object files
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/graph.o $(BUILD_DIR)/bfs.o

all: $(TARGET)

$(TARGET): $(OBJS)
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.cpp 
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/graph.o: $(SRC_DIR)/graph.cpp
	mkdir -p $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/graph.cpp -o $(BUILD_DIR)/graph.o

$(BUILD_DIR)/bfs.o: $(SRC_DIR)/bfs.cpp
	$(CXX) $(CXXFLAGS) -c $(SRC_DIR)/bfs.cpp -o $(BUILD_DIR)/bfs.o

clean:
	rm -rf $(BUILD_DIR)
