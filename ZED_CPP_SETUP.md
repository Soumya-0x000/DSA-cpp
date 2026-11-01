# Running C++ in Zed (Windows): Problems and Fixes

## Setup

- Compiler: MinGW `g++` 6.3.0 at `C:\MinGW\bin\g++.exe`
- Zed runs task commands through **Windows PowerShell 5.1**
- Task file: `F:\Workings\DSA\.zed\tasks.json`
- Keymap file: `C:\Users\ASUS\AppData\Roaming\Zed\keymap.json`

## Final working config

`.zed/tasks.json`

```json
[
  {
    "label": "Build & Run C++",
    "command": "cd $ZED_DIRNAME; g++ -o $ZED_STEM $ZED_FILE; if ($?) { ./$ZED_STEM; Remove-Item $ZED_STEM.exe -ErrorAction SilentlyContinue }",
    "tags": ["cpp"]
  }
]
```

`keymap.json`

```json
[
  {
    "context": "Editor",
    "bindings": {
      "ctrl-shift-r": ["task::Spawn", { "task_name": "Build & Run C++" }]
    }
  }
]
```

To use it: click inside a `.cpp` file and press `Ctrl+Shift+R`.

---

## Problems we hit

### 1. `&&` is not a valid statement separator

- **Error:** `The token '&&' is not a valid statement separator in this version.`
- **Cause:** Zed runs the task through Windows PowerShell 5.1. `&&` only works in PowerShell 7+ and bash.
- **Fix:** Use `; if ($?) { ... }`. `$?` is true when the previous command succeeded, so the program runs only if compilation worked.

### 2. Task "failed" with exit code 1 / 97

- **Cause:** This wasn't a setup bug. `test.cpp` had `return 'a';` in `main()`. That returns 97 (the ASCII code of `a`), and any non-zero exit code counts as failure.
- **Fix:** Return `0` from `main()`.

### 3. `.exe` files left in the project (including the root folder)

- **Cause:** `g++ -o name` writes the binary to the current folder. Zed starts tasks in the project root, so the `.exe` landed in `F:\Workings\DSA\`.
- **Fix:** `cd $ZED_DIRNAME` first, so the build happens in the file's own folder. Then `Remove-Item $ZED_STEM.exe` deletes the binary after it runs.

### 4. Shortcut always ran the same file (the main issue)

- **Symptom:** `Ctrl+Shift+R` always ran whichever file was open when Zed started, even after switching to `sum.cpp`.
- **Real cause:** The keymap wrote the key as `ctrl+shift+r`. **Zed separates keys with hyphens (`ctrl-shift-r`)**. Zed silently ignored the invalid binding, with no error in the UI or the log. None of the keymap changes ever took effect. Whatever ran on that key was probably Zed's default behavior repeating the first task, still holding its first file.
- **Things tried that couldn't help** (the binding was never loaded):
  - `task::Rerun` instead of `task::Spawn`
  - Changing the keymap context from `Workspace` to `Editor`
  - `task::Rerun` with `reevaluate_context: true`
- **Fix:** Write the key as `ctrl-shift-r` and bind it to `task::Spawn` with `task_name`. Spawn reads `$ZED_FILE` from the open editor each time it runs.

## Lessons

- In Zed's `keymap.json`, keys are joined with `-`, e.g. `ctrl-shift-r`, `alt-t`.
- When a config change seems to do nothing, first check that the config is being loaded at all. Changing its values comes second.
- Tasks run in PowerShell 5.1 on Windows, so use PowerShell syntax (`;`, `if ($?)`), not bash syntax.
- Useful task variables: `$ZED_FILE` (full path), `$ZED_STEM` (file name without extension), `$ZED_DIRNAME` (the file's folder).
- Zed config files accept trailing commas, so removing them wasn't actually needed.
