//Assignment 6 DSA
//Harshwardhan Lokhande


#include <iostream>

using namespace std;

void heapify(int arr[], int N, int i) {
    int largest, l, r;
    largest = i;
    l = (2*i) + 1;
    r = (2*i) + 2;
    
    if(l<N and arr[l] < arr[largest]) {
        largest = l;
    }
    
    if(r<N and arr[r] < arr[largest]) {
        largest = r;
    }
    
    if(largest != i) {
        swap(arr[i], arr[largest]);
        
        heapify(arr, N, largest);
    }
}

void maxheap(int arr[], int N) {
    
    int i;
    for(i=(N/2)-1; i>=0; i--) {
        heapify(arr, N, i);
    }
    
    for(i=N-1; i>0; i--) {
        swap(arr[0], arr[i]);
        
        heapify(arr, i, 0);
    }
    
}

int extract(int arr[], int n) {
    
    cout<<"Extracted: "<<arr[0];
    arr[0] = arr[n-1];
    maxheap(arr, n-1);
    return n-1;
    
}

void display(int arr[], int n) {
    
    cout<<"-----------------------"<<endl;
    for(int i=0; i<n; i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<"-----------------------"<<endl;
}

int main() {
    
    int i, n, oper, arr[50];
    
    while(1) {
        
        cout<<"1. Add\n2. Extract\n3. Display\n4. Exit\nYour Choice: ";
        cin>>oper;
        
        switch(oper) {
            case 1:
            cout<<"Enter element: ";
            cin>>arr[n++];
            maxheap(arr, n);
            break;
            
            case 2:
            n = extract(arr, n);
            break;
            
            case 3:
            display(arr, n);
            break;
            
            case 4:
            exit(0);
            break;
        }
        cout<<endl;
    }
    
    return 0;
}
