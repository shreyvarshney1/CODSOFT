#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    // Constructor
    Task(const string& desc) : description(desc), completed(false) {}
};

// Function prototypes
void displayMenu();
void addTask(vector<Task>& tasks);
void viewTasks(const vector<Task>& tasks);
void markAsCompleted(vector<Task>& tasks);
void removeTask(vector<Task>& tasks);

int main() {
    vector<Task> tasks;

    int choice;
    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markAsCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    } while (choice != 5);

    return 0;
}

void displayMenu() {
    cout << "\n===== To-Do List Manager =====" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. View Tasks" << endl;
    cout << "3. Mark Task as Completed" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTask(vector<Task>& tasks) {
    string description;
    cout << "Enter the task description: ";
    cin.ignore(); // Ignore newline character from previous input
    getline(cin, description);

    tasks.push_back(Task(description));
    cout << "Task added successfully!" << endl;
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\n===== Task List =====" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << (tasks[i].completed ? "[X] " : "[ ] ") << tasks[i].description << endl;
    }
}

void markAsCompleted(vector<Task>& tasks) {
    viewTasks(tasks);

    if (tasks.empty()) {
        cout << "No tasks to mark as completed." << endl;
        return;
    }

    int index;
    cout << "Enter the task number to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!" << endl;
    } else {
        cout << "Invalid task number. Please enter a valid task number." << endl;
    }
}

void removeTask(vector<Task>& tasks) {
    viewTasks(tasks);

    if (tasks.empty()) {
        cout << "No tasks to remove." << endl;
        return;
    }

    int index;
    cout << "Enter the task number to remove: ";
    cin >> index;

    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!" << endl;
    } else {
        cout << "Invalid task number. Please enter a valid task number." << endl;
    }
}
