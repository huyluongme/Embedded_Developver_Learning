# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -pthread

# Executable name
TARGET = atm_system

# Source files
SRCS = main.cc user_account.cc atm.cc atm_service.cc atm_app.cc

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
