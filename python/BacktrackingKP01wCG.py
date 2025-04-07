from Solution import Solution

class BacktrackingKP01wCG:
    def __init__(self):
        pass
    
    def has_conflict(self, solution, instance):
        """Check if the solution has conflicts."""
        graph = instance.get_conflicts_graph()
        items = solution.get_items()
        
        for i in range(len(items)):
            for j in range(i + 1, len(items)):
                if graph.are_adjacent(items[i], items[j]):
                    return True
        return False
    
    def better_solution(self, solution1, solution2, instance):
        """Compare two solutions and return the better one."""
        has_conflict1 = self.has_conflict(solution1, instance)
        has_conflict2 = self.has_conflict(solution2, instance)
        
        # If both solutions have no conflicts
        if not has_conflict1 and not has_conflict2:
            # Check capacity constraints
            if (solution1.get_total_weight() <= instance.get_capacity() and 
                solution2.get_total_weight() > instance.get_capacity()):
                return solution1
            
            if (solution1.get_total_weight() > instance.get_capacity() and 
                solution2.get_total_weight() <= instance.get_capacity()):
                return solution2
            
            if (solution1.get_total_weight() <= instance.get_capacity() and 
                solution2.get_total_weight() <= instance.get_capacity()):
                # Choose the one with higher profit
                return solution1 if solution1.get_total_profit() > solution2.get_total_profit() else solution2
        
        # If only one solution has no conflicts
        if not has_conflict1 and has_conflict2:
            return solution1
        
        if has_conflict1 and not has_conflict2:
            return solution2
        
        # Both have conflicts or other issues
        return Solution(instance.get_num_items())
    
    def solve(self, instance, current_solution, i):
        """
        Solve the 0-1 Knapsack Problem with conflicts using backtracking.
        
        Args:
            instance: The problem instance
            current_solution: The current partial solution
            i: The current item index being considered
        """
        num_items = instance.get_num_items()
        
        # Base case: all items considered
        if num_items == 0 or i == num_items:
            if (current_solution.get_total_weight() <= instance.get_capacity() and 
                not self.has_conflict(current_solution, instance)):
                return current_solution
            return Solution(num_items)
        
        # Pruning: If current solution exceeds capacity or has conflicts
        if (current_solution.get_total_weight() > instance.get_capacity() or 
            self.has_conflict(current_solution, instance)):
            return Solution(num_items)
        
        # Explore without including the current item
        solution_without_item = self.solve(instance, current_solution, i + 1)
        
        # Explore with including the current item
        solution_with_item = Solution(num_items)
        for item in current_solution.get_items():
            solution_with_item.add_item(item)
        solution_with_item.total_weight = current_solution.get_total_weight()
        solution_with_item.total_profit = current_solution.get_total_profit()
        
        solution_with_item.add_item(i)
        solution_with_item.add_weight(instance.get_weight(i))
        solution_with_item.add_profit(instance.get_profit(i))
        
        solution_with_item = self.solve(instance, solution_with_item, i + 1)
        
        # Return the better solution
        return self.better_solution(solution_without_item, solution_with_item, instance)