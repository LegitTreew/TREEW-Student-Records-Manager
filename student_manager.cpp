/*
████████╗██████╗ ███████╗███████╗██╗    ██╗
╚══██╔══╝██╔══██╗██╔════╝██╔════╝██║    ██║
   ██║   ██████╔╝█████╗  █████╗  ██║ █╗ ██║
   ██║   ██╔══██╗██╔══╝  ██╔══╝  ██║███╗██║
   ██║   ██║  ██║███████╗███████╗╚███╔███╔╝
   ╚═╝   ╚═╝  ╚══════╝╚══════╝ ╚══╝╚══╝

          STUDENT RECORDS MANAGER
          -----------------------
          Author  : Treew & Cello
          Version : 1.0
          Date    : 15 November 2026

   Description:
   A simple program to manage student names and scores.
   Users can add, view, search, sort and remove students.
   The program can also calculate student statistics.
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

// Passing score
const int PASS_MARK = 60;

// Display the main menu
void showMenu() {
    cout << "\n";
    cout << "*******************************************************\n";
    cout << "*                                                     *\n";
    cout << "*              STUDENT RECORDS MANAGER                *\n";
    cout << "*                    Version 1.0                      *\n";
    cout << "*                                                     *\n";
    cout << "*******************************************************\n";

    cout << "\n";
    cout << "   [1] Add Student\n";
    cout << "   [2] View All Students\n";
    cout << "   [3] Search Student\n";
    cout << "   [4] Sort by Score\n";
    cout << "   [5] Statistics\n";
    cout << "   [6] Remove Student\n";
    cout << "   [0] Exit\n";

    cout << "\n-------------------------------------------------------\n";
    cout << "   Enter your choice: ";
}

// Check if a score is between 0 and 100
bool isValidScore(int score) {
    return score >= 0 && score <= 100;
}

// Add a new student and their score
void addStudent(vector<string>& names, vector<int>& scores) {
    string name;
    int score;

    cout << "\n========== ADD STUDENT ==========\n";
    cout << "Enter student name: ";
    cin >> name;

    cout << "Enter student score (0-100): ";

    if (!(cin >> score)) {
        cout << "Invalid input! Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (!isValidScore(score)) {
        cout << "Invalid score! Score must be between 0 and 100.\n";
        return;
    }

    // Add the name and score together
    names.push_back(name);
    scores.push_back(score);

    cout << "\nStudent added successfully!\n";
    cout << "Name  : " << name << "\n";
    cout << "Score : " << score << "\n";
}

// Display all student records
void viewAll(const vector<string>& names, const vector<int>& scores) {
    cout << "\n========== ALL STUDENTS ==========\n";

    if (names.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << left << setw(8) << "No."
         << setw(20) << "Name"
         << "Score\n";

    cout << "----------------------------------------\n";

    for (size_t i = 0; i < names.size(); i++) {
        cout << left << setw(8) << i + 1
             << setw(20) << names[i]
             << scores[i] << "\n";
    }

    cout << "----------------------------------------\n";
    cout << "Total students: " << names.size() << "\n";
}

// Find a student by name; return -1 if not found
int findByName(const vector<string>& names, const string& target) {
    for (size_t i = 0; i < names.size(); i++) {
        if (names[i] == target) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

// Search for and display a student's record
void searchStudent(const vector<string>& names, const vector<int>& scores) {
    string name;

    cout << "\n========== SEARCH STUDENT ==========\n";
    cout << "Enter student name: ";
    cin >> name;

    int index = findByName(names, name);

    if (index == -1) {
        cout << "\nStudent not found!\n";
        return;
    }

    cout << "\nStudent found!\n";
    cout << "Name  : " << names[index] << "\n";
    cout << "Score : " << scores[index] << "\n";

    if (scores[index] >= PASS_MARK) {
        cout << "Status: PASS\n";
    } else {
        cout << "Status: FAIL\n";
    }
}

// Sort students from highest to lowest using bubble sort
void sortByScoreDescending(vector<string>& names, vector<int>& scores) {
    int size = static_cast<int>(names.size());

    if (size == 0) {
        cout << "\nNo students to sort.\n";
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                // Swap the scores
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                // Swap the names so they stay matched with their scores
                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }

    cout << "\nStudents sorted successfully!\n";
}

// Calculate the average student score
double computeAverage(const vector<int>& scores) {
    int total = 0;

    for (size_t i = 0; i < scores.size(); i++) {
        total += scores[i];
    }

    return static_cast<double>(total) / scores.size();
}

// Find the highest student score
int findHighest(const vector<int>& scores) {
    int highest = scores[0];

    for (size_t i = 1; i < scores.size(); i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
    }

    return highest;
}

// Find the lowest student score
int findLowest(const vector<int>& scores) {
    int lowest = scores[0];

    for (size_t i = 1; i < scores.size(); i++) {
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
    }

    return lowest;
}

// Count students with scores of 60 or higher
int countPassing(const vector<int>& scores) {
    int total = 0;

    for (size_t i = 0; i < scores.size(); i++) {
        if (scores[i] >= PASS_MARK) {
            total++;
        }
    }

    return total;
}

// Display student score statistics
void showStatistics(const vector<int>& scores) {
    cout << "\n========== STUDENT STATISTICS ==========\n";

    if (scores.empty()) {
        cout << "No student records available.\n";
        return;
    }

    int passing = countPassing(scores);
    int failing = static_cast<int>(scores.size()) - passing;

    cout << fixed << setprecision(2);
    cout << "Total Students : " << scores.size() << "\n";
    cout << "Average Score  : " << computeAverage(scores) << "\n";
    cout << "Highest Score  : " << findHighest(scores) << "\n";
    cout << "Lowest Score   : " << findLowest(scores) << "\n";
    cout << "Passing        : " << passing << "\n";
    cout << "Failing        : " << failing << "\n";
    cout << "=========================================\n";
}

// Find and remove a student by name
void removeStudent(vector<string>& names, vector<int>& scores) {
    string name;

    cout << "\n========== REMOVE STUDENT ==========\n";
    cout << "Enter student name: ";
    cin >> name;

    int index = findByName(names, name);

    if (index == -1) {
        cout << "\nStudent not found!\n";
        return;
    }

    // Remove the name and score at the same index
    names.erase(names.begin() + index);
    scores.erase(scores.begin() + index);

    cout << "\nStudent removed successfully!\n";
}

int main() {
    // Store student names and scores
    vector<string> names;
    vector<int> scores;

    int choice;

    // Welcome screen
    cout << "\n";
    cout << "*******************************************************\n";
    cout << "*                                                     *\n";
    cout << "*                  WELCOME TO TREEW                   *\n";
    cout << "*              STUDENT RECORDS MANAGER                *\n";
    cout << "*                                                     *\n";
    cout << "*******************************************************\n";

    // Keep showing the menu until the user chooses 0
    do {
        showMenu();

        // Check if the menu input is a number
        if (!(cin >> choice)) {
            cout << "\nInvalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
            continue;
        }

        // Perform the selected menu option
        switch (choice) {
            case 1:
                addStudent(names, scores);
                break;

            case 2:
                viewAll(names, scores);
                break;

            case 3:
                searchStudent(names, scores);
                break;

            case 4:
                sortByScoreDescending(names, scores);
                break;

            case 5:
                showStatistics(scores);
                break;

            case 6:
                removeStudent(names, scores);
                break;

            case 0:
                cout << "\nThank you for using TREEW Student Records Manager!\n";
                cout << "Goodbye!\n";
                break;

            default:
                cout << "\nInvalid choice! Please select 0-6.\n";
        }

    } while (choice != 0);

    return 0;
}
