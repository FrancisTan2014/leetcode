# A Systematic Test Case Methodology for LeetCode
## STEP 1 — Identify the key dimensions of the problem

Before writing tests, break the problem into dimensions that affect behavior.

Examples of dimensions:

Input size (small/large).

Shape/structure (sorted? duplicated? random?).

Special values (zero, negative, empty, null).

Graph/tree structure patterns.

Boundary conditions given by constraints.

Cases that trigger each “branch” of the algorithm.

This step ensures your tests cover the entire problem space.

---

## STEP 2 — Create a checklist of mandatory test categories

For almost all algorithmic problems, these categories apply:

1. Base cases

Empty input (if allowed)

Single-element input

Minimum constraints

2. Boundary cases

Values at the constraint limits, e.g.

0, 1, 10^5, 10^9

maximum input length

Structures just at the threshold (e.g., 2 nodes in a binary tree)

3. Typical cases

Normal “middle-of-the-road” inputs

Multiple elements with mixed behaviors

4. Edge behavior cases

Depending on the problem:

Arrays with all duplicates

Already sorted / reverse sorted

Graph with cycles / no cycles

Tree skewed to left or right

Strings with repeated patterns

5. Trick cases

Cases designed to break common mistakes:

Overflow risks

Off-by-one boundaries

Floating-point precision

Two identical optimal answers

Negative values or zeros

Solutions involving tie-breaking rules

6. Performance stress cases

These verify your algorithm meets time complexity:

Maximum size arrays

Worst-case graphs

Deep recursion trees (checking stack overflow)

Heavy string repetition

These are crucial when your own tests might not catch a TLE.

---

## STEP 3 — Translate the categories into concrete test input sets

Example: Problem Two Sum

Category	Test Case	Expected
Base	[1], target=1	no solution
Boundary	[0,4,3,0], target=0	[0,3]
Typical	[2,7,11,15], target=9	[0,1]
Duplicates	[3,3], target=6	[0,1]
Negative values	[-3,4,3,90], target=0	[0,2]
Large input	random array length = 10^5	valid solution
Trick	input that causes overflow if someone uses int sum = a + b in languages with overflow	correct behavior

Every problem can be tested this way.

--- 

## STEP 4 — Automate test execution

Create a test runner that:

Runs all test cases.

Compares the result against expected output.

Reports failures clearly.

Includes randomized generators if needed.

This ensures consistency as you modify or optimize your solution.

---

## STEP 5 — Add property-based tests (advanced but extremely powerful)

Instead of asserting one answer, define invariants that must always be true.

Example: Sorting algorithm

Output array must be non-decreasing.

Output must contain the same elements as input.

This catches many mistakes that example-based tests cannot.