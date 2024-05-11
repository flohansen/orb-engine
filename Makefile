CC = gcc
CXX = g++

LDFLAGS = -L/usr/lib
LDFLAGS += -lglfw

TARGET = main
cpp_files = src/main.cpp
objects = $(cpp_files:.cpp=.o)

all: $(TARGET)

$(TARGET): $(objects)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY : clean
clean:
	rm $(TARGET) $(objects)
