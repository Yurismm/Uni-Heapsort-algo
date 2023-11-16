//heap sort v2 c2454177

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

// added time
 
using namespace std::this_thread;     
using namespace std::chrono_literals; 
using std::chrono::system_clock;


void heapifymax(int a[], int heapSize, int i) {

    // set the left index (i being index here)
    int left = 2 * i;

    int right = 2 * i + 1;

    int largest = i;

    if (left < heapSize && a[left] > a[largest]) {
    
        largest = left;
    
        cout << "swapping " << a[largest] << " with " << a[left] << endl;
        sleep_for(50ms);

    }


    if (right < heapSize && a[right] > a[largest]) {
    
        cout << "swapping " << a[largest] << " with " << a[right] << endl;
        sleep_for(50ms);
        largest = right;
    
    }


    if (largest != i) {
    
    
        swap(a[i], a[largest]);

        // recusion
        heapifymax(a, heapSize, largest);
    
    }

}



void heapSort(int a[], int heapSize) {
    // here we build the max heap

    for (int i = heapSize / 2 - 1; i >= 0; i--) {
    
        // this formula above allows you to detirmine the leaves of the tree
        heapifymax(a, heapSize, i);
    
    }

    // Heap sort, for loop keeps going until the heap is empty
    for (int i = heapSize - 1; i >= 0; i--) {
        swap(a[0], a[i]);

        heapifymax(a, i, 0);
    }
}

// prints the new array
void print(int a[], int heapSize) {

    for (int i = 0; i < heapSize; ++i)

        cout << a[i] << " ";

    cout << "   ";
}


int main()
{
    std::cout << "WIP!" << endl;

    int a[] = { 7, 10, 2, 13, 8, 17, 24, 199 , 100, 21, 100, 54, 210, 400 , 420 , 23, 77, 392 , 149 , 155 , 156, 122, 45 , 29 , 14 , 34, 600 , 321, 341, 233, 111, 14, 61, 88, 123, 99, 33, 36, 700, 657 };

    cout << "original array was " << "6 , 8 , 1 , 7 , 2 , 12" << endl;

    int heapSize = sizeof(a) / sizeof(a[0]);
    heapSort(a, heapSize);

    cout << "array now is: \n";
    print(a, heapSize);


}
