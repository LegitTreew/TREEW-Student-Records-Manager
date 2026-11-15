[test_plan (1).md](https://github.com/user-attachments/files/34868698/test_plan.1.md)
# Test Plan – TREEW Student Records Manager

**Author:** Treew  
**Project:** Student Records Manager  
**Version:** 1.0  
**Date:** 15 November 2026

## Test Objective

The purpose of this test plan is to check that the Student Records Manager works correctly, including its six main features and input validation.

## Test Data

The following sample records were used for testing:

| Student name | Score |
|---|---:|
| Ani | 78 |
| Bima | 92 |
| Citra | 55 |

## Test Cases and Results

| Test ID | Feature | Test input / action | Expected result | Actual result | Status |
|---|---|---|---|---|---|
| T01 | Add student | Add Ani with score 78 | Ani and 78 are stored | Worked as expected | PASS |
| T02 | Add student validation | Enter score 150 | The program rejects the score because it is outside 0–100 | Worked as expected | PASS |
| T03 | View all students | Select option 2 after adding the sample records | All student names and scores are displayed | Worked as expected | PASS |
| T04 | Search student | Search for Bima | Bima's record and score 92 are displayed | Worked as expected | PASS |
| T05 | Search missing student | Search for a name that is not registered | The program displays “Student not found!” | Worked as expected | PASS |
| T06 | Sort by score | Select option 4, then option 2 | Students are displayed from highest to lowest: Bima, Ani, Citra | Worked as expected | PASS |
| T07 | Statistics | Select option 5 with the three sample records | Average is 75.00, highest is 92, lowest is 55, passing is 2 and failing is 1 | Worked as expected | PASS |
| T08 | Remove student | Remove Citra | Citra's name and score are removed | Worked as expected | PASS |
| T09 | View after removal | Select option 2 after removing Citra | Only Ani and Bima remain | Worked as expected | PASS |
| T10 | Menu input validation | Enter a letter instead of a menu number | The program displays an invalid-input message and returns to the menu | Worked as expected | PASS |
| T11 | Empty records | View or calculate statistics when no students are registered | The program displays a message that no records are available | Worked as expected | PASS |

## Test Summary

- **Total test cases:** 11
- **Passed:** 11
- **Failed:** 0

All tested features and input-validation cases behaved as expected during testing.

## Notes

The program stores student records in vectors while it is running. Records are not saved permanently after the program closes.
