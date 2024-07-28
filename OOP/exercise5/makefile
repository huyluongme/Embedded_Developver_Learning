# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17

# Executable name
TARGET = exercise5

# Source files
SRCS = main.cc stack_or_queue.cc stack.cc queue.cc

# Object files
OBJS = $(SRCS:.cc=.o)

# Default target
all: $(TARGET) clean

# Rule to build the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Rule to build each object file
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files
clean:
	rm $(OBJS)

# Phony targets
.PHONY: all clean
