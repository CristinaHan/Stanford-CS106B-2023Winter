/*
 * CS106B Section Handout Test Harness: Section 8
 * ----------------------------------------------
 * These problems have been galvanized from years of
 * section handouts that have been worked on by numerous
 * instructors and TA's. Codified by Neel Kishnani for 
 * CS106B Winter 2022.
 *
 * A huge thank you to Keith Schwarz and Julie Zelenski
 * for creating an amazing testing harness!
 */

#include <iostream>
#include "testing/SimpleTest.h"
#include "node.h"
#include "utility.h"
#include "error.h"
#include "set.h"
using namespace std;

struct OSTNode {
  int value;
  int leftSubtreeSize;
  OSTNode* left;
  OSTNode* right;
};

/*
 * Function: kthNodeIn 
 * --------------------
 * Accepts as input a pointer to the root of the order 
 * statistic tree, along with a number k, then returns 
 * a pointer to the kth-smallest node in the tree (zero-indexed). 
 * If _k_ is negative or at least as large as the number of nodes 
 * in the tree, your function should return nullptr as a sentinel.
 */
OSTNode* kthNodeIn(OSTNode* root, int k) {
    if (root == nullptr || k < 0) return nullptr;

    if (k < root->leftSubtreeSize) return kthNodeIn(root->left, k);
    else if (k == root->leftSubtreeSize) return root;
    else return kthNodeIn(root->right, k - 1 - root->leftSubtreeSize); //减去根节点左子树和根节点
}

PROVIDED_TEST("Simple tests for kthNodeIn function") {
    OSTNode* root = new OSTNode;
    root->leftSubtreeSize = 2;
    OSTNode* firstChild = new OSTNode;
    root->left = firstChild;
    root->right = nullptr;
    firstChild->leftSubtreeSize = 1;
    OSTNode* secondChild = new OSTNode;
    firstChild->left = secondChild;
    firstChild->right = nullptr;
    secondChild->leftSubtreeSize = 0;
    secondChild->left = nullptr;
    secondChild->right = nullptr;
    EXPECT_EQUAL(kthNodeIn(root, 2), root);
    delete root;
    delete firstChild;
    delete secondChild;
}
