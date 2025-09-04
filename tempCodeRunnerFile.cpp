#include <iostream>
using namespace std;

int Prima(int a) {
    if (a < 2) return false; 
    for (int i = 2; i * i <= a; i++) { 
        if (a % i == 0) return false; 
    }
    return true; 
}

int main() {
    int a; 
    cin >> a; 
    if (Prima(a)) {
        cout << "YA"; 
    } else {
        cout << "BUKAN"; 
    }

    return 0;
}