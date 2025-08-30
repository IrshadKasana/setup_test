#include <iostream>
#include<string>
// #include <bits/stdc++.h>
using namespace std;

struct NodeH {
    string key;
    int priority;
};

NodeH heapArr[100005]; 
int sizeofH = 0;

void buttomup(int m) {
    while (m > 1) {
        int parent = m / 2;
        if (heapArr[parent].priority > heapArr[m].priority) {
           NodeH temp = heapArr[parent];
             heapArr[parent] = heapArr[m];
              heapArr[m] = temp;
            m = parent;
        } else {
            break;
        }
    }
}


void topdown(int q) {
    while (true) {
        int left = q * 2;
        int right = q * 2 + 1;
        int smallest = q;

        if (left <= sizeofH && heapArr[left].priority < heapArr[smallest].priority)
            smallest = left;
        if (right <= sizeofH && heapArr[right].priority < heapArr[smallest].priority)
            smallest = right;

        if (smallest != q) {
              NodeH temp = heapArr[smallest];
              heapArr[smallest] = heapArr[q];
              heapArr[q] = temp;
            q = smallest;
        } else {
            break;
        }
    }
}


void insertingInto(string key, int priority) {
    if(sizeofH == 100005)
        return;
    
    sizeofH++;
    heapArr[sizeofH].key = key;
    heapArr[sizeofH].priority = priority;
    buttomup(sizeofH);
}


string peek() {
    if (sizeofH == 0) return "";
    return heapArr[1].key;
}


string extractMin() {
    if (sizeofH == 0) return "";
    string minimum = heapArr[1].key;
    heapArr[1] = heapArr[sizeofH];
    sizeofH--;
    topdown(1);
    return minimum;
}


void decreaseKey(string key, int newPriority) {
    if(sizeofH == 0)
        return;
    for (int i = 1; i <= sizeofH; i++) {
        if (heapArr[i].key == key) {
            heapArr[i].priority = newPriority;
            buttomup(i);
            return;
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int counting;
   
    if(!(cin>>counting))
        return 0;
    if(counting == 0)
        return 0;
    
    for(int i=0;i<counting;i++){
        string inputing;
            if(!(cin>> inputing)) break;
         if (inputing == "INSERT" || inputing =="insert") {
            string x;
            int p;
            if(!(cin >> x >> p)){ return 0;}
            insertingInto(x, p);
        } else if (inputing == "PEEK" ||inputing =="peek") {
            cout << peek() << "\n";
        } else if (inputing == "EXTRACT" || inputing =="extract") {
            cout << extractMin() << "\n";
        } else if (inputing == "DECREASE" || inputing =="decrease") {
            string x;
            int p;
           if(!(cin >> x >> p)){return 0;}
            decreaseKey(x, p);
        }
        
    }
    return 0;
}