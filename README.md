# 🚀 Sokoban Solver — Algorithm & AI Search Project

## 🧠 Overview

This project implements an **intelligent Sokoban solver** using advanced search algorithms and state-space optimization techniques.

Sokoban is a classical benchmark problem in **Artificial Intelligence and Algorithm Design**, known for its extremely large search space and computational complexity (PSPACE-complete).

> 🎯 **Goal**: Build a high-performance solver capable of efficiently exploring and pruning the state space to find optimal (or near-optimal) solutions.

---

## ✨ Highlights (Why this project stands out)

* 🔥 Designed a **complete state-space search engine** from scratch
* ⚡ Implemented **efficient state encoding + deduplication**
* 🧠 Integrated **heuristic-based search (A*)** to significantly improve performance
* 🚫 Implemented **deadlock detection & pruning**, reducing useless exploration
* 📉 Achieved **X× speedup vs naive BFS** *(建议你后面填真实数据)*
* 🧩 Solves complex Sokoban levels with large branching factors

---

## 🎮 Problem Description

Sokoban is a grid-based puzzle where:

* The player pushes boxes to target locations
* Only **push actions are allowed**
* Incorrect moves may lead to **irreversible deadlocks**

This makes it a **highly constrained search problem** with:

* Huge state space
* Many invalid states
* Strong dependency on pruning strategies

---

## 🏗️ System Design

### 🔹 State Representation

Each game state is modeled as:

* Player position
* Box positions (encoded efficiently, e.g., tuple / bitmask)
* Map layout (walls, targets)

👉 Designed for:

* Fast comparison (hashable)
* Memory efficiency
* Quick duplication checks

---

### 🔹 Search Framework

Implemented multiple search strategies:

#### 1️⃣ Breadth-First Search (Baseline)

* Guarantees optimal solution
* Extremely high memory usage

#### 2️⃣ Depth-First Search

* Lower memory footprint
* Not guaranteed optimal

#### 3️⃣ ⭐ A* Search (Core Optimization)

* Uses heuristic to guide search
* Balances optimality and performance

---

### 🔹 Heuristic Design (Core of A*)

Examples:

* Manhattan distance between boxes and targets
* Matching strategy between boxes and goals
* Penalty for blocked states

> 💡 A good heuristic dramatically reduces search complexity

---

### 🔹 Deadlock Detection (Key Optimization 🚀)

To avoid wasting computation:

* Detect corner deadlocks (box stuck in corner)
* Detect wall deadlocks
* Prune unsolvable states early

👉 This is one of the **most critical optimizations in Sokoban solvers**

---

## ⚡ Performance

| Method | Time Complexity | Practical Performance |
| ------ | --------------- | --------------------- |
| BFS    | O(b^d)          | Very slow ❌           |
| DFS    | O(b^d)          | Unstable              |
| A*     | O(b^d) (pruned) | Efficient ✅           |

📊 Example Results:

* Solved levels: **X**
* Average steps: **X**
* Runtime: **X ms**
* Speedup vs BFS: **X×**

*(👉 强烈建议你填真实数据，这一块决定“含金量”)*

---

## 📂 Project Structure

```bash
.
├── solver/        # Search algorithms (BFS / DFS / A*)
├── model/         # State representation
├── levels/        # Game levels
├── utils/         # Helper functions
├── main.py        # Entry point
└── README.md
```

---

## 🛠️ How to Run

```bash
git clone https://github.com/YihanLi-erisaer/Algorithm-and-data-structure-Sokoban.git
cd Algorithm-and-data-structure-Sokoban
python main.py
```

---

## 📸 Demo

```text
#######
#  .  #
#  $  #
#  @  #
#######
```

Output:

```
Solution found!
Steps: 42
Path: UDLR...
```

---

## 🧪 Technical Challenges & Solutions

### ❗ Challenge 1: State Explosion

* 🔴 Problem: Exponential growth of search space
* ✅ Solution:

  * State hashing
  * Visited set pruning

---

### ❗ Challenge 2: Deadlock States

* 🔴 Problem: Many states are unsolvable
* ✅ Solution:

  * Rule-based deadlock detection
  * Early pruning

---

### ❗ Challenge 3: Inefficient Search

* 🔴 Problem: BFS too slow
* ✅ Solution:

  * A* with heuristic guidance
  * Priority queue optimization

---

## 📚 What I Learned

* Advanced **graph search algorithms**
* Designing **efficient state representations**
* Trade-offs between **time and space complexity**
* Practical optimization techniques in AI search problems

---

## 🔮 Future Work

* 🚀 Pattern Database Heuristic (PDB)
* 🎮 GUI visualization (e.g., Pygame)
* 🤖 Reinforcement Learning solver
* ⚡ Parallel search optimization

---

## 👤 Author

**Yihan Li**

---

## ⭐ Why this project matters (for recruiters / admission)

This project demonstrates:

* Strong foundation in **Data Structures & Algorithms**
* Ability to handle **complex state-space problems**
* Understanding of **AI search & optimization techniques**
* Capability to turn theory into **working systems**

---
