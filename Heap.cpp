#include <iostream>
#include <vector>
using namespace std;

// ==================== HEAP CLASS ====================
class Heap {
protected:
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
    Heap(bool maxHeap = true) { isMax = maxHeap; }

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

    vector<int> getHeap() const { return heap; }
};

// ==================== PRIORITY QUEUE ====================
class PriorityQueue : public Heap {
private:
    vector<pair<int, int>> pq; // (value, priority)

    int parent(int i) { return (i - 1) / 2; }
    int Lchild(int i) { return (2 * i) + 1; }
    int Rchild(int i) { return (2 * i) + 2; }

    void upPQ(int i) {
        if (i == 0) return;
        int p = parent(i);
        if ((isMax && pq[i].second > pq[p].second) || (!isMax && pq[i].second < pq[p].second)) {
            swap(pq[i], pq[p]);
            upPQ(p);
        }
    }

    void downPQ(int i) {
        int n = pq.size();
        int left = Lchild(i);
        int right = Rchild(i);
        int extreme = i;

        if (left < n && ((isMax && pq[left].second > pq[extreme].second) || (!isMax && pq[left].second < pq[extreme].second)))
            extreme = left;

        if (right < n && ((isMax && pq[right].second > pq[extreme].second) || (!isMax && pq[right].second < pq[extreme].second)))
            extreme = right;

        if (extreme != i) {
            swap(pq[i], pq[extreme]);
            downPQ(extreme);
        }
    }

public:
    PriorityQueue(bool maxQueue = true) : Heap(maxQueue) {}

    // Insert with priority
    void insert(int value, int priority) {
        pq.push_back({value, priority});
        upPQ(pq.size() - 1);
        printQueue();
    }

    // Extract highest (or lowest) priority element using heap property
    int extract() {
        if (pq.empty()) {
            cout << "Priority Queue is empty!\n";
            return -1;
        }

        int top = pq[0].first;
        pq[0] = pq.back();
        pq.pop_back();
        if (!pq.empty()) downPQ(0);

        cout << "Extracted highest priority value: " << top << endl;
        printQueue();
        return top;
    }

    void printQueue() {
        cout << "Priority Queue now: ";
        for (auto &x : pq)
            cout << "(" << x.first << ", P=" << x.second << ") ";
        cout << endl;
    }
};

// ==================== HEAP SORT FUNCTION ====================
void heapSort(vector<int>& arr) {
    Heap h(true); // build a max heap

    for (int val : arr)
        h.insert(val);

    // extract max repeatedly
    for (int i = arr.size() - 1; i >= 0; i--) {
        arr[i] = h.extract();
    }

    cout << "\nArray sorted using Heap Sort:\n";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
}

// ==================== MENUS ====================
void menu_Heap() {
    Heap h;
    int choice;

    while (true) {
        cout << "\n--- Heap Menu ---\n";
        cout << "1. Insert values\n";
        cout << "2. Extract\n";
        cout << "3. Perform Heap Sort\n";
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
        else if (choice == 3) {
            int n;
            cout << "Enter array size: ";
            cin >> n;
            vector<int> arr(n);
            cout << "Enter array elements: ";
            for (int i = 0; i < n; i++)
                cin >> arr[i];
            heapSort(arr);
        }
        else if (choice == 0) {
            cout << "Exiting...\n";
            break;
        }
        else {
            cout << "Invalid choice!\n";
        }
    }
}

void menu_PQ() {
    PriorityQueue pq;
    int choice;

    while (true) {
        cout << "\n--- Priority Queue Menu ---\n";
        cout << "1. Insert values with priorities\n";
        cout << "2. Extract highest priority element\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int count, val, pri;
            cout << "How many elements do you want to insert? ";
            cin >> count;
            for (int i = 0; i < count; i++) {
                cout << "Enter value " << i + 1 << ": ";
                cin >> val;
                cout << "Enter its priority: ";
                cin >> pri;
                pq.insert(val, pri);
            }
        }
        else if (choice == 2) {
            pq.extract();
        }
        else if (choice == 0) {
            cout << "Exiting Priority Queue menu...\n";
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }
}

void menu_HeapSort() {
    Heap h;
    int choice;

    while (true) {
        cout << "\n--- Heap Sort Menu ---\n";
        cout << "1. Enter array to sort\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            int n;
            cout << "Enter number of elements: ";
            cin >> n;

            vector<int> arr(n);
            cout << "Enter the elements:\n";
            for (int i = 0; i < n; i++) {
                cout << "Element " << i + 1 << ": ";
                cin >> arr[i];
            }

            cout << "\nOriginal array: ";
            for (int val : arr) cout << val << " ";
            cout << endl;

            // Perform Heap Sort
            heapSort(arr);

            cout << "\nSorted array (Ascending): ";
            for (int val : arr) cout << val << " ";
            cout << endl;
        }

        else if (choice == 0) {
            cout << "Exiting Heap Sort menu...\n";
            break;
        }

        else {
            cout << "Invalid choice! Try again.\n";
        }

        char cont;
        cout << "\nDo you want to (s)ort again or (q)uit? ";
        cin >> cont;

        if (cont == 's' || cont == 'S')
            continue;
        else if (cont == 'q' || cont == 'Q') {
            cout << "Goodbye!\n";
            break;
        }
    }
}


int main() {
    int choice;

    while (true) {
        cout << "\n==============================\n";
        cout << "      MAIN MENU\n";
        cout << "==============================\n";
        cout << "1. Work with Heap\n";
        cout << "2. Work with Priority Queue\n";
        cout << "3. Perform Heap Sort\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            menu_Heap();
        }
        else if (choice == 2) {
            menu_PQ();
        }
        else if (choice == 3) {
            menu_HeapSort();
        }
        else if (choice == 0) {
            cout << "Goodbye! 👋\n";
            break;
        }
        else {
            cout << "Invalid choice! Try again 😅\n";
        }
    }

    return 0;
}