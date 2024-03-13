// creating and printing an array
#include <iostream>
using namespace std;
int main() {
    int array [] = {1,2,3,4};
    int n = sizeof(array)/sizeof(int);
    for(int i = 0;i < n;i++) {
        cout << array[i] << endl;
    }
    return 0;
}