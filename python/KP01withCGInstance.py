from Graph import Graph
import os

class KP01withCGInstance:
    def __init__(self, n=0, cap=0):
        self.num_items = n
        self.capacity = cap
        self.items_weight = []
        self.items_profit = []
        self.num_conflicts = 0
        self.conflicts = Graph()
        
    def set_weight(self, index, weight):
        """Set the weight of an item at the given index."""
        self.items_weight[index] = weight
        
    def set_profit(self, index, profit):
        """Set the profit of an item at the given index."""
        self.items_profit[index] = profit
        
    def get_weight(self, index):
        """Get the weight of an item at the given index."""
        return self.items_weight[index]
    
    def get_profit(self, index):
        """Get the profit of an item at the given index."""
        return self.items_profit[index]
    
    def get_num_items(self):
        """Get the number of items."""
        return self.num_items
    
    def get_capacity(self):
        """Get the capacity of the knapsack."""
        return self.capacity
    
    def add_conflict(self, item1, item2):
        """Add a conflict between two items."""
        self.conflicts.add_conflict(item1, item2)
        
    def remove_conflict(self, item1, item2):
        """Remove a conflict between two items."""
        self.conflicts.remove_conflict(item1, item2)
        
    def read_instance_from_file(self, filename):
        """Read an instance from a file."""
        print("Intentando abrir:", filename)
        print("¿Existe el archivo?:", os.path.exists(filename))
        print("Ruta absoluta actual:", os.path.abspath(filename))
        with open(filename, 'r') as file:
            lines = file.readlines()
            
            # Parse number of items and capacity
            first_line = lines[0].strip().split()
            self.num_items = int(first_line[0])
            
            second_line = lines[1].strip().split()
            self.capacity = int(second_line[0])
            
            # Parse weights
            weights_line = lines[2].strip().split()
            self.items_weight = [int(w) for w in weights_line]
            
            # Parse profits
            profits_line = lines[3].strip().split()
            self.items_profit = [int(p) for p in profits_line]
            
            # Parse number of conflicts
            conflicts_count_line = lines[4].strip().split()
            self.num_conflicts = int(conflicts_count_line[0])
            
            # Parse conflicts
            conflicts_list = []
            for i in range(5, 5 + self.num_conflicts):
                conflict_line = lines[i].strip().split()
                u, v = int(conflict_line[0]), int(conflict_line[1])
                conflicts_list.append((u, v))
                
            # Create the conflicts graph
            self.conflicts = Graph(self.num_conflicts, conflicts_list)
    
    def get_num_conflicts(self):
        """Get the number of conflicts."""
        return self.num_conflicts
    
    def get_conflicts_graph(self):
        """Get the conflicts graph."""
        return self.conflicts