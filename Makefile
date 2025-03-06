CXX = g++
CXXFLAGS = -Wall -std=c++11 -I.  # -I. tells the compiler to look in the project root for headers

SRCS = main.cpp Character.cpp \
       Characters/Beastmaster/Beastmaster.cpp \
       Characters/Berserker/Berserker.cpp \
       Characters/Cleric/Cleric.cpp \
       Characters/DarkKnight/DarkKnight.cpp \
       Characters/Elementalist/Elementalist.cpp \
       Characters/Mage/Mage.cpp \
       Characters/Paladin/Paladin.cpp \
       Characters/Rogue/Rogue.cpp \
       Characters/Warrior/Warrior.cpp

OBJS = $(SRCS:.cpp=.o)
TARGET = jrpg

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)
