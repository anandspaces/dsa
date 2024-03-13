// operations on array
#include <iostream>
using namespace std;
int* globalarray;
int size;
int* createarray(int size) {
    int* array;
    array = new int[size];
    cout << "Enter values:\n";
    for(int i = 0;i < size;i++) {
        cin >> array[i]; 
    }
    cout << "Array is initialized...\n";
    return array;
}
void printarray(int array[]) {
    for(int i = 0;i < size;i++) {
        cout << array[i] << "\t";
    }
    cout << endl;
}
int searcha(int* array,int element) {
    int i = 0;
    for(;i < size;i++) {
        if(element == array[i]) {
            return i;
        } else {
            continue;
        }
    }
    return -1;
}
int* inserta(int* array) {
    int element,position;
    cout << "Type the element to insert: ";
    cin >> element;
    cout << "Type the position of insertion: ";
    cin >> position;
    if(position > size || position < 0) {
        cout << "Invalid position" << endl;
        return globalarray;
    }
    size++;
    int* array1 = new int[size];
    for(int i = 0;i < size;i++) {
        if(i < position) {
            array1[i] = array[i];
        } else if(i == position) {
            array1[i] = element;
        } else {
            array1[i] = array[i - 1];
        }
    }
    globalarray = array1;
    cout << "Printing new array..." << endl;
    printarray(globalarray);
    return globalarray;
}
int* deletea(int* array) {
    int element,position;
    cout << "Type the element to delete: ";
    cin >> element;
    if(searcha(array,element) == -1) {
        cout << "Element not found!";
        return array;
    } else {
        position = searcha(array,element);
    }
    size--;
    int* array1 = new int[size];
    for(int i = 0;i < size;i++) {
        if(i < position) {
            array1[i] = array[i];
        } else {
            array1[i] = array[i + 1];
        }
    }
    globalarray = array1;
    cout << "Printing new array..." << endl;
    printarray(globalarray);
    return globalarray;
}
int* mergea(int* marray,int msize) {
    int* array1 = new int[size];
    for(int i = 0;i < size;i++) {
        array1[i] = globalarray[i];
    }
    for(int i = size,j = 0;i < size + msize && j < msize;i++,j++) {
        array1[i] = marray[j];
    }
    size += msize;
    globalarray = array1;
    cout << "Printing new array..." << endl;
    printarray(globalarray);
    return globalarray;
}
int main() {
    int token = 0;
    cout << "Enter the size of array: ";
    cin >> size;
    globalarray = createarray(size);
    cout << "1. Search element in the array.\n"
            << "2. Insert element in the array.\n"
            << "3. Delete element in the array.\n"
            << "4. Filter an array.\n"
            << "5. Fetch a subarray.\n"
            << "6. Merging arrays.\n"
            << "7. Reverse array.\n"
            << "8. Rotate array.\n";
    while(token > 0) {
        cout << "Enter: ";
        cin >> token;
        switch(token) {
            case 1 : {
                int element;
                cout << "Type the element to search: ";
                cin >> element;
                int pos = searcha(globalarray,element);
                if(pos == -1) {
                    cout << "Element not found" << endl;
                } else {
                    cout << "Element found at " << pos << endl;
                }
                break;
            }
            case 2 : {
                inserta(globalarray);
                break;
            }
            case 3 : {
                deletea(globalarray);
                break;
            }
            case 6 : {
                int msize;
                cout << "Enter the size of new array: ";
                cin >> msize;
                int* marray = new int[msize];
                cout << "Enter elements of new array:\n";
                for(int i = 0;i < msize;i++) {
                    cin >> marray[i];
                }
                mergea(marray,msize);
                delete[] marray;
                break;
            }
            default : {
                cout << "Enter valid option!\n";
                continue;
            }
        }
    }
    
    delete[] globalarray;
    return 0;
}

