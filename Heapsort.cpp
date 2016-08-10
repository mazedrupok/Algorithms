http://quiz.geeksforgeeks.org/heap-sort/
#include <iostream>
using namespace std;
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i;  // Initialize largest as root
    int l = 2*i + 1;  // left = 2*i + 1
    int r = 2*i + 2;  // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest]) largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i) { //largest not root
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);  //heapify the sub-tree
    }
}
// main function to do heap sort
void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) //heapify all parent node
        heapify(arr, n, i);
    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
void printArray(int arr[], int n) {
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
int main()
{
    int arr[10000], n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i];
    heapSort(arr, n);
    cout << "Sorted array is \n";
    printArray(arr, n);
}
