
#include "Tree.hpp"

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string> 

using namespace std;

using namespace ariel;

void ariel::Node::setLeft(Node* left) {
    Node*x = this;
    if(x==NULL)
    throw "no node and therefore cannot set left";
	_left = left;
    }



void ariel::Node::setRight(Node* right) {
    Node*x = this;
    if(x==NULL)
    throw "no node and therefore cannot set right";
	_right = right;

}

void ariel::Node::setParent(Node* parent) {
    Node*x = this;
    if(x==NULL)
    throw "no node and therefore cannot set parent";
	_parent = parent;
}

string ariel::Node::to_string(){
    Node*x = this;
    if(x==NULL)
    throw "no node and therefore cannot print";
    return "value is: " + std::to_string(getValue()) + "\n";
}

string ariel::Node::print(string str){
    Node*x = this;
    if(x==NULL)
    throw "no node and therefore cannot print!";
    if(this->getLeft()!=NULL)
    str=str+this->getLeft()->print(str);
    if(this->getRight()!=NULL)
    str=str+this->getRight()->print(str);
    return to_string();
}




void ariel::Node::remove(){
    delete(this);
 }


Node* ariel::Node::minimum(){
    Node* x = this;
    if (x==NULL)
    throw "no node and therefore no minimum";
    while(x->getLeft()!=NULL)
    x=(*x).getLeft();
    return x;
}



ariel::Node::Node() {
    _value=0;
    this->_left = NULL;
    this->_right = NULL;
    this->_parent = NULL;
}

ariel::Node::Node(int x) {
    _value=x;
    this->_left = NULL;
    this->_right = NULL;
    this->_parent = NULL;
}


void ariel::Tree::insert(int value){
    Node* y = NULL;
    Node* x = _root;
    Node* z = new Node(value);
    while(x!=NULL){
        y=x;
        if(value<x->getValue())
        x = x->getLeft();
        else
        x = x->getRight();
    }
    z->setParent(y);
    if(y==NULL){
    _root=z;
    _size++;
    }
    else if(value<y->getValue()){
    y->setLeft(z);
    _size++;
    }
    else if(value>y->getValue()){
    y->setRight(z);
    _size++;
    }
    else throw "already contains number";
    print2D(_root);
}


void ariel::Tree::transplant(Node* u, Node* v){
    if(u->getParent()==NULL)
    _root=v;
    else if(u==u->getParent()->getLeft())
    u->getParent()->setLeft(v);
    else
    u->getParent()->setRight(v);
    if(v!=NULL)
    v->setParent(u->getParent());
}

Node* ariel::Tree::findNode(int i){
      Node* temp = _root;
      while(temp!=NULL && temp->getValue()!=i){
          if(temp->getValue()>i)
          temp = temp->getLeft();
          else if(temp->getValue()<i)
          temp = temp->getRight();
      }
      return temp;
    }


void ariel::Tree::remove(int i){
    Node* z = findNode(i);
    if(z!=NULL){
    _size--;
    if(z->getLeft()==NULL)
    transplant(z,z->getRight());
    else if(z->getRight()==NULL)
    transplant(z,z->getLeft());
    else{
        Node* y = z->getRight()->minimum();
        if(y->getParent()!=z){
            transplant(y,y->getRight());
            y->setRight(z->getRight());
            y->getRight()->setParent(y);
        }
        transplant(z,y);
        y->setLeft(z->getLeft());
        y->getLeft()->setParent(y);
    }
    z->remove();
    z = NULL;
    }
    else throw "no such number";
    print2D(_root);
}

int ariel::Tree::parent(int i){
    Node* x = findNode(i);
    if(x==NULL)
    throw "No node with that value";
    Node* y = x->getParent();
    if(y==NULL)
    throw "The node has no parent";
    print2D(_root);
    return y->getValue();
}

int ariel::Tree::left(int i){
    Node* x = findNode(i);
    if(x==NULL)
    throw "No node with that value";
    Node* y = x->getLeft();
    if(y==NULL)
    throw "The node has no left child";
    print2D(_root);
    return y->getValue();
}


int ariel::Tree::right(int i){
    Node* x = findNode(i);
    if(x==NULL)
    throw "No node with that value";
    Node* y = x->getRight();
    if(y==NULL)
    throw "The node has no right child";
    print2D(_root);
    return y->getValue();
}


int ariel::Tree::size(){
    print2D(_root);
    return _size;
}

int ariel::Tree::contains(int i){
    print2D(_root);
    Node* x = findNode(i);
    if(x==NULL)
    return 0;
    else return 1;
}

string ariel::Tree::print(){
    string str="";
    if(_root!=NULL)
    return _root->print(str);
    else return "no root. sorry";
}


ariel::Tree::Tree() {
    _root = NULL;
    _size=0;
}

ariel::Tree::Tree(int x) {
    _root = new Node(x);
    _size=0;
}

ariel::Tree::Tree(Node* node){
    _root = node;
    _size=0;
}




