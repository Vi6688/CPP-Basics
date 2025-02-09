CXX = g++
CXXFLAGS = -I Basics/Common -Wall -Wextra -MMD -MP

# Gather all source files.
SRCS := $(wildcard Basics/Railway/*.cpp)
# Convert source filenames to object filenames in the build directory.
OBJS := $(patsubst Basics/Railway/%.cpp,Basics/Build/%.o,$(SRCS))

# Final executable depends on all object files.
test: $(OBJS)
	$(CXX) $(CXXFLAGS) -o test $(OBJS)

# Pattern rule: compile each .cpp to a corresponding .o in Basics/Build.
Basics/Build/%.o: Basics/Railway/%.cpp | Basics/Build
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Include all generated dependency files.
-include $(OBJS:.o=.d)

# Ensure the build directory exists.
Basics/Build:
	mkdir -p Basics/Build

clean:
	rm -f Basics/Build/*.o Basics/Build/*.d test

.PHONY: clean
