CXX := g++

CXXFLAGS := -std=c++20 -Wall -Wextra -Wpedantic
CPPFLAGS := -Iinclude

TARGET := battery_test

SOURCES := \
	src/Battery.cpp \
	test/main.cpp

.PHONY: all run clean

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(SOURCES) -o $(TARGET)

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(TARGET)