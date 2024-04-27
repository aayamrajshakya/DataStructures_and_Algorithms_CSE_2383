#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

#include "list.h"
#include "tree.h"

void setNumbers(int maxAmount) {
    int Range = 1000;
    srand(time(nullptr));

    vector<int> numList;
    for (int i = 0; i < maxAmount; i++) {
        int Num = (rand() % Range) + 1;
        numList.push_back(Num);
    }

    // Configuration for linked list
    LinkedList list;
    auto LLstart1 = chrono::high_resolution_clock::now();
    for (int i = 0; i <= maxAmount; i++) {
        list.append(i);
    }
    auto LLend1 = chrono::high_resolution_clock::now();
    auto LLduration1 = chrono::duration_cast<chrono::microseconds>(LLend1 - LLstart1);
    long LLmicroseconds1 = LLduration1.count();
    cout << "Total time to populate (" << maxAmount << ") random numbers in LinkedList: " << LLmicroseconds1 << " ms."
         << endl;

    auto LLstart2 = chrono::high_resolution_clock::now();
    cout <<"Element found? "<< list.search(69) << endl;
    auto LLend2 = chrono::high_resolution_clock::now();
    auto LLduration2 = chrono::duration_cast<chrono::microseconds>(LLend2 - LLstart2);
    long LLmicroseconds2 = LLduration2.count();
    cout << "Total time to search for element in LinkedList: " << LLmicroseconds2 << " ms." << endl;
    cout << "**************************************************************************************" << endl;

    // Configuration for binary search tree
    BST tree;
    auto BSTstart1 = chrono::high_resolution_clock::now();
    for (int i = 0; i <= maxAmount; i++) {
        tree.insert(i);
    }
    auto BSTend1 = chrono::high_resolution_clock::now();
    auto BSTduration1 = chrono::duration_cast<chrono::microseconds>(BSTend1 - BSTstart1);
    long BSTmicroseconds1 = BSTduration1.count();
    cout << "Total time to populate (" << maxAmount << ") random numbers in Tree: " << BSTmicroseconds1 << " ms."
         << endl;

    auto BSTstart2 = chrono::high_resolution_clock::now();
    cout <<"Element found? "<< tree.find(69) << endl;
    auto BSTend2 = chrono::high_resolution_clock::now();
    auto BSTduration2 = chrono::duration_cast<chrono::microseconds>(BSTend2 - BSTstart2);
    long BSTmicroseconds2 = BSTduration2.count();
    cout << "Total time to search for element in Tree: " << BSTmicroseconds2 << " ms." << endl;
    cout << "**************************************************************************************" << endl;

}

void one_to_thousand() {

    // LinkedList -- 1 to 1000
    LinkedList ll1;
    auto LLstart3 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000; i++) {
        ll1.append(i);
    }
    auto LLend3 = chrono::high_resolution_clock::now();
    auto LLduration3 = chrono::duration_cast<chrono::microseconds>(LLend3 - LLstart3);
    long LLmicroseconds3 = LLduration3.count();
    cout << "Total time to populate 1-1000 in ascending order in LinkedList: " << LLmicroseconds3 << " ms." << endl;

    auto LLstart4 = chrono::high_resolution_clock::now();
    cout <<"Element found? "<< ll1.search(69) << endl;
    auto LLend4 = chrono::high_resolution_clock::now();
    auto LLduration4 = chrono::duration_cast<chrono::microseconds>(LLend4 - LLstart4);
    long LLmicroseconds4 = LLduration4.count();
    cout << "Total time to search in LinkedList: " << LLmicroseconds4 << " ms." << endl;


    // BST -- 1 to 1000
    BST b1;
    auto BSTstart3 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000; i++) {
        b1.insert(i);
    }
    auto BSTend3 = chrono::high_resolution_clock::now();
    auto BSTduration3 = chrono::duration_cast<chrono::microseconds>(BSTend3 - BSTstart3);
    long BSTmicroseconds3 = BSTduration3.count();
    cout << "Total time to populate 1-1000 in ascending order in Tree: " << BSTmicroseconds3 << " ms." << endl;

    auto BSTstart4 = chrono::high_resolution_clock::now();
    cout <<"Element found? "<< b1.find(69) << endl;
    auto BSTend4 = chrono::high_resolution_clock::now();
    auto BSTduration4 = chrono::duration_cast<chrono::microseconds>(BSTend4 - BSTstart4);
    long BSTmicroseconds4 = BSTduration4.count();
    cout << "Total time to search in Tree: " << BSTmicroseconds4 << " ms." << endl;
    cout << "**************************************************************************************" << endl;

}

void thousand_to_one() {

    // LinkedList -- 1000 to 1
    LinkedList ll2;
    auto LLstart5 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000; i++) {
        ll2.append(i);
    }
    auto LLend5 = chrono::high_resolution_clock::now();
    auto LLduration5 = chrono::duration_cast<chrono::microseconds>(LLend5 - LLstart5);
    long LLmicroseconds5 = LLduration5.count();
    cout << "Total time to populate 1000-1 in descending order in LinkedList: " << LLmicroseconds5 << " ms." << endl;

    auto LLstart6 = chrono::high_resolution_clock::now();
    cout <<"Element found? "<< ll2.search(69) << endl;
    auto LLend6 = chrono::high_resolution_clock::now();
    auto LLduration6 = chrono::duration_cast<chrono::microseconds>(LLend6 - LLstart6);
    long LLmicroseconds6 = LLduration6.count();
    cout << "Total time to search in LinkedList: " << LLmicroseconds6 << " ms." << endl;
    
    // BST -- 1000 to 1
    BST b2;
    auto BSTstart5 = chrono::high_resolution_clock::now();
    for (int i = 1; i <= 1000; i++) {
        b2.insert(i);
    }
    auto BSTend5 = chrono::high_resolution_clock::now();
    auto BSTduration5 = chrono::duration_cast<chrono::microseconds>(BSTend5 - BSTstart5);
    long BSTmicroseconds5 = BSTduration5.count();
    cout << "Total time to populate 1000-1 in descending order in Tree: " << BSTmicroseconds5 << " ms." << endl;

    auto BSTstart6 = chrono::high_resolution_clock::now();
    cout <<"Element found? "<< b2.find(69) << endl;
    auto BSTend6 = chrono::high_resolution_clock::now();
    auto BSTduration6 = chrono::duration_cast<chrono::microseconds>(BSTend6 - BSTstart6);
    long BSTmicroseconds6 = BSTduration6.count();
    cout << "Total time to search in Tree: " << BSTmicroseconds6 << " ms." << endl;
    cout << "**************************************************************************************" << endl;

}
int main() {
    setNumbers(12);
    setNumbers(24);
    setNumbers(999);
    one_to_thousand();
    thousand_to_one();
    return 0;
}