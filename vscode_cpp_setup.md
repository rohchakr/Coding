1. Install `C/C++ Extension Pack` by `Microsoft`
2. Run `main.cpp` that will generate `.vscode/tasks.json`
3. Add `"-DLOCAL_JUDGE"` in `args` section in `tasks.json`
4. Add the following just after start of `main` function

```C++
#ifdef LOCAL_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
#endif
```
