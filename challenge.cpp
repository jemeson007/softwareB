#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <vector>
using namespace std;

struct node {
    int data;
    int employeeId;
    int managerId;
 	char* superHero;
    struct node* left;
    struct node* right;
    struct node* parent;
};
	struct node* root;
  
//function declaration

struct node *find(struct node* root, int value) ; //to find a node
struct node* NewNode(int data, char superHero); //helper function to create a new node
struct node* insert(struct node* node, int data); // to insert a new node

struct node* buildTestTree(); //test case to build Tree
struct node* buildRealTree(); //case for the real SuperHeroes Tree
void printTree(struct node* node); //print out the nodes 
void printPaths(node* root, node* one, node* two); //prints the shortest paths between node and root


//Main function
int main(int argc, char const *argv[])
{

	/* code */
	//struct node* root = buildTestTree();
	root = buildRealTree();
//	cout << printTree(root) << endl;
	 printTree(root);
	// find(root, 6);
//	 printPaths(node *dangerMouse, node *catWoman, node *hitGirl);
	return 0;
}

//function definitions

//helper function to find the data to input into Lowest Common Ancestor
struct node* find(struct node* root, int value) {
  std::vector<node*> v;
  if (root == NULL) {
    return(NULL);
  }
     	//checks the left subtree
   if (value < root->data) 
   return(find(root->left, value));
		//checks the right subtree
   else if(value > root->data)
   return(find(root->right, value));

    	v.push_back(root);
    	return root;
  
}
  
  //helper function that creates a new node
struct node* NewNode(int data, int employeeId, int managerId, char* superHero) {
struct node* node = new(struct node);    //
node->data = data;
node->employeeId = employeeId;
node->managerId = managerId;
node->superHero = superHero;
node->left = NULL;
node->right = NULL;
node->parent = NULL;
return(node);
}
  

// struct node* insert(struct node* node, int data) {
//   // 1. If the tree is empty, return a new, single node
//   if (node == NULL) {
//     return(NewNode(data));
//   }
//   else {
//     // 2. Otherwise, recur down the tree
//     if (data <= node->data) node->left = insert(node->left, data);
//     else node->right = insert(node->right, data);

//     return(node); // return the (unchanged) node pointer
//   }
// } 

// struct node* buildTestTree(){
// 	struct node* root =  NewNode(2);
// 	struct node* leftChild =  NewNode(1);
// 	struct node* rightChild =  NewNode(3);

// 	root->left = leftChild;
// 	root->right = rightChild;

// 	return (root);
// }

struct node* buildRealTree(){
	struct node* dangerMouse = NewNode(5, 1, 0, "Danger Mouse");
	struct node* gonzoTheGreat = NewNode(4, 2, 1, "Gonzo the Great");
	struct node* blackWidow = NewNode(2, 6, 2, "Black Widow");
	struct node* batman = NewNode(1, 16, 6, "Batman");
	struct node* catWoman = NewNode(3, 17, 6, "Catwoman");
	struct node* invisibleWoman = NewNode(7, 3, 1, "Invisible Woman");
	struct node* hitGirl = NewNode(6, 12, 3, "Hit Girl");
	struct node* superTed = NewNode(8, 15, 3, "Super Ted");

	dangerMouse->left = gonzoTheGreat;
	dangerMouse->right = invisibleWoman;
	dangerMouse->parent = NULL;

	gonzoTheGreat->left = blackWidow;
	gonzoTheGreat->right = NULL;
	gonzoTheGreat->parent = dangerMouse;

	blackWidow->left = batman;
	blackWidow->right = catWoman;
	blackWidow->parent = gonzoTheGreat;

	batman->left = NULL;
	batman->right = NULL;
	batman->parent = blackWidow;

	catWoman->left = NULL;
	catWoman->right = NULL;
	catWoman->parent = blackWidow;

	invisibleWoman->right = superTed;
	invisibleWoman->left = hitGirl;
	invisibleWoman->parent = dangerMouse;

	hitGirl->left = NULL;
	hitGirl->right = NULL;
	hitGirl->parent=invisibleWoman;

	superTed->left = NULL;
	superTed->right = NULL;
	superTed->parent=invisibleWoman;

	return(dangerMouse);


};

//prints out the nodes inorder traversal
void printTree(node* node) {
  if (node == NULL) return;

   	printTree(node->left);

 	printf("%s(%d) ->",node->superHero, node->employeeId);
 //	cout << *node << "("<<node->employeeId <<")";
    printTree(node->right);
 } 

 //print out path between nodes and root
 void printPaths(node* root, node* one, node* two){
  std::vector<node*> v;
  struct node* temp;
  //base case
  if(root== NULL || one == NULL || two == NULL) return;

//to find the LCA
 // when LCA is root
  while(root!=NULL){
  if(((root->data >= one->data)&&(root->data <= two->data)) ||
  	((root->data <= one->data)&&(root->data >= two->data)))
  	break;

  //when LCA node is to the left of the root
  if(root->data>one->data)
  	root=root->left;

  	//when LCA node is to the right of the root
  if(root->data < one->data)
  	root=root->right;
}
//print path to node one
	
	while(true){
		temp = root;
		if(temp=NULL) return;
		
		//at node one
		if(temp->data == one->data) break;
		else if(temp->data > one->data){
		//	v.push_back(one->data);
			printf("-> %s (%d)", one->superHero, one->employeeId);
			temp = temp->left;
		}else{
			printf("->%s(%d)", one->superHero, one->employeeId);
		//	v.push_back(one->data);
			temp = temp->right;
		}

	}

	//print path to node two
	while(true){
		temp = root;
		if(temp=NULL) return;
		
		//at node two
		if(temp->data == two->data) break;
		else if(temp->data > two->data){
			//v.push_back(two->data);
			printf(" <- %s (%d)", one->superHero, one->employeeId);
			temp = temp->left;
		}
		else{
			printf("<-%s(%d)", one->superHero, one->employeeId);
			//v.push_back(two->data);
			temp = temp->right;
		}	
	}

 }








