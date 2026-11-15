/*
    ████████╗██████╗ ███████╗███████╗██╗    ██╗
    ╚══██╔══╝██╔══██╗██╔════╝██╔════╝██║    ██║
       ██║   ██████╔╝█████╗  █████╗  ██║ █╗ ██║
       ██║   ██╔══██╗██╔══╝  ██╔══╝  ██║███╗██║
       ██║   ██║  ██║███████╗███████╗╚███╔███╔╝
       ╚═╝   ╚═╝  ╚══════╝╚══════╝ ╚══╝╚══╝

              STUDENT RECORDS MANAGER
              -----------------------
              Author  : Treew
              Version : 1.0
              Date    : 15 November 2026
*/

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

const int PASS_MARK = 60;

// Display the TREEW welcome banner
void showBanner() {
    cout << "\n";
    cout << "****************************************************\n";
    cout << "*                                                  *\n";
    cout << "*                    TREEW                         *\n";
    cout << "*                                                  *\n";
    cout << "*             STUDENT RECORDS MANAGER              *\n";
    cout << "*                    Version 1.0                   *\n";
    cout << "*                                                  *\n";
    cout << "****************************************************\n";
}

// Read a complete name, including spaces
string readFullName() {
    string name;
    getline(cin >> ws, name);
    return name;
}

// Display the main menu
void showMenu() {
    cout << "\n";
    cout << "-------------------- MAIN MENU --------------------\n";
    cout << "\n";
    cout << "  [1] Add Student\n";
    cout << "  [2] View All Students\n";
    cout << "  [3] Search Student\n";
    cout << "  [4] Sort by Score\n";
    cout << "  [5] Statistics\n";
    cout << "  [6] Remove Student\n";
    cout << "  [0] Exit\n";
    cout << "\n---------------------------------------------------\n";
    cout << "  Enter your choice: ";
}

// Check whether a score is between 0 and 100
bool isValidScore(int score) {
    return score >= 0 && score <= 100;
}

// Add a new student
void addStudent(vector<string>& names, vector<int>& scores) {
    cout << "\n==================== ADD STUDENT ====================\n";
    cout << "Enter student name: ";

    string name = readFullName();

    if (name.empty()) {
        cout << "Name cannot be empty.\n";
        return;
    }

    int score;
    cout << "Enter student score (0-100): ";

    if (!(cin >> score)) {
        cout << "Invalid input! Please enter a number.\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return;
    }

    if (!isValidScore(score)) {
        cout << "Invalid score! Enter a score between 0 and 100.\n";
        return;
    }

    names.push_back(name);
    scores.push_back(score);

    cout << "\nStudent added successfully!\n";
    cout << "Name  : " << name << "\n";
    cout << "Score : " << score << "\n";
}

// Display all student records
void viewAll(const vector<string>& names, const vector<int>& scores) {
    cout << "\n================== ALL STUDENTS ==================\n";

    if (names.empty()) {
        cout << "No student records found.\n";
        return;
    }

    cout << left << setw(8) << "No."
         << setw(25) << "Name"
         << "Score\n";
    cout << "---------------------------------------------------\n";

    for (size_t i = 0; i < names.size(); i++) {
        cout << left << setw(8) << i + 1
             << setw(25) << names[i]
             << scores[i] << "\n";
    }

    cout << "---------------------------------------------------\n";
    cout << "Total students: " << names.size() << "\n";
}

// Find a student by their complete name
int findByName(const vector<string>& names, const string& target) {
    for (size_t i = 0; i < names.size(); i++) {
        if (names[i] == target) {
            return static_cast<int>(i);
        }
    }

    return -1;
}

// Search for a student by full name
void searchStudent(const vector<string>& names, const vector<int>& scores) {
    cout << "\n================== SEARCH STUDENT ==================\n";
    cout << "Enter student name: ";

    string name = readFullName();
    int index = findByName(names, name);

    if (index == -1) {
        cout << "\nStudent not found.\n";
        return;
    }

    cout << "\nStudent found!\n";
    cout << "Name  : " << names[index] << "\n";
    cout << "Score : " << scores[index] << "\n";
    cout << "Status: "
         << (scores[index] >= PASS_MARK ? "PASS" : "FAIL") << "\n";
}

// Sort students from highest to lowest using Bubble Sort
void sortByScoreDescending(vector<string>& names, vector<int>& scores) {
    int size = static_cast<int>(scores.size());

    if (size == 0) {
        cout << "\nNo students to sort.\n";
        return;
    }

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (scores[j] < scores[j + 1]) {
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }

    cout << "\nStudents sorted successfully!\n";
}

// Calculate the average score
double computeAverage(const vector<int>& scores) {
    int total = 0;

    for (int score : scores) {
        total += score;
    }

    return static_cast<double>(total) / scores.size();
}

// Find the highest score
int findHighest(const vector<int>& scores) {
    int highest = scores[0];

    for (int score : scores) {
        if (score > highest) {
            highest = score;
        }
    }

    return highest;
}

// Find the lowest score
int findLowest(const vector<int>& scores) {
    int lowest = scores[0];

    for (int score : scores) {
        if (score < lowest) {
            lowest = score;
        }
    }

    return lowest;
}

// Count students who passed
int countPassing(const vector<int>& scores) {
    int total = 0;

    for (int score : scores) {
        if (score >= PASS_MARK) {
            total++;
        }
    }

    return total;
}

// Display student statistics
void showStatistics(const vector<int>& scores) {
    cout << "\n================ STUDENT STATISTICS ================\n";

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
}

// Remove a student by full name
void removeStudent(vector<string>& names, vector<int>& scores) {
    cout << "\n================== REMOVE STUDENT ==================\n";
    cout << "Enter student name: ";

    string name = readFullName();
    int index = findByName(names, name);

    if (index == -1) {
        cout << "\nStudent not found.\n";
        return;
    }

    names.erase(names.begin() + index);
    scores.erase(scores.begin() + index);

    cout << "\nStudent removed successfully!\n";
}

// Main program
int main() {
    vector<string> names;
    vector<int> scores;
    int choice;

    showBanner();

    do {
        showMenu();

        if (!(cin >> choice)) {
            cout << "\nInvalid input! Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

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
                cout << "\n****************************************************\n";
                cout << "*       Thank you for using TREEW Manager!         *\n";
                cout << "*                    Goodbye.                      *\n";
                cout << "****************************************************\n";
                break;

            default:
                cout << "\nInvalid choice. Please select 0-6.\n";
        }

    } while (choice != 0);

    return 0;
}
