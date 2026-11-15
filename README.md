[TREEW_test_plan.md](https://github.com/user-attachments/files/34868824/TREEW_test_plan.md)
# Test Plan: TREEW Student Records Manager

**Author:** Treew  
**Project:** Student Records Manager  
**Version:** 1.0  
**Date:** 15 November 2026

## 1. Test Objective

The purpose of this test plan is to check that the Student Records Manager works correctly. The tests cover its six main features and input checks.

## 2. Test Data

These sample student records were used for testing:

| Student Name | Score |
|---|---:|
| Ani | 78 |
| Bima | 92 |
| Citra | 55 |

## 3. Test Cases and Results

| Test ID | Feature | Test Input or Action | Expected Result | Actual Result | Status |
|---|---|---|---|---|---|
| T01 | Add student | Add Ani with a score of 78. | Ani and the score 78 are saved in the program. | Worked as expected. | PASS |
| T02 | Check student score | Try to add a student with a score of 150. | The program rejects the score because it must be from 0 to 100. | Worked as expected. | PASS |
| T03 | View all students | Select option 2 after adding the sample students. | The program shows all student names and scores. | Worked as expected. | PASS |
| T04 | Search for a student | Search for Bima. | The program shows Bima's name and score of 92. | Worked as expected. | PASS |
| T05 | Search for a missing student | Search for a name that is not in the records. | The program shows "Student not found!" | Worked as expected. | PASS |
| T06 | Sort by score | Select option 4, then option 2. | The students appear from highest to lowest score: Bima, Ani, Citra. | Worked as expected. | PASS |
| T07 | View statistics | Select option 5 with the three sample students. | Average: 75.00, highest: 92, lowest: 55, passing: 2, failing: 1. | Worked as expected. | PASS |
| T08 | Remove a student | Remove Citra. | Citra's name and score are removed. | Worked as expected. | PASS |
| T09 | View records after removal | Select option 2 after removing Citra. | Only Ani and Bima remain. | Worked as expected. | PASS |
| T10 | Check menu input | Enter a letter instead of a menu number. | The program shows an invalid input message and returns to the menu. | Worked as expected. | PASS |
| T11 | Check empty records | View students or check statistics when there are no students. | The program says that no student records are available. | Worked as expected. | PASS |

## 4. Test Summary

- **Total test cases:** 11
- **Passed:** 11
- **Failed:** 0

All the features and input checks listed above worked as expected during testing.

## 5. Notes

The program keeps student records in vectors while it is running. The records are not saved permanently, so they are lost when the program closes.
