CC = gcc
CXX = g++

LDFLAGS = 
LDFLAGS += -lglfw

TARGET = target/main
cpp_files = src/main.cpp src/app/window.cpp vendor/glad/glad.c
objects = $(cpp_files:.cpp=.o)

all: $(TARGET)

$(TARGET): $(objects)
	$(CXX) -o $@ $^ $(LDFLAGS)

.PHONY : clean
clean:
	rm $(TARGET) $(objects)
