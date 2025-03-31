CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2 -v

SRC = main.cpp KP01withCGInstance.cpp Solution.cpp DynamicProgrammingKP01.cpp BacktrackingKP01wCG.cpp BruteForceKP01wCG.cpp Graph.cpp
HEADERS = KP01withCGInstance.h Solution.h DynamicProgrammingKP01.h BacktrackingKP01wCG.h BruteForceKP01wCG.h Graph.h
OBJ = $(SRC:.cpp=.o)
EXEC = knapsack_solver

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
