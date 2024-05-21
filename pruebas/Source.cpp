#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

const int Max = 100;
const string FileName = "db.txt";

struct tEmployee {
    string name, surname1, surname2, nif, phone;
    int age;
    double salary;
    bool deleted = false;
};

typedef tEmployee tEmpArray[Max];

struct tList {
    tEmpArray employees;
    int counter = 0;
};

typedef int tIndex[Max];

int menu();
void load(tList& list);
void sortByName(const tList& list, tIndex names);
void sortByNIF(const tList& list, tIndex nifs);
void sortBySalary(const tList& list, tIndex salaries); // With equal salaries, sorted by full name
int find(const tList& list, tIndex nifs, string nif);
tEmployee newEmp();
bool insert(tList& list, tIndex names, tIndex nifs, tIndex salaries);
void print(const tEmployee& emp);
void print(const tList& list);
void print(const tList& list, const tIndex index);
void save(const tList& list);

int main() {
    tList list;
    tIndex names, nifs, salaries;
    tEmployee emp;
    int op = -1, pos;
    string nif;
    bool modified = false;

    load(list);
    sortByName(list, names);
    sortByNIF(list, nifs);
    sortBySalary(list, salaries);
    while (op != 0) {
        op = menu();
        switch (op) {
        case 1:
            print(list);
            break;
        case 2:
            print(list, names);
            break;
        case 3:
            print(list, nifs);
            break;
        case 4:
            print(list, salaries);
            break;
        case 5:
            modified = insert(list, names, nifs, salaries);
            if (modified)
                cout << "New employee added!" << endl;
            else
                cout << "List full! Impossible to add a new employee" << endl;
            break;
        case 6:
            cout << "NIF of the employee to delete: ";
            cin >> nif;
            pos = find(list, nifs, nif);
            if (pos == -1)
                cout << "NIF not found!" << endl;
            else {
                list.employees[pos].deleted = true;
                modified = true;
                cout << "Deleted!" << endl;
            }
            break;
        }
    }
    if (modified)
        save(list);

    return 0;
}

int menu() {
    int op = -1;

    while (op < 0 || op > 6) {
        cout << "1 - Print list" << endl;
        cout << "2 - Print list by names" << endl;
        cout << "3 - Print list by nifs" << endl;
        cout << "4 - Print list by salaries" << endl;
        cout << "5 - New employee" << endl;
        cout << "6 - Delete employee" << endl;
        cout << "0 - Exit" << endl;
        cout << "Option: ";
        cin >> op;
        if (op < 0 || op > 6)
            cout << "Wrong option! Try again..." << endl;
    }
    cout << endl;

    return op;
}

void load(tList& list) {
    ifstream file;
    file.open("db.txt");
    string name = " ";

    file >> name; //We create the variable so we dont access a non-permitted index
    while (name != "XXX" && list.counter < Max) {
        list.employees[list.counter].name = name;
        file >> list.employees[list.counter].surname1;
        file >> list.employees[list.counter].surname2;
        file >> list.employees[list.counter].nif;
        file >> list.employees[list.counter].phone;
        file >> list.employees[list.counter].age;
        file >> list.employees[list.counter].salary;
        list.counter++;
        file >> name;
    }
    file.close();
}

bool operator<(tEmployee left, tEmployee right) {
    return left.surname1 < right.surname1 ||
        left.surname1 == right.surname1 && (left.surname2 < right.surname2 ||
            left.surname2 == right.surname2 && left.name < right.name);
}

void sortByName(const tList& list, tIndex names) {
    int lowest = 0, tmp = 0;

    for (int i = 0; i < list.counter; i++)
        names[i] = i;
    // From first element to the second to last...
    for (int i = 0; i < list.counter - 1; i++) {
        lowest = i;
        // From i + 1 to last...
        for (int j = i + 1; j < list.counter; j++) {
            if (list.employees[names[j]] < list.employees[names[lowest]])
                lowest = j;
        }
        if (lowest > i) {
            tmp = names[i];
            names[i] = names[lowest];
            names[lowest] = tmp;
        }
    }
}

void sortByNIF(const tList& list, tIndex nifs) {

}

void sortBySalary(const tList& list, tIndex salaries) { // With equal salaries, sorted by full name

}

int find(const tList& list, tIndex nifs, string nif) {
    int pos = -1;

    for (int i = 0; i < list.counter; i++) {
        if (list.employees[i].nif == nif)
            pos = i;
    }
    return pos;
}

tEmployee newEmp() {
    tEmployee employee;

    cout << "Name: ";
    cin >> employee.name;
    cout << "First surname: ";
    cin >> employee.surname1;
    cout << "Second surname: ";
    cin >> employee.surname2;
    cout << "NIF: ";
    cin >> employee.nif;
    cout << "Phone: ";
    cin >> employee.phone;
    cout << "Age: ";
    cin >> employee.age;
    cout << "Salary: ";
    cin >> employee.salary;

    return employee;
}

bool insert(tList& list, tIndex names, tIndex nifs, tIndex salaries) {
    bool inserted = false;

    return inserted;
}

void print(const tEmployee& emp) {
    cout << left << emp.nif << "  " << setw(25) << emp.surname1 + " " + emp.surname2 + ", " + emp.name << "  " << emp.age << " Years  " << emp.phone << "  $" << fixed << setprecision(2) << emp.salary << endl;
}

void print(const tList& list) {
    for (int i = 0; i < list.counter; i++)
        if (!list.employees[i].deleted)
            print(list.employees[i]);
    cout << endl;
}

void print(const tList& list, const tIndex index) {
    for (int i = 0; i < list.counter; i++)
        if (!list.employees[index[i]].deleted)
            print(list.employees[index[i]]);
    cout << endl;
}

void save(const tList& list) {

}