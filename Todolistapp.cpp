#include <iostream>
#include <string>
using namespace std;

// Structure for a task
struct Task {
    string description;
    bool completed;
    Task* next;

    Task(string desc) {
        description = desc;
        completed = false;
        next = nullptr;
    }
};

// Class for managing the to-do list
class ToDoList {
private:
    Task* head;

public:
    ToDoList() {
        head = nullptr;
    }

    // Add a task
    void addTask(string desc) {
        Task* newTask = new Task(desc);
        if (!head) {
            head = newTask;
        } else {
            Task* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newTask;
        }
        cout << "Task added successfully!\n";
    }

    // Mark a task as completed
    void completeTask(int index) {
        Task* temp = head;
        int count = 1;
        while (temp) {
            if (count == index) {
                temp->completed = true;
                cout << "Task marked as completed! ✅\n";
                return;
            }
            temp = temp->next;
            count++;
        }
        cout << "Invalid task number!\n";
    }

    // View all tasks
    void viewTasks() {
        if (!head) {
            cout << "No tasks available!\n";
            return;
        }
        Task* temp = head;
        int count = 1;
        while (temp) {
            cout << count << ". " << temp->description;
            if (temp->completed) {
                cout << " ✅";
            }
            cout << endl;
            temp = temp->next;
            count++;
        }
    }

    // Destructor to free memory
    ~ToDoList() {
        Task* temp;
        while (head) {
            temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    ToDoList todo;
    int choice;
    string task;
    int taskNumber;

    while (true) {
        cout << "\nTo-Do List Application" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Mark Task as Completed" << endl;
        cout << "3. View Tasks" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Ignore newline

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, task);
                todo.addTask(task);
                break;
            case 2:
                cout << "Enter task number to mark as completed: ";
                cin >> taskNumber;
                todo.completeTask(taskNumber);
                break;
            case 3:
                todo.viewTasks();
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
