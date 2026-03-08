CXX = g++
CXXFLAGS = -Wall -std=c++17
TARGETS = binary_search factorial fibonacci string_reversal

all: $(TARGETS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

clean:
	rm -f $(TARGETS)