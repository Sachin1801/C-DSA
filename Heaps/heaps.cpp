#include<iostream>
using namespace std ;

void bubble_up(int ar_heap[], int i){
    
    while(ar_heap[i]>ar_heap[i/2]){
        swap(ar_heap[i],ar_heap[i/2]);
        i /=2;
    }
    return;
}

void build_heap_iterative(int arr[], int n, int ar_heap[]){
    //base case
    int heapsize =0;
    for(int i=0;i<n;i++){
        ar_heap[heapsize++] = arr[i];
        bubble_up(ar_heap, heapsize-1);
    }
    return;
}

void bubble_down(int *arr, int n, int i) {
    int largest = i; // Initialize largest as the root
    int left = 2*i + 1; // Left child index
    int right = 2*i + 2; // Right child index

    // If the left child is larger than the current largest
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    // If the right child is larger than the current largest
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    // If the largest is not the root, swap and continue bubbling down
    if (largest != i) {
        swap(arr[i], arr[largest]);
        bubble_down(arr, n, largest);
    }
}

void build_heap_bottom_up(int *arr, int n){
    for(int j=n/2;j>=0;j--){
        bubble_down(arr,n,j);
    }
    return;
}

void delete_max(int *arr, int heap_size){
    swap(arr[0],arr[heap_size]);
    heap_size -=1 ;
    bubble_down(arr,heap_size,0);

}

void heap_sort(int *arr, int n){
    build_heap_bottom_up(arr,n);
    for(int i=n-1;i>=1;i--){
        delete_max(arr, i);
    }
}

int main(){

    freopen("output.txt", "w", stdout);
    freopen("input.txt", "r", stdin);
    
    int arr[]={4, 1 ,3 ,2, 16, 9, 10, 14, 8, 7};
    int n = sizeof(arr)/sizeof(int);

    int ar_heap[100];

    // build_heap_iterative(arr,n,ar_heap);

    build_heap_bottom_up(arr,n);

    heap_sort(arr,n);


    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }

    
    return 0;
}