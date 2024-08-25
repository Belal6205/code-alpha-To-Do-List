#include <iostream>
#include <string>
using namespace std;
class ToDoList {
private:
    string *ToDo;
    int size;
public:
    ~ToDoList() {
        delete[] ToDo;
    }

    void setSize(int size) {
        this->size = size;
        ToDo = new string[size];
    }
    int getSize() {
        return size;
    }
    void setToDo() {
        if (size <= 0) {
            cout << "Please retry to enter the number of tasks you want to do" << endl;
            return;
        }
        for (int i = 0; i < size; ++i) {
            cout << "Please enter task " << (i + 1) << ":" << endl;
            cin.ignore();
            getline(cin, ToDo[i]);
        }
    }
    string getToDo(int index) {
        if (index >= 0 && index < size) {
            return ToDo[index];
        }
        return "Invalid index";
    }
    void check() {
        string *done = new string[size];
        string *notYet = new string[size];
        int m = 0, n = 0;
        char checkThat;
        for (int j = 0; j < size; ++j) {
            cout << "Did you finish: " << ToDo[j] << "? [y/n]" << endl;
            cin >> checkThat;
            if (checkThat == 'y') {
                done[m++] = ToDo[j];
            } else {
                notYet[n++] = ToDo[j];
            }
        }
        cout << "Completed tasks:" << endl;
        for (int i = 0; i < m; ++i) {
            cout << done[i] << endl;
        }
        cout << "Tasks not yet completed:" << endl;
        for (int i = 0; i < n; ++i) {
            cout << notYet[i] << endl;
        }
        delete[] done;
        delete[] notYet;
    }
};
int main() {
    int days, tasks;
    cout << "For how many days do you want the program to work? ";
    cin >> days;
    cout << endl;
    ToDoList *toDo = new ToDoList[days];
    for (int z = 0; z < days; ++z) {
        cout << "Enter the number of tasks you have for day " << (z + 1) << ": ";
        cin >> tasks;
        toDo[z].setSize(tasks);
        toDo[z].setToDo();
        toDo[z].check();
    }
    delete[] toDo;
    return 0;
}
