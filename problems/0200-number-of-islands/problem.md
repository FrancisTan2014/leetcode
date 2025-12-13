# 200. Number of Islands

Given an `m x n` 2D binary grid `grid` which represents a map of `'1'`s (land) and `'0'`s (water), return the number of islands.

An **island** is surrounded by water and is formed by connecting adjacent lands **horizontally or vertically**. You may assume all four edges of the grid are surrounded by water.

## Examples

### Example 1
Input:
```
grid = [
	["1","1","1","1","0"],
	["1","1","0","1","0"],
	["1","1","0","0","0"],
	["0","0","0","0","0"]
]
```
Output:
```
1
```

### Example 2
Input:
```
grid = [
	["1","1","0","0","0"],
	["1","1","0","0","0"],
	["0","0","1","0","0"],
	["0","0","0","1","1"]
]
```
Output:
```
3
```

## Constraints

- `m == grid.size()`
- `n == grid[i].size()`
- `1 <= m, n <= 300`
- `grid[i][j]` is `'0'` or `'1'`.

## Notes

- Adjacency is **4-directional** (up, down, left, right), not diagonal.
- Many solutions mutate the grid to mark visited cells; if you prefer not to modify input, make a copy.
