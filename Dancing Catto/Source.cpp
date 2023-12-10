#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

int main() {
    int a;
    cin >> a;
    for (int i = 0; i < 50; ++i) {
        cout << "  /\\_/\\ " << endl;
        cout << " ( o.o ) " << endl;
        cout << "  > ^ <  " << endl;
        cout << " /  -  \\ " << endl;
        system("cls"); 

        cout << "  /\\_/\\ " << endl;
        cout << " ( o.o ) " << endl;
        cout << "  \\ ^ / " << endl;
        cout << " /  -  \\ " << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        system("cls"); 

        cout << "  /\\_/\\ " << endl;
        cout << " ( o.o ) " << endl;
        cout << "  < ^ > " << endl;
        cout << " /  -  \\ " << endl;
        this_thread::sleep_for(chrono::milliseconds(100));
        system("cls");
    }
    return 0;
}