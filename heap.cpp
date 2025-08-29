#include <bits/stdc++.h>
using namespace std;

struct Element {
    string key;
    int priority;
};

Element heapArr[100005]; // large enough for constraints
int sizeHeap = 0;

// Swap two elements
void swapElem(int i, int j) {
    Element temp = heapArr[i];
    heapArr[i] = heapArr[j];
    heapArr[j] = temp;
}

// Heapify up
void heapifyUp(int idx) {
    while (idx > 1) {
        int parent = idx / 2;
        if (heapArr[parent].priority > heapArr[idx].priority) {
            swapElem(parent, idx);
            idx = parent;
        } else {
            break;
        }
    }
}

// Heapify down
void heapifyDown(int idx) {
    while (true) {
        int left = idx * 2;
        int right = idx * 2 + 1;
        int smallest = idx;

        if (left <= sizeHeap && heapArr[left].priority < heapArr[smallest].priority)
            smallest = left;
        if (right <= sizeHeap && heapArr[right].priority < heapArr[smallest].priority)
            smallest = right;

        if (smallest != idx) {
            swapElem(smallest, idx);
            idx = smallest;
        } else {
            break;
        }
    }
}

// Insert element
void insertElement(string key, int priority) {
    sizeHeap++;
    heapArr[sizeHeap].key = key;
    heapArr[sizeHeap].priority = priority;
    heapifyUp(sizeHeap);
}

// Peek (return smallest element's key)
string peek() {
    if (sizeHeap == 0) return "";
    return heapArr[1].key;
}

// Extract min (remove and return smallest)
string extractMin() {
    if (sizeHeap == 0) return "";
    string minKey = heapArr[1].key;
    heapArr[1] = heapArr[sizeHeap];
    sizeHeap--;
    heapifyDown(1);
    return minKey;
}

// Decrease priority of element x
void decreaseKey(string key, int newPriority) {
    for (int i = 1; i <= sizeHeap; i++) {
        if (heapArr[i].key == key) {
            heapArr[i].priority = newPriority;
            heapifyUp(i);
            return;
        }
    }
}

int main() {
    int Q;
    cin >> Q;
    while (Q--) {
        string cmd;
        cin >> cmd;
        if (cmd == "INSERT") {
            string x;
            int p;
            cin >> x >> p;
            insertElement(x, p);
        } else if (cmd == "PEEK") {
            cout << peek() << "\n";
        } else if (cmd == "EXTRACT") {
            cout << extractMin() << "\n";
        } else if (cmd == "DECREASE") {
            string x;
            int p;
            cin >> x >> p;
            decreaseKey(x, p);
        }
    }
    return 0;
}
