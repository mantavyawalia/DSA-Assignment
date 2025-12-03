#include <iostream>
#include <vector>
using namespace std;

class PriorityQueue {
private:
    vector<int> heap;   // underlying array for heap

    int parent(int i) { return (i - 1) / 2; }
    int left(int i)   { return 2 * i + 1; }
    int right(int i)  { return 2 * i + 2; }

    // Move element at index i up to restore heap property
    void heapifyUp(int i) {
        while (i != 0 && heap[parent(i)] < heap[i]) { // max-heap
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    // Move element at index i down to restore heap property
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int l = left(i);
            int r = right(i);
            int largest = i;

            if (l < n && heap[l] > heap[largest])
                largest = l;
            if (r < n && heap[r] > heap[largest])
                largest = r;

            if (largest == i) break;

            swap(heap[i], heap[largest]);
            i = largest;
        }
    }

public:
    bool empty() const {
        return heap.empty();
    }

    // Insert element into priority queue
    void push(int x) {
        heap.push_back(x);          // add at end
        heapifyUp(heap.size() - 1); // fix upwards
    }

    // Return highest priority element (max)
    int top() const {
        if (heap.empty()) {
            cout << "Priority queue is empty.\n";
            return -1;  // or throw
        }
        return heap[0];
    }

    // Remove highest priority element
    void pop() {
        if (heap.empty()) {
            cout << "Priority queue is empty.\n";
            return;
        }
        heap[0] = heap.back();  // move last to root
        heap.pop_back();
        if (!heap.empty())
            heapifyDown(0);     // fix downwards
    }

    void print() const {
        cout << "Heap array: ";
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;

    // Insert some elements (priorities)
    pq.push(20);
    pq.push(5);
    pq.push(15);
    pq.push(30);
    pq.push(10);

    pq.print();

    cout << "Top (max priority): " << pq.top() << endl;

    cout << "Removing elements in priority order:\n";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
