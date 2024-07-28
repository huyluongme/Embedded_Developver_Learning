# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17

# Executable name
TARGET = exercise4

# Source files
SRCS = main.cc node.cc doubly_linked_list.cc presentation.cc

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
ifeq ($(OS),Windows_NT)
	del $(OBJS)
else
	rm -f $(OBJS)
endif

# Phony targets
.PHONY: all clean
