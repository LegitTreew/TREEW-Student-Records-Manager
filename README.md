TREEW - STUDENT RECORDS MANAGER
TEST PLAN
============================================================

Author  : Treew
Project : Student Records Manager
Version : 1.0
Date    : 15 November 2026

1. TEST OBJECTIVE
------------------------------------------------------------
The purpose of this test plan is to check that the Student
Records Manager works correctly. The tests cover the six
main features and input validation.

2. TEST DATA
------------------------------------------------------------
The following sample student records were used:

    Student name       Score
    -------------------------
    Ani                 78
    Bima                92
    Citra               55

3. TEST CASES AND RESULTS
------------------------------------------------------------

TEST T01 - Add Student
Input / Action:
    Add Ani with a score of 78.
Expected Result:
    Ani and the score 78 are stored.
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T02 - Invalid Student Score
Input / Action:
    Try to add a student with a score of 150.
Expected Result:
    The program rejects the score because it is outside
    the allowed range of 0 to 100.
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T03 - View All Students
Input / Action:
    Select option 2 after adding the sample records.
Expected Result:
    All registered student names and scores are displayed.
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T04 - Search for an Existing Student
Input / Action:
    Search for Bima.
Expected Result:
    Bima's record and score of 92 are displayed.
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T05 - Search for a Missing Student
Input / Action:
    Search for a name that is not registered.
Expected Result:
    The program displays "Student not found!"
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T06 - Sort Students by Score
Input / Action:
    Select option 4 to sort, then option 2 to view the list.
Expected Result:
    Students appear from highest to lowest score:
    Bima (92), Ani (78), Citra (55).
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T07 - Student Statistics
Input / Action:
    Select option 5 with the three sample records.
Expected Result:
    Average score: 75.00
    Highest score: 92
    Lowest score : 55
    Passing       : 2
    Failing       : 1
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T08 - Remove a Student
Input / Action:
    Remove Citra.
Expected Result:
    Citra's name and score are removed.
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T09 - View Records After Removal
Input / Action:
    Select option 2 after removing Citra.
Expected Result:
    Only Ani and Bima remain in the list.
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T10 - Invalid Menu Input
Input / Action:
    Enter a letter instead of a menu number.
Expected Result:
    The program displays an invalid-input message and
    returns to the menu.
Actual Result:
    Worked as expected.
Status: PASS

............................................................

TEST T11 - Empty Student Records
Input / Action:
    View students or calculate statistics when no students
    are registered.
Expected Result:
    The program displays a message that no records are
    available.
Actual Result:
    Worked as expected.
Status: PASS

4. TEST SUMMARY
------------------------------------------------------------
Total test cases : 11
Passed           : 11
Failed           : 0

All tested features and input-validation cases behaved as
expected during testing.

5. NOTES
------------------------------------------------------------
Student records are stored in vectors while the program is
running. The records are not saved permanently, so they are
lost when the program closes.

============================================================
End of Test Plan
