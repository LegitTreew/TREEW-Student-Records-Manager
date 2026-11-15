[test_plan (1).txt](https://github.com/user-attachments/files/34868683/test_plan.1.txt)
+======================================================================+
|                                                                      |
|                 TREEW - STUDENT RECORDS MANAGER                     |
|                           TEST PLAN                                  |
|                                                                      |
+======================================================================+

  AUTHOR       Treew
  PROJECT      Student Records Manager
  VERSION      1.0
  DATE         15 November 2026


  01  TEST OBJECTIVE
  --------------------------------------------------------------------

  This test plan checks that the Student Records Manager works
  correctly. It covers the six main features and input validation.


  02  TEST DATA
  --------------------------------------------------------------------

  +----------------------+----------------+
  | STUDENT NAME         | SCORE          |
  +----------------------+----------------+
  | Ani                  | 78             |
  | Bima                 | 92             |
  | Citra                | 55             |
  +----------------------+----------------+


  03  TEST CASES AND RESULTS
  --------------------------------------------------------------------

  [ T01 ]  ADD STUDENT
  Input       Add Ani with a score of 78.
  Expected    Ani and the score 78 are stored.
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T02 ]  INVALID STUDENT SCORE
  Input       Try to add a student with a score of 150.
  Expected    The program rejects the score because it is outside
              the allowed range of 0 to 100.
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T03 ]  VIEW ALL STUDENTS
  Input       Select option 2 after adding the sample records.
  Expected    All registered student names and scores are displayed.
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T04 ]  SEARCH FOR AN EXISTING STUDENT
  Input       Search for Bima.
  Expected    Bima's record and score of 92 are displayed.
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T05 ]  SEARCH FOR A MISSING STUDENT
  Input       Search for a name that is not registered.
  Expected    The program displays "Student not found!"
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T06 ]  SORT STUDENTS BY SCORE
  Input       Select option 4 to sort, then option 2 to view the list.
  Expected    Students appear from highest to lowest:
              Bima (92), Ani (78), Citra (55).
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T07 ]  STUDENT STATISTICS
  Input       Select option 5 with the three sample records.
  Expected    Average: 75.00 | Highest: 92 | Lowest: 55
              Passing: 2 | Failing: 1
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T08 ]  REMOVE A STUDENT
  Input       Remove Citra.
  Expected    Citra's name and score are removed.
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T09 ]  VIEW RECORDS AFTER REMOVAL
  Input       Select option 2 after removing Citra.
  Expected    Only Ani and Bima remain in the list.
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T10 ]  INVALID MENU INPUT
  Input       Enter a letter instead of a menu number.
  Expected    The program displays an invalid-input message and
              returns to the menu.
  Actual      Worked as expected.
  Result      PASS

  ....................................................................

  [ T11 ]  EMPTY STUDENT RECORDS
  Input       View students or calculate statistics when no students
              are registered.
  Expected    The program displays a message that no records are
              available.
  Actual      Worked as expected.
  Result      PASS


  04  TEST SUMMARY
  --------------------------------------------------------------------

  +----------------------+----------------+
  | TOTAL TEST CASES     | 11             |
  | PASSED               | 11             |
  | FAILED               | 0              |
  +----------------------+----------------+

  All tested features and input-validation cases behaved as expected
  during testing.


  05  NOTES
  --------------------------------------------------------------------

  Student records are stored in vectors while the program is running.
  Records are not saved permanently and are lost when the program
  closes.


+======================================================================+
|                    END OF TREEW TEST PLAN                            |
+======================================================================+
