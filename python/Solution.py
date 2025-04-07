class Solution:
    def __init__(self, num_items):
        self.elements = []
        self.total_weight = 0
        self.total_profit = 0
        
    def add_item(self, item):
        """Add an item to the solution."""
        self.elements.append(item)
        
    def remove_item(self, item):
        """Remove an item from the solution."""
        if item in self.elements:
            self.elements.remove(item)
            
    def contains(self, item):
        """Check if the solution contains an item."""
        return item in self.elements
    
    def get_items(self):
        """Return all items in the solution."""
        return self.elements
    
    def print_solution(self):
        """Print the details of the solution."""
        print("Elements:", end=" ")
        for elem in self.elements:
            print(elem, end=" ")
        print(f"\nTotal weight: {self.total_weight}")
        print(f"Total profit: {self.total_profit}")
        
    def add_weight(self, weight):
        """Add weight to the total weight."""
        self.total_weight += weight
        
    def add_profit(self, profit):
        """Add profit to the total profit."""
        self.total_profit += profit
        
    def get_total_profit(self):
        """Return the total profit."""
        return self.total_profit
    
    def get_total_weight(self):
        """Return the total weight."""
        return self.total_weight