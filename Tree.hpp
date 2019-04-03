



#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


namespace ariel{

#define COUNT 10


class Node {

  private:    // Not required. All is private by default.

    int _value;
    Node* _parent;
    Node* _left;
    Node* _right;
    
    

  public:

    // methods defined inline:

    Node* getParent() { return _parent;  }

    Node* getLeft() { return _left;  }
    
    Node* getRight() { return _right;  }
    
    
    
void setLeft(Node* left);


void setRight(Node* right);


void setParent(Node* parent);


Node* minimum();

    

   
   int getValue(){
      return _value;
   }

   void remove();

   string to_string();

   string print(string str);
   
   
  Node();
  
  Node(int x);

};




class Tree {

  private:    // Not required. All is private by default.

    Node* _root;
    int _size;

    
    

  public:

    // methods defined inline:



    Node* findNode(int i);

    void insert(int i);

    void transplant(Node* u, Node* v);


    void remove(int i);

    int size();

    int contains(int i);

    int root(){
      if (_root==NULL)
      throw "no root";
      return _root->getValue();
    }

    int parent(int i);

    int left(int i);

    int right(int i);

    string print();

   
  Tree();
  
  Tree(Node* node);

  Tree(int i);




  // Function to print binary tree in 2D  
// It does reverse inorder traversal  
void print2DUtil(Node *root, int space)  
{  
    // Base case  
    if (root == NULL)  
        return;  
    // Increase distance between levels  
    space += COUNT;  
    // Process right child first  
    print2DUtil(root->getRight(), space);  
    // Print current node after space  
    // count  
    cout<<endl;  

    for (int i = COUNT; i < space; i++)  
        cout<<" ";  
    
    cout<<root->getValue()<<"\n";  
    // Process left child
    print2DUtil(root->getLeft(), space); 
}  
  
// Wrapper over print2DUtil()  
void print2D(Node *root)  
{ 
    cout<<"Tree's layout is"<<"\n"; 
    // Pass initial space count as 0  
    print2DUtil(root, 0);  
}  

};

}