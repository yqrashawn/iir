CXX = g++
CXXFLAGS = -Wextra -std=c++11

SRCDIR = ./src
SRCS   = $(wildcard $(SRCDIR)/*.cpp)
OBJS   = $(subst .cpp,.o, $(SRCS))

all: iir

iir: $(OBJS)
	$(CXX) -o $@ $^

$(SRCDIR)/%.o: %.h %.cpp

clean:
	rm -f $(SRCDIR)/*.o
