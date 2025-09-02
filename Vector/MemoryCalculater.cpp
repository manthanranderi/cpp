#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class StudentRecord {
private:
    T studentId;
    string studentName;

public:
    StudentRecord(T id, string name) {
        studentId = id;
        studentName = name;
    }

    T getId() const {
        return studentId;
    }

    void printDetails() const {
        cout << "ID: " << studentId << ", Name: " << studentName << endl;
    }
};

template <typename T>
class StudentDatabase {
private:
    vector<StudentRecord<T>> records;

public:
    void insertStudent(T id, const string& name) {
        records.emplace_back(id, name);
        cout << "Student added successfully.\n\n";
    }

    void showAllStudents() const {
        if (records.empty()) {
            cout << "No student records available.\n\n";
            return;
        }

        for (const auto& student : records) {
            student.printDetails();
        }
        cout << endl;
    }

    void findStudent(T id) const {
        for (const auto& student : records) {
            if (student.getId() == id) {
                student.printDetails();
                cout << endl;
                return;
            }
        }
        cout << "Student with ID " << id << " not found.\n\n";
    }

    void deleteStudent(T id) {
        for (auto it = records.begin(); it != records.end(); ++it) {
            if (it->getId() == id) {
                records.erase(it);
                cout << "Student removed successfully.\n\n";
                return;
            }
        }
        cout << "No student found with ID " << id << ".\n\n";
    }
};

int main() {
    StudentDatabase<int> db;
    int choice;
    int id;
    string name;

    do {
        cout << "Menu:\n";
        cout << "1. Add Student\n";
        cout << "2. Show All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Student ID: ";
                cin >> id;
                cout << "Enter Student Name: ";
                cin >> name;
                db.insertStudent(id, name);
                break;

            case 2:
                db.showAllStudents();
                break;

            case 3:
                cout << "Enter Student ID to search: ";
                cin >> id;
                db.findStudent(id);
                break;

            case 4:
                cout << "Enter Student ID to delete: ";
                cin >> id;
                db.deleteStudent(id);
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n\n";
        }
    } while (choice != 0);

    return 0;
}
