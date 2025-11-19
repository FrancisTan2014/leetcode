# Debugging Guide

## Quick Start - Just Press F5!

Debugging is now fully automatic. No typing, no configuration needed.

### Steps:
1. Open any test file (e.g., `test_0003-longest-substring-without-repeating-characters.cpp`)
2. **Click anywhere inside the test case** you want to debug (e.g., inside `TEST(LongestSubstring, Basic)`)
3. Set breakpoints if needed (click left of line numbers)
4. **Press F5**

That's it! The debugger will:
- ✅ Auto-detect the problem folder
- ✅ Auto-detect the test at your cursor
- ✅ Build with debug symbols
- ✅ Start debugging

### Example

```cpp
TEST(LongestSubstring, Basic) {  // ← Put your cursor anywhere in this test
    Solution s;
    string input = "abcabcbb";
    int output = s.lengthOfLongestSubstring(input);
    EXPECT_EQ(output, 3);  // ← Set breakpoint here
}
```

Press **F5** → Debugs only `LongestSubstring.Basic`

## Debug Controls

- **F5** - Continue
- **F10** - Step Over
- **F11** - Step Into  
- **Shift+F11** - Step Out
- **Shift+F5** - Stop
- **Ctrl+Shift+F5** - Restart

## Debug Multiple Tests

If you want to debug all tests in the current file:
1. Open the debug dropdown (top of debug panel)
2. Select "Debug All Tests in Current File"
3. Press F5

## How It Works

The debug system uses two helper scripts:
- `.vscode/get_problem_folder.sh` - Extracts problem folder from file path
- `.vscode/get_test_at_line.py` - Detects test name at cursor line

These run automatically when you press F5.

## Requirements

The extension "Tasks Shell Input" is required and should be auto-installed.
If not, install it manually: `augustocdias.tasks-shell-input`

## Troubleshooting

### "Cannot find executable"
Run: `make build-debug` or `cd build && cmake -DCMAKE_BUILD_TYPE=Debug .. && make`

### Wrong test is debugging
Make sure your cursor is **inside** the test function you want to debug, not just near it.

### Breakpoints not hit
Ensure you built with debug symbols (the preLaunchTask handles this automatically).

## C#-Style Debugging

This setup mimics C# debugging in Visual Studio:
- No manual configuration
- Cursor position matters
- Just press F5 and go
