Paths() = Paths from right + Paths from down
Paths(x, y) = Paths(x, y + 1) + Paths(x + 1, y)

n X n grid

Paths(n, n) = 0;

```
for (int i = n; i >= 1; i--) {
    for (int j = n; j >= 1; j--) {
        numPaths[i][j] = 0;

        // base case
        if (i == n && j == n) {
            continue;
        }
        
        if (grid[i][j] != TRAP) {
            if (i + 1 <= n)
                numPaths[i][j] += numPaths[i + 1][j];
            if (j + 1 <= n)
                numPaths[i][j] += numPaths[i][j + 1];
        }
    }
}

return numPaths[1][1];
```

What if the target square itself is a trap?