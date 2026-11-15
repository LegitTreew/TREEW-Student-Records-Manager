# Test Plan: TREEW Student Records Manager

**Author:** Treew  
**Project:** Student Records Manager  
**Version:** 1.0  
**Date:** 15 November 2026

## 1. Test Objective

The purpose of this test plan is to check that the Student Records Manager works correctly. The tests cover its six main features, input validation, and student names containing spaces.

## 2. Test Data

The following sample student records were used for testing:

| Student Name | Score |
|---|---:|
| Ani | 78 |
| Bima | 92 |
| Citra | 55 |
| John Smith | 85 |

## 3. Test Cases and Results

| Test ID | Feature | Test Input or Action | Expected Result | Actual Result | Status |
|---|---|---|---|---|---|
| T01 | Add student | Add Ani with a score of 78. | Ani and the score 78 are saved. | Worked as expected. | PASS |
| T02 | Check score validation | Try to add a student with a score of 150. | The program rejects the score because it must be from 0 to 100. | Worked as expected. | PASS |
| T03 | View all students | Select option 2 after adding the sample students. | The program shows all student names and scores. | Worked as expected. | PASS |
| T04 | Search for a student | Search for Bima. | The program shows Bima's name and score of 92. | Worked as expected. | PASS |
| T05 | Search for a missing student | Search for a name that is not in the records. | The program shows "Student not found." | Worked as expected. | PASS |
| T06 | Sort by score | Select option 4, then option 2. | Students appear from highest to lowest: Bima, Ani, Citra. | Worked as expected. | PASS |
| T07 | View statistics | Select option 5 with the three sample students. | Average: 75.00, highest: 92, lowest: 55, passing: 2, failing: 1. | Worked as expected. | PASS |
| T08 | Remove a student | Remove Citra. | Citra's name and score are removed. | Worked as expected. | PASS |
| T09 | View records after removal | Select option 2 after removing Citra. | Only Ani and Bima remain. | Worked as expected. | PASS |
| T10 | Check menu input | Enter a letter instead of a menu number. | The program shows an invalid input message and returns to the menu. | Worked as expected. | PASS |
| T11 | Check empty records | View students or check statistics when there are no students. | The program says that no student records are available. | Worked as expected. | PASS |
| T12 | Add a full name | Add John Smith with a score of 85. | The complete name "John Smith" and score 85 are saved. | Worked as expected. | PASS |
| T13 | Search using a full name | Search for John Smith. | The program finds and displays the complete name and score. | Worked as expected. | PASS |
| T14 | Remove using a full name | Remove John Smith. | The program finds and removes the complete matching name. | Worked as expected. | PASS |

## 4. Test Summary

- **Total test cases:** 14
- **Passed:** 14
- **Failed:** 0

All features and input checks listed above worked as expected during testing.

## 5. Notes

The program keeps student records in vectors while it is running. The records are not saved permanently, so they are lost when the program closes.
