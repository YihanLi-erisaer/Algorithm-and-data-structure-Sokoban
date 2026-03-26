# Intelligent Solver for Sokoban: A State-Space Search Approach

## 1. Abstract
This project implements an automated solver for the classic NP-hard puzzle, **Sokoban**. By treating the game as a state-space traversal problem, the system employs various search strategies—ranging from uninformed Breadth-First Search (BFS) to informed A* Search. The primary objective is to find an optimal (or near-optimal) sequence of moves to transition the system from an initial configuration to a predefined goal state while navigating environmental constraints and avoiding irreversible deadlocks.

## 2. Problem Formulation

In a formal computational context, the Sokoban puzzle is defined by:
* **State ($S$):** A tuple $(P, B)$, where $P$ represents the coordinates of the player and $B$ is the set of coordinates for all boxes.
* **Initial State ($S_0$):** The starting layout of the grid, boxes, and player.
* **Goal State ($G$):** A configuration where every box in $B$ is positioned on a target storage location.
* **Transition Model ($T$):** Valid moves (Up, Down, Left, Right) that obey wall constraints and box-pushing mechanics.



## 3. Algorithmic Implementation

### 3.1 Search Strategies
The project compares multiple paradigms of pathfinding:
* **Uninformed Search (BFS):** Guarantees the shortest path in terms of moves by expanding nodes layer-by-layer. However, it suffers from exponential space complexity $O(b^d)$.
* **Informed Search (A*):** Utilizes a cost function $f(n) = g(n) + h(n)$ to prioritize node expansion, where $g(n)$ is the path cost and $h(n)$ is the heuristic estimate.

### 3.2 Heuristic Function Design
To optimize the A* search, we implemented several heuristic estimators:
1.  **Manhattan Distance Sum:** The cumulative distance from each box to its nearest storage target.
2.  **Minimum Matching Lower Bound:** A more complex approach using bipartite matching to assign boxes to targets uniquely, minimizing the total distance.

### 3.3 Deadlock Detection Logic
To prune the search tree effectively, the solver identifies "Deadlock States"—configurations from which the goal state is unreachable:
* **Corner Deadlocks:** A box pushed into a non-target corner.
* **Line Deadlocks:** Boxes pushed against a wall where no target exists or movement is restricted.

---

## 4. Task 6: Performance Evaluation & Results

In **Task 6**, we conducted a comparative analysis of the implemented algorithms across levels of varying complexity.

### 4.1 Computational Efficiency
The performance is measured using the following metrics:
* **Node Expansion:** Total number of states explored before reaching the goal.
* **Temporal Complexity:** Execution time (latency) per level.
* **Path Optimality:** The total number of steps in the generated solution.

| Algorithm | Avg. Nodes Expanded | Avg. Execution Time (ms) | Path Length |
| :--- | :--- | :--- | :--- |
| **BFS** | High | High | Optimal |
| **DFS** | High | Medium | Sub-optimal |
| **A* (Manhattan)** | Low | Low | Optimal |

### 4.2 Impact of Heuristics (Task 6 Insight)
Our empirical data from Task 6 demonstrates that the **A* Search with Deadlock Pruning** reduces the search space by over **[X]%** compared to naive BFS. The analysis confirms that while $O(2^n)$ complexity is inherent to Sokoban, effective heuristics significantly shift the "tractability frontier," allowing the solver to handle larger grids within reasonable memory limits.

---

## 5. Data Structures

The efficiency of the solver is underpinned by high-performance data structures:
* **Hash Maps (Visited Sets):** Used to store previously explored states to prevent infinite loops and redundant computation.
* **Priority Queues (Min-Heaps):** Facilitates $O(\log n)$ retrieval of the lowest-cost node in A* search.
* **Bitmasking/Coordinate Mapping:** Optimized representation of the 2D grid to minimize memory footprint during state storage.

## 6. Setup and Execution

### Requirements
* Python 3.x
* (Optional) Pygame for GUI visualization

### Installation
```bash
git clone https://github.com/YihanLi-erisaer/Algorithm-and-data-structure-Sokoban.git
cd Algorithm-and-data-structure-Sokoban
```

### Running the Solver
To execute the solver and view the performance report (Task 6):
```bash
python solver.py --algorithm astar --level 1
```

## 7. Conclusion
This project illustrates the application of classical AI search techniques to complex puzzle-solving. Through the rigorous analysis in Task 6, we demonstrate that informed search, coupled with domain-specific deadlock detection, provides a robust framework for solving PSPACE-complete problems like Sokoban.
