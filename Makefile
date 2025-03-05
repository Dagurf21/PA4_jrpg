CXX = g++
CXXFLAGS = -Wall -std=c++11

SRCS = main.cpp Character.cpp Warrior.cpp Mage.cpp
OBJS = $(SRCS:.cpp=.o)
TARGET = jrpg

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
