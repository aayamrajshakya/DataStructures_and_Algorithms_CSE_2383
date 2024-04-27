#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>
#include "LinkedList.h"
#include "BST.h"
using namespace std;

vector<int> numberList(char format) {
    vector<int> numbers;

    if (format == 'r') {
        for (int i = 1; i <= 1000; i++) {
            numbers.push_back(i);
        }
    }
    else if (format == 'b') {
        for (int i = 1000; i >= 1; i--) {
            numbers.push_back(i);
        }
    }
    return numbers;
}

void allNumberChecks(char format){
    vector<int> numbers = numberList(format);
    string Prompt1;
    string Prompt2;

    if (format == 'r') {
        Prompt1 = "Time taken to search from 1-1000: ";
        Prompt2 = "Time taken to insert 1-1000 ";
    }
    else if (format == 'b') {
        Prompt1 = "Time taken to search from 1000-1: ";
        Prompt2 = "Time taken to insert 1000-1 ";
    }
    
    // LinkedList part
    LinkedList ll;
    auto LLstart3= chrono::high_resolution_clock::now();
    for (int i : numbers){
        ll.prepend(i);
    }
    auto LLend3=chrono::high_resolution_clock::now();
    auto LLduration3=chrono::duration_cast<chrono::microseconds>(LLend3 - LLstart3);
    long LLmicroseconds3=LLduration3.count();
    cout << Prompt2 << " in the linked list: " << LLmicroseconds3 << " microseconds" << endl; 
    
    auto LLstart4 = chrono::high_resolution_clock::now();
    cout << "Found '44' in LinkedList or not? " << ll.search(44) << endl; 
    auto LLend4=chrono::high_resolution_clock::now();
    auto LLduration4=chrono::duration_cast<chrono::microseconds>(LLend4 - LLstart4);
    long LLmicroseconds4=LLduration4.count();
    cout << Prompt1 << " in the linked list: " << LLmicroseconds4 << " microseconds" << endl;
    

    // BST part
    BST b;
    auto BSTstart3 = chrono::high_resolution_clock::now();
    for (int i : numbers){
         b.insert(i);
    }
    auto BSTend3=chrono::high_resolution_clock::now();
    auto BSTduration3=chrono::duration_cast<chrono::microseconds>(BSTend3 - BSTstart3);
    long BSTmicroseconds3=BSTduration3.count();
    cout << Prompt2 << " in BST: " << BSTmicroseconds3 << " microseconds" << endl;
    
    auto BSTstart4 = chrono::high_resolution_clock::now();
    cout << "Found '44' in BST or not? " << b.find(44) << endl;
    auto BSTend4=chrono::high_resolution_clock::now();
    auto BSTduration4=chrono::duration_cast<chrono::microseconds>(BSTend4 - BSTstart4);
    long BSTmicroseconds4=BSTduration4.count();
    cout << Prompt1 << " in BST: " << BSTmicroseconds4 << " microseconds" << endl << endl;
}

void orderedNumberChecks(int max_ct) {
    int max_rand = 1000; // defines the range of random numbers (1-1000)
    srand(time(nullptr));  // seeds the random number generator with the current time
    
    vector<int> numberList;
    for (int i=0; i<max_ct; i++)
    {
        int randNum = (rand()%max_rand) + 1;  //displays a random number on the range of 1-1000
        numberList.push_back(randNum);
    }
    
    // LinkedList part
    LinkedList ll;
    auto LLstart1= chrono::high_resolution_clock::now();
    for (int i : numberList){
         ll.prepend(i);
    }
    auto LLend1=chrono::high_resolution_clock::now();
    auto LLduration1=chrono::duration_cast<chrono::microseconds>(LLend1 - LLstart1);
    long LLmicroseconds1=LLduration1.count();
    cout << "Time taken to insert " << max_ct << " random numbers in the linked list: " << LLmicroseconds1 << " microseconds" << endl;
    
    auto LLstart2 = chrono::high_resolution_clock::now();
    cout << "Found '44' in LinkedList or not? " << ll.search(44) << endl; 
    auto LLend2=chrono::high_resolution_clock::now();
    auto LLduration2=chrono::duration_cast<chrono::microseconds>(LLend2 - LLstart2);
    long LLmicroseconds2=LLduration2.count();
    cout << "Time taken to search '44' in a set of " << max_ct << " random numbers in LinkedList: " << LLmicroseconds2 << " microseconds" << endl;

    // BST part
    BST b;
    auto BSTstart1 = chrono::high_resolution_clock::now();
    for (int i : numberList){
         b.insert(i);
    }
    auto BSTend1=chrono::high_resolution_clock::now();
    auto BSTduration1=chrono::duration_cast<chrono::microseconds>(BSTend1 - BSTstart1);
    long BSTmicroseconds1=BSTduration1.count();
    cout << "Time taken to insert " << max_ct << " random numbers in BST: " << BSTmicroseconds1 << " microseconds" << endl;
    
    auto BSTstart2 = chrono::high_resolution_clock::now();
    cout << "Found '44' in BST or not? " << b.find(44) << endl;
    auto BSTend2=chrono::high_resolution_clock::now();
    auto BSTduration2=chrono::duration_cast<chrono::microseconds>(BSTend2 - BSTstart2);
    long BSTmicroseconds2=BSTduration2.count();
    cout << "Time taken to look for '44' in a set of " << max_ct << " random numbers in the tree: " << BSTmicroseconds2 << " microseconds" << endl << endl;
}

int main(){
    orderedNumberChecks(12);
    orderedNumberChecks(24);
    orderedNumberChecks(999);
    allNumberChecks('r');
    allNumberChecks('b');
    return 0;
}