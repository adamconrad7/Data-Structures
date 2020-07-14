/*
 * This file is where you should implement your binary search tree.  It already
 * contains skeletons of the functions you need to implement (along with
 * documentation for each function).  Feel free to implement any additional
 * functions you might need.  Also, don't forget to include your name and
 * @oregonstate.edu email address below.
 *
 * Name: Adam Conrad
 * Email: conraada@oregonstate.edu
 */

#include <stdlib.h>
#include <stdio.h>

#include "bst.h"

/*
 * This structure represents a single node in a BST.  In addition to containing
 * pointers to its two child nodes (i.e. `left` and `right`), it contains two
 * fields representing the data stored at this node.  The `key` field is an
 * integer value that should be used as an identifier for the data in this
 * node.  Nodes in the BST should be ordered based on this `key` field.  The
 * `value` field stores data associated with the key.
 *
 * You should not modify this structure.
 */
struct bst_node {
  int key;
  void* value;
  struct bst_node* left;
  struct bst_node* right;
};


/*
 * This structure represents an entire BST.  It specifically contains a
 * reference to the root node of the tree.
 *
 * You should not modify this structure.
 */
struct bst {
  struct bst_node* root;
};

/*
 * This function should allocate and initialize a new, empty, BST and return
 * a pointer to it.
 */
struct bst* bst_create() {
  // allocate pointer to struct and point its root to null
  struct bst* bstp = malloc( sizeof( struct bst));
  bstp -> root = NULL;
  return bstp;
}

/*
 * This function should free the memory associated with a BST.  While this
 * function should up all memory used in the BST itself, it should not free
 * any memory allocated to the pointer values stored in the BST.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   bst - the BST to be destroyed.  May not be NULL.
 */
void bst_free(struct bst* bst) {
  //Interface function to free_node()
  free_node(bst -> root);
  free(bst);
  return;
}

/*
 * This function should return the total number of elements stored in a given
 * BST.
 *
 * Params:
 *   bst - the BST whose elements are to be counted.  May not be NULL.
 */
int bst_size(struct bst* bst) {
  //interface function to sise()
  return sise( bst -> root);
}

/*
 * This function should insert a new key/value pair into the BST.  The key
 * should be used to order the key/value pair with respect to the other data
 * stored in the BST.  The value should be stored along with the key, once the
 * right location in the tree is found.
 *
 * Params:
 *   bst - the BST into which a new key/value pair is to be inserted.  May not
 *     be NULL.
 *   key - an integer value that should be used to order the key/value pair
 *     being inserted with respect to the other data in the BST.
 *   value - the value being inserted into the BST.  This should be stored in
 *     the BST alongside the key.  Note that this parameter has type void*,
 *     which means that a pointer of any type can be passed.
 */
void bst_insert(struct bst* bst, int key, void* value) {
  // if tree is empty insert root node
  if(bst -> root == NULL)
      bst -> root = new_node(key, value);
  // otherwise, recursively find where to insert new node
  else{
      struct bst_node* parent = find_node(bst -> root, key);
      struct bst_node* new =  new_node(key, value);
      // determine which child new node is
      if(key > parent -> key)
         parent -> right = new;
      else
         parent -> left = new;
  }
}

/*
 * This function should remove a key/value pair with a specified key from a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should remove the first one it encounters (i.e. the one closest to
 * the root of the tree).
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair to be removed from the BST.
 */
void bst_remove(struct bst* bst, int key) {
  // Interface function for delete node()
  delete_node(bst -> root, key);
  return;
}

/*
 * This function should return the value associated with a specified key in a
 * given BST.  If multiple values with the same key exist in the tree, this
 * function should return the first one it encounters (i.e. the one closest to
 * the root of the tree).  If the BST does not contain the specified key, this
 * function should return NULL.
 *
 * Params:
 *   bst - the BST from which a key/value pair is to be removed.  May not
 *     be NULL.
 *   key - the key of the key/value pair whose value is to be returned.
 *
 * Return:
 *   Should return the value associated with the key `key` in `bst` or NULL,
 *   if the key `key` was not found in `bst`.
 */
void* bst_get(struct bst* bst, int key) {
  // if tree is empty return NULL
  if(bst -> root == NULL ) return NULL;
  // recursively get node based on key:
  struct bst_node* n = get_node( bst -> root, key);
  // make sure key was matched
  if(n == NULL){
    return NULL;
  }
  return n -> value;
}


//CUSTOM FUNCTIONS
void free_node(struct bst_node* node){
  // base case
  if( node == NULL){
    return;
  }
  free_node(node -> right);
  free_node(node -> left);
  free(node);
}

struct bst_node* get_node(struct bst_node* node, int key){
  // base case 1: when leaf's child is found
  if(node == NULL){
    return NULL;
  // base case 2: when match is found
  }else if(key == node -> key){
    return node;
  // otherwise recurse based on key
  }else if( key > node -> key){
    return get_node( node -> right, key);
  }else{
    return get_node( node -> left, key);
  }
}

struct bst_node*  delete_node(struct bst_node* node, int key){

  if( node == NULL) return node;
  // continue searching based on key
  if( key < node -> key)
    node -> left = delete_node(node -> left, key);
  else if(key > node -> key)
    node -> right = delete_node(node -> right, key);
  // node with matching key is found, delete
  else{
    // if node has one child point it around node to be deleted and free it
    if( node -> left == NULL){
      struct bst_node* tmp = node -> right;
      free(node);
      return tmp;
    }else if( node -> right == NULL){
      struct bst_node* tmp = node -> left;
      free(node);
      return tmp;
    }
    // otherwise node has a subtree so we must find the left most node in its right subtree
    struct bst_node* tmp = minValueNode(node -> right);
    node -> key = tmp -> key;
    node -> right = delete_node( node->right, tmp -> key);
  }
  return node;
}

struct bst_node* find_node( struct bst_node* node, int key){
 // if leaf is found, return it
 if(node -> left == NULL && node -> right == NULL){
      return node;
  // otherwise, continue searching based on key
  }else if( key > node -> key){
      // if rightmost node is ofund, return it
      if( node -> right == NULL){
        return node;
      }
      return find_node( node -> right, key);
  }else{
      // if leftmost node is ofund, return it
      if( node -> left == NULL){
        return node;
      }
      return find_node( node -> left, key);
  }
}

// Allocates new node with given key and value:
struct bst_node* new_node(int key, void* val){
  struct bst_node* new_node =  malloc( sizeof( struct bst_node));
  new_node -> key = key;
  new_node -> value = val;
  new_node -> left = NULL;
  new_node -> right = NULL;
  return new_node;
}

int sise(struct bst_node* node) {
  // if bottom of tree is found, dont count it
  if(node == NULL){
    return 0;
  }else{
    // otherwise, count this node and continue down the tree
    return sise(node -> left) + sise(node -> right) + 1;
  }
}

// function that returns the leftmost node in from a given tree
struct bst_node * minValueNode(struct bst_node* node){
    struct bst_node* current = node;

    while (current && current->left != NULL)
        current = current->left;

    return current;
}

/*****************************************************************************
 **
 ** BST iterator definition (extra credit only)
 **
 *****************************************************************************/

/*
 * Structure used to represent a binary search tree iterator.  It contains
 * only a reference to a stack to be used to implement the iterator.
 *
 * You should not modify this structure.
 */
struct bst_iterator {
  struct stack* stack;
};

/*
 * This function should allocate and initialize an iterator over a specified
 * BST and return a pointer to that iterator.
 *
 * Params:
 *   bst - the BST for over which to create an iterator.  May not be NULL.
 */
struct bst_iterator* bst_iterator_create(struct bst* bst) {
  return NULL;
}

/*
 * This function should free all memory allocated to a given BST iterator.
 * It should NOT free any memory associated with the BST itself.  This is the
 * responsibility of the caller.
 *
 * Params:
 *   iter - the BST iterator to be destroyed.  May not be NULL.
 */
void bst_iterator_free(struct bst_iterator* iter) {
  return;
}

/*
 * This function should indicate whether a given BST iterator has more nodes
 * to visit.  It should specifically return 1 (true) if the iterator has at
 * least one more node to visit or 0 (false) if it does not have any more
 * nodes to visit.
 *
 * Param:
 *   iter - the BST iterator to be checked for remaining nodes to visit.  May
 *     not be NULL.
 */
int bst_iterator_has_next(struct bst_iterator* iter) {
  return 0;
}

/*
 * This function should return both the value and key associated with the
 * current node pointed to by the specified BST iterator and advnce the
 * iterator to point to the next node in the BST (in in-order order).
 *
 * Because a function can't return two things, the key associated with the
 * current node should be returned the normal way, while its value should be
 * returned via the argument `value`.  Specifically, the argument `value`
 * is a pointer to a void pointer.  The current BST node's value (a void
 * pointer) should be stored at the address represented by `value` (i.e. by
 * dereferencing `value`).  This will look something like this:
 *
 *   *value = current_node->value;
 *
 * Parameters:
 *   iter - BST iterator.  The key and value associated with this iterator's
 *     current node should be returned, and the iterator should be updated to
 *     point to the next node in the BST (in in-order order).  May not be NULL.
 *   value - pointer at which the current BST node's value should be stored
 *     before this function returns.
 *
 * Return:
 *   This function should return the key associated with the current BST node
 *   pointed to by `iter`.
 */
int bst_iterator_next(struct bst_iterator* iter, void** value) {
  if (value) {
    *value = NULL;
  }
  return 0;
}
