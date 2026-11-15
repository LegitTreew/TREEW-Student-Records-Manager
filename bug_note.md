# BUG REPORT
**TREEW Student Records Manager**

**Bug Title:** Student Names With Spaces Not Being Read Correctly

### 1. Description
During testing, I found that the program could not correctly read student names containing spaces. For example, entering "John Smith" only saved the first name.

### 2. Cause
The program used `cin >> name`, which reads input only until the first space.

### 3. Solution
The input method needs to be changed to `getline()` so the program can read the student's full name.

### 4. Expected Result
The program should correctly accept and store full names, including spaces.

### 5. Status
Pending implementation and testing.
