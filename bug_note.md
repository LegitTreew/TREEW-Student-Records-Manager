[bug_note.md](https://github.com/user-attachments/files/34868981/bug_note.md)
# BUG REPORT
**TREEW Student Records Manager**

**Bug:** Student names with spaces were not read correctly.

### Description
When entering a name such as "John Smith", the program only read "John". This affected adding, searching, and removing students by their full names.

### Cause
The program used `cin >> name`, which stops reading at the first space.

### Fix
I changed the input to `getline(cin, name)` and handled the leftover newline using `cin.ignore()`.

### Result
The program can now read full names with spaces. The fix should be tested in Add, Search, and Remove before submission.

**Status:** Fixed in code, testing required.
