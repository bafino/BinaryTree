/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Node.hpp
 * Author: fofan
 *
 * Created on November 13, 2019, 9:20 PM
 */

#ifndef NODE_HPP
#define NODE_HPP

template<class ItemType>
struct Node{
    ItemType data;
    Node * left;
    Node * right;
};

#endif /* NODE_HPP */

