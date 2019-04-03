/**
 * Examples of automatic tests for the exercise on binary trees.
 *
 * @author Erel Segal-Halevi
 * @since 2019-02
 */

#include <iostream>
using std::cout, std::endl;
#include "badkan.hpp"
#include "Tree.hpp"


int main() {
  

  ariel::Tree myTree1;
  ariel::Tree myTree2;
  ariel::Tree myTree3;
  ariel::Tree myTree4;
  ariel::Tree myTree5;
  ariel::Tree myTree6;
  ariel::Tree myTree7;
  ariel::Tree myTree8;  

  badkan::TestCase tc("Binary tree");
  tc

/**
  .CHECK_EQUAL (emptytree.size(), 0)
  .CHECK_OK    (emptytree.insert(5))
  .CHECK_EQUAL (emptytree.size(), 1)
  .CHECK_EQUAL (emptytree.contains(5), true)
  .CHECK_OK    (emptytree.remove(5))
  .CHECK_EQUAL (emptytree.contains(5), false)
  .CHECK_THROWS(emptytree.remove(5))
  .CHECK_EQUAL (emptytree.size() ,0)
  
  .CHECK_EQUAL (threetree.size(), 3)
  .CHECK_EQUAL (threetree.root(), 5)
  .CHECK_EQUAL (threetree.parent(3), 5)
  .CHECK_EQUAL (threetree.parent(7), 5)
  .CHECK_EQUAL (threetree.left(5), 3)
  .CHECK_EQUAL (threetree.right(5), 7)
  .CHECK_THROWS(threetree.insert(3))
  .CHECK_THROWS(threetree.left(6))
  .CHECK_OK    (threetree.print())



*/

/**
tests the removal of a parent with two sons
**/

.CHECK_EQUAL (myTree1.size(), 0)
.CHECK_OK(myTree1.insert(978))
.CHECK_OK(myTree1.insert(715))
.CHECK_OK(myTree1.insert(569))
.CHECK_THROWS(myTree1.remove(-148))
.CHECK_OK(myTree1.insert(895))
.CHECK_OK(myTree1.remove(715))
.CHECK_THROWS(myTree1.remove(-148))

/**
tests the removal of a parent with one son
*/


.CHECK_OK(myTree2.insert(209))
.CHECK_OK(myTree2.insert(-946))
.CHECK_OK(myTree2.insert(-847))
.CHECK_OK(myTree2.insert(635))
.CHECK_OK(myTree2.insert(-906))
.CHECK_OK(myTree2.insert(931))
.CHECK_OK(myTree2.insert(-451))
.CHECK_THROWS(myTree2.remove(-289))
.CHECK_OK(myTree2.remove(-946))
.CHECK_EQUAL (myTree2.contains(-451), true)
.CHECK_EQUAL (myTree2.contains(-289), false)
.CHECK_EQUAL (myTree2.contains(-946), false)
.CHECK_EQUAL (myTree2.size(), 6)

/**
try to remove root's parent
try to remove non-existant left node
*/


.CHECK_OK(myTree3.insert(-981))
.CHECK_OK(myTree3.insert(-268))
.CHECK_OK(myTree3.insert(-559))
.CHECK_OK(myTree3.insert(-261))
.CHECK_OK(myTree3.insert(-472))
.CHECK_OK(myTree3.insert(-539))
.CHECK_EQUAL (myTree3.size(), 6)
.CHECK_THROWS(myTree3.remove(myTree3.parent(-981)))
.CHECK_EQUAL (myTree3.right(-559), -472)
.CHECK_THROWS(myTree3.remove(myTree3.left(-559)))


/**
 create a tree with a single right branch. remove all sons (existant and non-existant)
 */
 

 .CHECK_OK(myTree4.insert(1))
 .CHECK_OK(myTree4.insert(2))
 .CHECK_OK(myTree4.insert(3))
 .CHECK_OK(myTree4.insert(4))
 .CHECK_OK(myTree4.insert(5))
 .CHECK_OK(myTree4.remove(myTree4.right(4)))
 .CHECK_THROWS(myTree4.remove(myTree4.left(4)))
 .CHECK_OK(myTree4.remove(myTree4.right(3)))
 .CHECK_THROWS(myTree4.remove(myTree4.left(3)))
 .CHECK_EQUAL(myTree4.size(),3)
 .CHECK_THROWS(myTree4.remove(myTree4.parent(4)))
 .CHECK_THROWS(myTree4.remove(myTree4.parent(5)))

 
 








  .print();
  cout << "You have " << tc.right() << " right answers and " << tc.wrong() << " wrong answers so your grade is " << tc.grade() << ". Great!" << endl;
}


