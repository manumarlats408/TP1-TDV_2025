import sys
from KP01withCGInstance import KP01withCGInstance
from Solution import Solution
from DynamicProgrammingKP01 import DynamicProgrammingKP01
from BacktrackingKP01wCG import BacktrackingKP01wCG


def main():
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <algorithm> <instance>")
        print("Available algorithms: dp (Dynamic Programming), bt (Backtracking)")
        return 1
    
    algorithm = sys.argv[1]
    instance_name = sys.argv[2]
    
    # Create and read the instance
    instance = KP01withCGInstance()
    instance.read_instance_from_file("./test_instance.in")


    
    print(instance.get_num_items())
    print(instance.get_capacity())
    
    # Initialize empty solution
    i = 0
    initial_solution = Solution(instance.get_num_items())
    
    # Choose and apply the algorithm
    if algorithm == "dp":
        solver = DynamicProgrammingKP01()
        solution = solver.solve(instance)
    elif algorithm == "bt":
        solver = BacktrackingKP01wCG()
        solution = solver.solve(instance, initial_solution, i)
    else:
        print(f"Unknown algorithm: {algorithm}")
        return 1
    
    # Print the results
    solution.print_solution()
    
    return 0

if __name__ == "__main__":
    main()