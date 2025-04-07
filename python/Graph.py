class Graph:
    def __init__(self, num_conflicts=0, conflicts=None):
        self.num_nodes = 0
        self.adj_list = []
        
        if conflicts:
            # Find the maximum node index to determine the number of nodes
            for u, v in conflicts:
                self.num_nodes = max(self.num_nodes, u, v)
            self.num_nodes += 1  # Adjust for 0-indexing
            
            # Initialize adjacency list
            self.adj_list = [[] for _ in range(self.num_nodes)]
            
            # Add all conflict edges
            for u, v in conflicts:
                self.add_edge(u, v)
    
    def add_edge(self, u, v):
        """Add an edge between nodes u and v."""
        self.adj_list[u].append(v)
        self.adj_list[v].append(u)
    
    def are_adjacent(self, u, v):
        """Check if nodes u and v are adjacent."""
        return v in self.adj_list[u]
    
    def add_conflict(self, item1, item2):
        """Add a conflict between two items if it doesn't exist."""
        if not self.are_adjacent(item1, item2):
            self.add_edge(item1, item2)
    
    def remove_conflict(self, item1, item2):
        """Remove a conflict between two items."""
        if item2 in self.adj_list[item1]:
            self.adj_list[item1].remove(item2)
        if item1 in self.adj_list[item2]:
            self.adj_list[item2].remove(item1)