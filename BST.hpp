/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   BST.hpp
 * Author: fofan
 *
 * Created on November 13, 2019, 9:20 PM
 */

#ifndef BST_HPP
#define BST_HPP

#include "Node.hpp"
#include<cstdio>
#include<iostream>


template<class ItemType>
class BST{
public:
    BST();
    ~BST();
    BST(const BST<ItemType>& other);
    BST<ItemType>& operator=(const BST<ItemType>& other);
    void InsertItem(ItemType item);
    Node<ItemType> * RetrieveItem(ItemType& item, bool &found);
    void DeleteItem(ItemType item);
    //void Insert(Node<ItemType> * aNode, ItemType item);
    bool IsEmpty();
    bool IsFull();
    Node<ItemType> * getRoot();
    void setRoot(ItemType item);
    BST<ItemType> * getInstance();
    
private:
    Node<ItemType> * root;
    //BST<int> pClass;
};

#endif /* BST_HPP */

