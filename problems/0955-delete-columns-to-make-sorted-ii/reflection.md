# LC 955 - Delete Columns to Make Sorted II: Learning Reflection

## Problem Context
Minimum columns to delete from string array to achieve lexicographic order. Constraint: can't physically delete (O(n²)), must track deletions.

## My Journey

### Initial Approach: Recursive (Failed ❌)
**What I tried:**
- Process first column, find equal pairs
- Recursively handle each equal pair range independently
- Mark deleted columns globally

**Why it failed:**
- **Sibling interference:** Recursion for rows 0-1 used col 1, but recursion for rows 2-3 deleted col 1 → first recursion's decision invalidated
- **Lost cross-context:** Each recursion didn't know about other row ranges
- **Fundamental issue:** Subproblems weren't independent - column deletions are global and affect all decisions

**Key lesson:** Recursion works when subproblems are independent. Here they're interdependent through shared columns.

### Breakthrough: Iterative with State Tracking ✓

**The core insight I was missing:**
> Once an adjacent pair is **determined** (found a column where row[i] < row[i+1]), we never need to check that pair again in future columns.

**The algorithm:**
```cpp
vector<bool> determined(n-1);  // Track which adjacent pairs are ordered

for each column:
    Check only UNDETERMINED pairs for violations
    If violation found → delete column
    Else → mark newly ordered pairs as determined
```

**What clicked:**
1. **State machine thinking:** Pairs have states: undetermined → determined (one-way, irreversible)
2. **The question that unlocked it:** "Does pair (1,2) need checking if they're already ordered by col 0?" → NO!
3. **Separation of concerns:** Global iteration + local state tracking, not recursive subdivision

### Bug I Hit: Two-Phase Commit 🐛

**First implementation:**
```cpp
for (int row = 0; row < rows - 1; row++) {
    if (!determined[row]) {
        if (strs[row][col] > strs[row+1][col]) {
            need_delete = true;
        } else if (strs[row][col] < strs[row+1][col]) {
            determined[row] = true;  // ❌ BUG: Mark WHILE checking
        }
    }
}
```

**The bug:** Marked pairs as determined even when the column gets deleted!

**The fix:** Two-phase approach
```cpp
// Phase 1: Check for violations
for (...) { if (violation) need_delete = true; }

// Phase 2: Only if keeping column, update state
if (!need_delete) {
    for (...) { if (ordered) determined[row] = true; }
}
```

**Why:** Deleted columns don't exist in final strings → can't provide ordering.

## Pattern Recognition Skills Developed

### 1. When to Use State Tracking
**Signal:** "Does what happened before affect what I do now?"
- If you think "wait, did I already check this?" → need state
- If decisions depend on history → state machine

### 2. Elegant Data Structure Choice
**Discovery process (honest version):**
1. First try: `map<pair<int,int>, bool>` for pairs
2. Notice: Iterating sequentially, keys are 0,1,2,3...
3. Realize: "I'm storing what I can compute" (pair identity = index)
4. Refactor: `vector<bool> determined(n-1)` where `determined[i]` = status of pair (i, i+1)

**The pattern:**
```
Adjacent pairs (i, i+1) → array[i]
Grid cells (r,c) → array[r][c]
Sequential relationships → natural indexing
```

**The test:** "Can I derive the object from its index?" → If yes, use array not map

### 3. Recognizing "Past Matters" Problems
**Greedy with state** vs **Pure greedy:**
- Pure greedy: Each decision is independent
- Greedy with state: Decisions depend on cumulative history
- This problem: Greedy iteration + state tracking of determined pairs

## Key Takeaways

1. ✅ **Start verbose, refactor ruthlessly** - Got it working first, then simplified
2. ✅ **State = What persists across iterations** - Determined pairs persist, everything else is transient
3. ✅ **Manual trace reveals patterns** - Tracing by hand showed "this pair is already ordered!"
4. ✅ **Two-phase commit for conditional updates** - Check validity, THEN commit changes
5. ✅ **Implicit > Explicit when there's natural indexing** - Adjacent pairs naturally map to array indices

## What I'll Remember Next Time

**When I see "adjacent pairs" in future:**
- Think: `vector<bool>(n-1)` where index i = pair (i, i+1)
- Don't store pairs explicitly

**When I see "depends on history":**
- Ask: "What state do I need to remember?"
- Build state machine: what states exist, what transitions are allowed?

**When greedy seems almost right but fails:**
- Ask: "Am I tracking what's already been decided?"
- Add state tracking for cumulative decisions

## Time Investment
- Initial recursive approach: Failed due to conceptual flaw
- Switch to iterative: Core algorithm correct
- Bug fix: Two-phase commit for state updates
- **All tests passing:** 26/26 ✓

## Complexity
- Time: O(rows × columns) - each cell checked at most once
- Space: O(rows) - for determined array
- Optimal for this problem

## Pattern Library Addition

**Pattern:** Greedy with adjacent pair state tracking
**Data structure:** Natural array indexing for implicit pair representation
**Key insight:** Track what's been determined, only check undetermined pairs
**Gotcha:** Don't commit state updates for deleted columns (two-phase commit)
