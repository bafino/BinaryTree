/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "BST.hpp"

template <class ItemType>
Node<ItemType>* BST<ItemType>::getRoot(){
    return root;
}
template <class ItemType>
void BST<ItemType>::setRoot(ItemType item){
    Node<ItemType> * newNode = new Node<ItemType>;
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    root = newNode;
}

template <class ItemType>
bool BST<ItemType>::IsEmpty(){
    return (root == NULL);
};

template <class ItemType>
bool BST<ItemType>::IsFull(){
    try{
        Node<ItemType> * newNode = new Node<ItemType>;
        delete newNode;
    }catch(int e){
        std::cout <<" Tree is full error nr" << e << std::endl; 
    }
}

template <class ItemType>
void Insert(Node<ItemType> *& aNode, ItemType item){
 
    if(aNode == NULL){
        aNode = new Node<ItemType>;
        aNode->data = item;
        aNode->left = NULL;
        aNode->right = NULL;


        //std::cout<<"root ="<< obj.getRoot() <<std::endl;
        std::cout<<"inserted ="<< aNode->data<<std::endl;
    }else if(aNode->data > item){
        Insert(aNode->left, item);
    }else{
        Insert(aNode->right, item);
    }
}
template <class ItemType>
void BST<ItemType>::InsertItem(ItemType item){
    Insert(root, item);
}

template<class ItemType>
Node<ItemType> * Retrieve(Node<ItemType> *& aNode, ItemType& item, bool & found){
    if(aNode == NULL){
        found = false;
        std::cout << "Not found"<<"\n";
        //return;
    }else if(aNode->data > item){
        return Retrieve(aNode->left, item, found);
    }else if(aNode->data < item){
        return Retrieve(aNode->right, item, found);
    }else{
        found = true;
        //item = aNode->data;
        std::cout<< "found item "<< aNode->data <<std::endl;
    }
    return aNode;
}
template<class ItemType>
Node<ItemType> * BST<ItemType>::RetrieveItem(ItemType& item, bool &found){
    //Node<ItemType> * resItem = new Node<ItemType>;
    return Retrieve(root, item, found);
}

template<class ItemType>
void Destroy(Node<ItemType> * aNode){
    if(aNode !=NULL){
        Destroy(aNode->left);
        Destroy(aNode->right);
        delete aNode;
    }  
}

template<class ItemType>
BST<ItemType>& BST<ItemType>::operator=(const BST<ItemType>& other){
    if(this != &other){
        Destroy(root);
        CopyTree(root, other.root);
    }
    return *this;
}

template<class ItemType>
BST<ItemType>::BST(){
    root = NULL;
}

template<class ItemType>
BST<ItemType>::~BST(){
    Destroy(root);
}


template<class ItemType>
BST<ItemType>::BST(const BST<ItemType>& other){
    CopyTree(root, other.root);
}

template<class ItemType>
void CopyTree(Node<ItemType> *& aNode, const Node<ItemType> * bNode){
    if (bNode == NULL){
        aNode = NULL;
    }else{
        aNode = new Node<ItemType>;
        aNode->data = bNode->data;
        CopyTree(aNode->left, bNode->left);
        CopyTree(aNode->right, bNode->right);
    }
}

template<class ItemType>
Node<ItemType> * getPredecessor(Node<ItemType> *& aNode){
    
    if(aNode != NULL && aNode->right != NULL){
        return getPredecessor(aNode->right);
//    }else if(aNode != NULL && aNode->left != NULL){
//        return getPredecessor(aNode->left);
    }
    return aNode;
}

template<class ItemType>
void Delete(Node<ItemType> *& aNode, ItemType item){
    if(aNode == NULL){
        //to-do handle item not found;
        std::cout << "to-do";
    }else if(aNode->data > item){
        Delete(aNode->left, item);
    }else if(aNode->data < item){
        Delete(aNode->right, item);
    }else{
        // Save the node
        Node<ItemType> * tempNode = new Node<ItemType>;
        tempNode = aNode;
        
        // check for left child and right child
        if(aNode->left == NULL && aNode->right == NULL){
            delete tempNode;
        }else if(aNode->left == NULL && aNode->right != NULL){
            aNode = aNode->right;
            delete tempNode;
        }else if(aNode->left != NULL && aNode->right == NULL){
            aNode = aNode->left;
            delete tempNode;
        }else{
            // get the predecessor. this should be a leaf, with no children. safe to delete
            Node<ItemType> * PredNode = new Node<ItemType>;
            PredNode = getPredecessor(aNode->left);
            aNode->data = PredNode->data;
            Delete(PredNode, PredNode->data);
        }
        
    }
}

template<class ItemType>
void BST<ItemType>::DeleteItem(ItemType item){
    Delete(root, item);
}
template class BST<int>;