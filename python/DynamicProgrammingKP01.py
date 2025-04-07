from Solution import Solution

class DynamicProgrammingKP01:
    def __init__(self):
        pass
    
    def solve(self, instance):
        """
        Solve the 0-1 Knapsack Problem using dynamic programming.
        Note: This doesn't consider conflicts.
        """
        capacity = instance.get_capacity()
        n = instance.get_num_items()
        
        # Create solution object
        solution = Solution(n)
        
        # Create DP table
        m = [[0 for _ in range(capacity + 1)] for _ in range(n + 1)]
        
        # Fill the DP table
        for k in range(1, n + 1):
            for c in range(1, capacity + 1):
                if instance.get_weight(k - 1) > c:
                    m[k][c] = m[k - 1][c]
                else:
                    m[k][c] = max(
                        m[k - 1][c],
                        instance.get_profit(k - 1) + m[k - 1][c - instance.get_weight(k - 1)]
                    )
        
        # Reconstruct the solution
        c = capacity
        for k in range(n, 0, -1):
            if m[k][c] != m[k - 1][c]:
                item_index = k - 1
                solution.add_item(item_index)
                solution.add_weight(instance.get_weight(item_index))
                solution.add_profit(instance.get_profit(item_index))
                c -= instance.get_weight(item_index)
        
        return solution