CXX := g++
CXXFLAGS := -std=c++23
TARGET := game

SOURCES := game_loop.cpp story_nodes.cpp node.cpp action_logic.cpp fight_loop.cpp
OBJECTS := $(SOURCES:.cpp=.o)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(TARGET)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET) *.o
