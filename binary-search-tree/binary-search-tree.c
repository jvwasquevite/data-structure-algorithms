#include <stdio.h>
#include <stdlib.h>

struct content {
  int key;
};

struct node {
  struct content cont;
  struct node *left;
  struct node *right;
};

struct node *tree;
void initialize_tree(struct node *);
void display(struct node *);

// Basic operations
struct node *INSERT(struct node *);
struct node *DELETE(struct node *);
void PREORDER(struct node *);
void INORDER(struct node *);
void POSTORDER(struct node *);

int main(int argc, char *argv[]) {
  int option;

  printf("0: Add new nodes\n");
  printf("1: Delete node\n");
  printf("3: Display tree\n");
  printf("4: Exit\n");

  // Initialize tree
  initialize_tree(tree);
  struct node *insertElement(struct node *, int);

  do {
    printf("\nEnter your option: ");
    scanf("%d", &option);
    getchar();
    printf("\n");
    
		switch(option) {
      case 0: tree = INSERT(tree);
			break;
      case 1: tree = DELETE(tree);
			break;
      case 3: display(tree);
			break;
		}
  } while(option != 4);
  getchar();
  
  return 0;
}

void initialize_tree(struct node *tree) {
  tree = NULL;
}

struct node *INSERT(struct node *tree) {
  struct node *new_node, *nodeptr, *parentptr;

  // Allocating memory for a new node
  new_node = (struct node*)malloc((sizeof(struct node)));

  if(!new_node){
      printf("Memory allocation error.\n");
      exit(1);
  }

  printf("Type the key: ");
  scanf("%d", &new_node->cont.key);
  getchar();

  new_node->left = NULL;
  new_node->right = NULL;

  if(tree == NULL) { // First insertion
    tree = new_node;
    tree->left = NULL;
    tree->right = NULL;
  } else {
    parentptr=NULL;
		nodeptr=tree;

    while(nodeptr != NULL) {
      parentptr = nodeptr;

      if(new_node->cont.key < nodeptr->cont.key) {
        nodeptr = nodeptr->left;
      } else {
        nodeptr = nodeptr->right;
      }
    }

    if(new_node->cont.key < parentptr->cont.key) {
      parentptr->left = new_node;
    } else {
      parentptr->right = new_node;
    }
  }

  return tree;
}

struct node *DELETE(struct node *tree) {
  struct node *cur, *parent, *suc, *psuc, *ptr;
  int key;

  printf("Type the key to delete: ");
  scanf("%d", &key);
  getchar();

  if(tree->left == NULL) { // Empty error
    printf("Tree is empty.\n");
    return(tree);
  }

  parent = tree;
  cur = tree->left;

  while(cur != NULL && key != cur->cont.key) {
    parent = cur;
    
    if(key < cur->cont.key) {
      cur = cur->left;
    } else {
      cur = cur->right;
    }
  }

  if(cur == NULL) { // Inexistent key errpr
    printf("Key not found\n");
    return(tree);
  }

  if(cur->left == NULL) {
    ptr = cur->right;
  } else if (cur->right == NULL) {
    ptr = cur->left;
  } else {
    // Finding in-order successor + parent
    psuc = cur;
    cur = cur->left;

    while(suc->left != NULL) {
      psuc = suc;
      suc = suc->left;
    }

    if(cur == psuc) { // Situation 1
      suc->left = cur->right;
    } else { // Situation 2
      suc->left = cur->left;
      psuc->left = suc->right;
      suc->right = cur->right;
    }
    ptr = suc;
  }

  // Attaching ptr to parent node
  if(parent->left == cur) {
    parent->left = ptr;
  } else {
    parent->right = ptr;
  }

  free(cur);
  return tree;
}

void display(struct node *tree) {
  int option;

  printf("0: PREORDER\n1: INORDER\n2: POSTORDER\n");
   printf("\nEnter your option: ");
  scanf("%d", &option);
  getchar();
  printf("\n");
  
  switch(option) {
    case 0: PREORDER(tree);
    break;
    case 1: INORDER(tree);
    break;
    case 2: POSTORDER(tree);
    break;
  }
}

void PREORDER(struct node *tree) {
  if(tree != NULL) {
    printf("[%d]\n", tree->cont.key);
    PREORDER(tree->left);
    PREORDER(tree->right);
  }
}

void INORDER(struct node *tree) {
  if(tree != NULL) {
    INORDER(tree->left);
    printf("[%d]\n", tree->cont.key);
    INORDER(tree->right);
  }
}

void POSTORDER(struct node *tree) {
  if(tree != NULL) {
    POSTORDER(tree->left);
    POSTORDER(tree->right);
    printf("[%d]\n", tree->cont.key);
  }
}