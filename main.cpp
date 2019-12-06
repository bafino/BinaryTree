/* 
 * File:   main.cpp
 * Author: fofana
 *
 * Created on November 13, 2019, 9:19 PM
 */

#include <cstdlib>
#include "BST.hpp"
//#include "Node.hpp"
#include<cstdlib>
#include <list>


using namespace std;

int main(int argc, char** argv) {
    BST<int> * aTree = new BST<int>();
    Node<int> * aNode = new Node<int>();
    
    int key = 7;
    
    list<int> myList1={10, 9, 13, 12, 7, 8, 11, 5, 2, 3};
    int myList[]={10, 9, 13, 12, 7, 8, 11, 5, 2, 3};
    
//    for(int i = 1; i < 100; i++){
//        //int val = rand() % 100;
//        //cout <<"random is = " << val << endl;
//        aTree->InsertItem(i);
//    }
    for (auto it = myList1.begin(); it != myList1.end(); it++){
        aTree->InsertItem(*it);
    }
//    for (int i = 0; i < sizeof(myList)/sizeof(int); i++){
//        aTree->InsertItem(myList[i]);
//    }
    
    bool found = false;
    
    aNode = aTree->RetrieveItem(key, found);
    //root = aNode->getRoot();
    cout << "root = "<< aTree->getRoot()->data <<endl;
    cout << "key = "<< ((aNode == NULL)? 0:aNode->data) <<endl;
    cout << "found = "<<found <<endl;
    
    aTree->DeleteItem(key);
    Node<int> * bNode = new Node<int>();
    bNode = aTree->RetrieveItem(key, found);
    cout << "root = "<< aTree->getRoot()->data <<endl;
    cout << "key = "<< ((bNode == NULL)? 0:bNode->data) <<endl;
    cout << "found = "<<found <<endl;
    
    
    
    return 0;
}

