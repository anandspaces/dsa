// creating and printing dynamic array
#include <iostream>
using namespace std;
int main() {
    int size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Initializing the array...\n";
    int* array = new int[size];
    cout << "Enter values in array:\n";
    for(int i = 0;i < size;i++) {
        cin >> array[i];
    }
    cout << "Printing values of array...\t";
    for(int i = 0;i < size;i++) {
        cout << array[i] << "\t";
    }
    return 0;
}