#include <bits/stdc++.h>
using namespace std;

class MaxHeap{
    public:
    vector<int> heap;

    void bubbleUp(int index){

        while(index > 0){

            //find the parent
            int parent = (index - 1)/2;
            // if curr node > parent
            if(heap[index] > heap[parent]){
                swap(heap[index], heap[parent]);
                index = parent;
            }
            else{
                break;
            }
            
        }
    }

    void bubbleDown(){
        int index = 0;
        int size = heap.size();
        while(index < size){
            int left = 2 * index + 1;
            int right = 2 * index + 2;
            int largest = index;
            if(left < size && heap[left] > heap[largest]){
                largest = left;
            }
            if(right < size && heap[right] > heap[largest]){
                largest = right;
            }
            if(largest != index){
                swap(heap[index], heap[largest]);
                index = largest;
            }
            else{
                break;
            }
        }        
    }

    void Heapify(vector<int> &arr, int n, int i){
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        if(left < n && arr[left] > arr[largest]){
            largest = left;
        }
        if(right < n && arr[right] > arr[largest]){
            largest = right;
        }
        if(largest != i){
            swap(arr[i], arr[largest]);
            Heapify(arr, n, largest);
        }
        else{
            return;
        }
    }

    void insert(int value){
        heap.push_back(value);
        bubbleUp(heap.size() - 1);

    }

    void Delete(){
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        bubbleDown();
    }

    void BuildMaxHeap(vector<int> &arr){
        int n = arr.size();
        for(int i = n/2 - 1; i >= 0; i--){
            Heapify(arr, n, i);
        }
    }

};

int main(){
    MaxHeap heap;
    vector<int> arr = {10, 3, 5, 30, 2, 8, 15};
    heap.BuildMaxHeap(arr);
    for(int i : arr){
        cout << i << " ";
    }

}