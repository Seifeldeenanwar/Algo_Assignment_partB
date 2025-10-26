#include <iostream>
#include <vector>
using namespace std;

class Heap {
private:
    vector<int> heap;  // store heap elements
    bool isMax;        // true = Max Heap, false = Min Heap

    int parent(int i) { return (i - 1) / 2; }
    int Lchild(int i) { return (2 * i) + 1; }
    int Rchild(int i) { return (2 * i) + 2; }

    // recursive up-heapify
    void up(int i) {
        if (i == 0) return;
        int p = parent(i);
        if ((isMax && heap[i] > heap[p]) || (!isMax && heap[i] < heap[p])) {
            swap(heap[i], heap[p]);
            up(p);
        }
    }

    // recursive down-heapify
    void down(int i) {
        int n = heap.size();
        int left = Lchild(i);
        int right = Rchild(i);
        int extreme = i;

        if (left < n && ((isMax && heap[left] > heap[extreme]) || (!isMax && heap[left] < heap[extreme])))
            extreme = left;

        if (right < n && ((isMax && heap[right] > heap[extreme]) || (!isMax && heap[right] < heap[extreme])))
            extreme = right;

        if (extreme != i) {
            swap(heap[i], heap[extreme]);
            down(extreme);
        }
    }

public:
    Heap(bool maxHeap = true) {
        isMax = maxHeap;
    }

    void insert(int value) {
        heap.push_back(value);
        up(heap.size() - 1);
        printHeap();
    }

    int extract() {
        if (heap.empty()) {
            cout << "Heap is empty!\n";
            return -1;
        }

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) down(0);
        cout << "Extracted root: " << root << endl;
        printHeap();
        return root;
    }

    void printHeap() {
        cout << "Heap now: ";
        for (int x : heap)
            cout << x << " ";
        cout << endl;
    }
};

int main() {
    bool type;
    cout << "Enter 1 for Max Heap, 0 for Min Heap: ";
    cin >> type;

    Heap h(type);
    int choice;

    while (true) {
        cout << "\n--- Heap Menu ---\n";
        cout << "1. Insert values\n";
        cout << "2. Extract\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int count, val;
            cout << "How many numbers do you want to insert? ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                cout << "Enter number " << i + 1 << ": ";
                cin >> val;
                h.insert(val);
            }
        }
        else if (choice == 2) {
            h.extract();
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }

        // ask user what to do next
        char cont;
        cout << "\nDo you want to (a)dd more, (e)xtract again, or (q)uit? ";
        cin >> cont;

        if (cont == 'a' || cont == 'A')
            continue; // back to menu
        else if (cont == 'e' || cont == 'E')
            h.extract();
        else if (cont == 'q' || cont == 'Q') {
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
