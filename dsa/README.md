# DSA study guide: UCSD Data Structures and Algorithms

This repo follows the [UCSD Data Structures and Algorithms](https://www.coursera.org/specializations/data-structures-algorithms) specialization, with extra practice on LeetCode and CSES. It is part of my study plan (see `about.md`).

**When:** Tuesday evening, 21:00–22:15.
**Why:** coding interviews for quant developer jobs, and the HKU application portfolio.
**Language:** C++ for every assignment and problem.

## How to use one Tuesday session

1. **45 minutes:** the next video or programming assignment in the current course.
2. **30 minutes:** one practice problem from the current module's list below.
3. **Last 2 minutes:** tick what you finished and write the next step at the bottom of this file.

A problem counts as done when you solved it **without looking at a solution**. If you needed a hint, mark it `[h]` and solve it again two weeks later.

## The order

| Step | Course | Status |
| --- | --- | --- |
| 1 | Algorithmic Toolbox | **Now** (grade 19%) |
| 2 | Data Structures | Next |
| 3 | Algorithms on Graphs | Optional |
| — | Algorithms on Strings, Advanced Algorithms, Genome Assembly | Dropped from the plan |

After step 2 (or 3), Tuesday becomes interview practice (see the end of this file).

---

## Step 1: Algorithmic Toolbox

**You learn:** how to analyse running time (big-O), and four ways to design an algorithm: greedy, divide and conquer, sorting, and dynamic programming.
**Done when:** every programming assignment passes in C++, and every problem below is ticked.

### Module 1–2: programming challenges, algorithmic warm-up

How to test your solution (stress testing), and why a slow correct algorithm is not enough.

- [ ] [LeetCode 70. Climbing Stairs](https://leetcode.com/problems/climbing-stairs/) (Easy)
- [ ] [LeetCode 704. Binary Search](https://leetcode.com/problems/binary-search/) (Easy)

### Module 3: greedy algorithms

When taking the best choice now gives the best answer overall, and how to prove it.

- [ ] [LeetCode 55. Jump Game](https://leetcode.com/problems/jump-game/) (Medium)
- [ ] [LeetCode 435. Non-overlapping Intervals](https://leetcode.com/problems/non-overlapping-intervals/) (Medium)
- [ ] CSES: Movie Festival

### Module 4: divide and conquer, sorting

Split the problem, solve the parts, combine. Binary search, merge sort, quicksort.

- [ ] [LeetCode 169. Majority Element](https://leetcode.com/problems/majority-element/) (Easy)
- [ ] [LeetCode 34. Find First and Last Position of Element in Sorted Array](https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/) (Medium)
- [ ] CSES: Distinct Numbers

### Module 5–6: dynamic programming

Break a problem into overlapping subproblems and store their answers.

- [ ] [LeetCode 322. Coin Change](https://leetcode.com/problems/coin-change/) (Medium)
- [ ] [LeetCode 72. Edit Distance](https://leetcode.com/problems/edit-distance/) (Medium)
- [ ] CSES: Minimizing Coins
- [ ] CSES: Book Shop (knapsack)

### Interview extras (not taught in the course)

Common interview techniques. Do these after the course modules.

- [ ] Two pointers: [LeetCode 26. Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/) (Easy)
- [ ] Two pointers: [LeetCode 11. Container With Most Water](https://leetcode.com/problems/container-with-most-water/) (Medium)
- [ ] Prefix sum: [LeetCode 560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/) (Medium)
- [ ] Binary search on the answer: [LeetCode 875. Koko Eating Bananas](https://leetcode.com/problems/koko-eating-bananas/) (Medium)

---

## Step 2: Data Structures

**You learn:** how the basic data structures work inside, and what each operation costs.
**Done when:** every programming assignment passes in C++, and every problem below is ticked.

### Arrays, linked lists, stacks, queues, trees

- [ ] [LeetCode 20. Valid Parentheses](https://leetcode.com/problems/valid-parentheses/) (Easy)
- [ ] [LeetCode 155. Min Stack](https://leetcode.com/problems/min-stack/) (Medium)
- [ ] [LeetCode 104. Maximum Depth of Binary Tree](https://leetcode.com/problems/maximum-depth-of-binary-tree/) (Easy)
- [ ] [LeetCode 102. Binary Tree Level Order Traversal](https://leetcode.com/problems/binary-tree-level-order-traversal/) (Medium)

### Dynamic arrays and amortised analysis

Why `std::vector::push_back` is fast on average, and why blustone still forbids it on the hot path.

- [ ] Explain in your own words, in English, at the bottom of this file. (Also writing practice.)

### Priority queues (heaps) and disjoint sets

- [ ] [LeetCode 215. Kth Largest Element in an Array](https://leetcode.com/problems/kth-largest-element-in-an-array/) (Medium)
- [ ] [LeetCode 547. Number of Provinces](https://leetcode.com/problems/number-of-provinces/) (Medium, disjoint set)
- [ ] CSES: Room Allocation

### Hash tables

- [ ] [LeetCode 1. Two Sum](https://leetcode.com/problems/two-sum/) (Easy)
- [ ] [LeetCode 128. Longest Consecutive Sequence](https://leetcode.com/problems/longest-consecutive-sequence/) (Medium)

### Binary search trees, balanced trees (AVL, splay)

- [ ] [LeetCode 98. Validate Binary Search Tree](https://leetcode.com/problems/validate-binary-search-tree/) (Medium)
- [ ] [LeetCode 236. Lowest Common Ancestor of a Binary Tree](https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/) (Medium)
- [ ] CSES: Concert Tickets (uses a balanced tree: `std::multiset`)

---

## Step 3 (optional): Algorithms on Graphs

**You learn:** how to model problems as graphs, explore them, and find shortest paths and spanning trees.

### Exploring graphs: DFS, connected components

- [ ] [LeetCode 200. Number of Islands](https://leetcode.com/problems/number-of-islands/) (Medium)
- [ ] CSES: Counting Rooms
- [ ] CSES: Building Roads

### Directed graphs: topological sort, strongly connected components

- [ ] [LeetCode 207. Course Schedule](https://leetcode.com/problems/course-schedule/) (Medium)
- [ ] [LeetCode 210. Course Schedule II](https://leetcode.com/problems/course-schedule-ii/) (Medium)
- [ ] CSES: Planets and Kingdoms (strongly connected components)

### Shortest paths: BFS, Dijkstra, Bellman-Ford

- [ ] CSES: Message Route (BFS)
- [ ] [LeetCode 743. Network Delay Time](https://leetcode.com/problems/network-delay-time/) (Medium, Dijkstra)
- [ ] [LeetCode 787. Cheapest Flights Within K Stops](https://leetcode.com/problems/cheapest-flights-within-k-stops/) (Medium, Bellman-Ford style)

### Minimum spanning trees

- [ ] [LeetCode 1584. Min Cost to Connect All Points](https://leetcode.com/problems/min-cost-to-connect-all-points/) (Medium)
- [ ] CSES: Road Reparation

---

## After the courses: interview practice

Tuesday becomes mixed practice:

- [ ] One timed problem per session: 30 minutes, then read the best solution.
- [ ] [Combinatorics and Probability](https://www.coursera.org/learn/combinatorics/home/welcome) (Discrete Mathematics, course 2).
- [ ] *A Practical Guide to Quantitative Finance Interviews* (Zhou): probability puzzles.
- [ ] Every two weeks: explain your solution out loud, in English, as in a real interview.

## Rules

- Keep solutions to **graded Coursera assignments private**. Coursera's Honor Code does not allow sharing them. LeetCode and CSES solutions are fine to publish.
- One course at a time. Don't start Step 2 until Step 1 is done.
- Codeforces contests are extra, outside the plan, and never replace a Tuesday session.

## Next step

<!-- Write the next concrete step here at the end of each session. -->
