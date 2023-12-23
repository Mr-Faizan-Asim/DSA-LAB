#include <iostream>
#include <vector>

using namespace std;

class LinearProbingHashTable {
private:
    int S;
     vector<int> T;

public:
    LinearProbingHashTable(int size) : S(size), T(size, -1) {}

    int h(int x) {
        return x % S;
    }

    void insert(int x) {
        int i = 0;
        while (T[(h(x) + i) % S] != -1) {
            i++;
        }
        T[(h(x) + i) % S] = x;
    }

    bool search(int x) {
        int i = 0;
        while (T[(h(x) + i) % S] != -1) {
            if (T[(h(x) + i) % S] == x) {
                return true;
            }
            i++;
        }
        return false;
    }
};

class ChainingHashTable {
private:
    int size;
    vector<list<int>> table;

public:
    ChainingHashTable(int tableSize) : size(tableSize), table(tableSize) {}

    int hash(int key) {
        return key % size;
    }

    void insert(int key) {
        int index = hash(key);
        table[index].push_back(key);
    }

    bool search(int key) {
        int index = hash(key);
        for (int value : table[index]) {
            if (value == key) {
                return true;  // Key found
            }
        }
        return false;  // Key not found
    }
};

class QuadraticProbingHashTable {
private:
    int S;
     vector<int> T;

public:
    QuadraticProbingHashTable(int size) : S(size), T(size, -1) {}

    int h(int x) {
        return x % S;
    }

    void insert(int x) {
        int i = 0;
        while (T[(h(x) + i * i) % S] != -1) {
            i++;
        }
        T[(h(x) + i * i) % S] = x;
    }

    bool search(int x) {
        int i = 0;
        while (T[(h(x) + i * i) % S] != -1) {
            if (T[(h(x) + i * i) % S] == x) {
                return true;
            }
            i++;
        }
        return false;
    }
};

int main() {
    LinearProbingHashTable LP(10);
    LP.insert(19);
    LP.insert(29);
    LP.insert(39);

     cout << "LP:\n";
     cout << "Search 19: " << (LP.search(19) ? "Found" : "Not Found") << "\n";
     cout << "Search 25: " << (LP.search(25) ? "Found" : "Not Found") << "\n";

    QuadraticProbingHashTable QP(10);
    QP.insert(19);
    QP.insert(29);
    QP.insert(39);

     cout << "\nQP:\n";
     cout << "Search 19: " << (QP.search(19) ? "Found" : "Not Found") << "\n";
     cout << "Search 25: " << (QP.search(25) ? "Found" : "Not Found") << "\n";

    return 0;
}
#include <iostream>
#include <vector>

class LinearProbingHashTable {
private:
    int S;
     vector<int> T;

public:
    LinearProbingHashTable(int size) : S(size), T(size, -1) {}

    int h(int x) {
        return x % S;
    }

    void insert(int x) {
        int i = 0;
        while (T[(h(x) + i) % S] != -1) {
            i++;
        }
        T[(h(x) + i) % S] = x;
    }

    bool search(int x) {
        int i = 0;
        while (T[(h(x) + i) % S] != -1) {
            if (T[(h(x) + i) % S] == x) {
                return true;
            }
            i++;
        }
        return false;
    }
};

class QuadraticProbingHashTable {
private:
    int S;
     vector<int> T;

public:
    QuadraticProbingHashTable(int size) : S(size), T(size, -1) {}

    int h(int x) {
        return x % S;
    }

    void insert(int x) {
        int i = 0;
        while (T[(h(x) + i * i) % S] != -1) {
            i++;
        }
        T[(h(x) + i * i) % S] = x;
    }

    bool search(int x) {
        int i = 0;
        while (T[(h(x) + i * i) % S] != -1) {
            if (T[(h(x) + i * i) % S] == x) {
                return true;
            }
            i++;
        }
        return false;
    }
};

int main() {
    LinearProbingHashTable LP(10);
    LP.insert(19);
    LP.insert(29);
    LP.insert(39);

     cout << "LP:\n";
     cout << "Search 19: " << (LP.search(19) ? "Found" : "Not Found") << "\n";
     cout << "Search 25: " << (LP.search(25) ? "Found" : "Not Found") << "\n";

    QuadraticProbingHashTable QP(10);
    QP.insert(19);
    QP.insert(29);
    QP.insert(39);

     cout << "\nQP:\n";
     cout << "Search 19: " << (QP.search(19) ? "Found" : "Not Found") << "\n";
     cout << "Search 25: " << (QP.search(25) ? "Found" : "Not Found") << "\n";

    return 0;
}

class lab14
{
};
