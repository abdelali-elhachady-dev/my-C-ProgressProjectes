#include <stdio.h>
#include <stdlib.h>

 struct node {
    int data ; 
    struct node * left ;
    struct node * right ;
};
 typedef struct node NODE;

 NODE * FindMin( NODE * head){
    while(head->left != NULL){
        head = head->left;
    }
    return head ;
}

NODE * create ( int data  )
{
    NODE * newnode =(NODE *) malloc(sizeof(NODE));
    newnode->data = data ; 
    newnode->left = NULL ; 
    newnode->right = NULL ; 

return newnode ;
}

NODE* insert (NODE *HEAD , int data )
 {
    
    if( HEAD == NULL){
    return create(data);
 }
    if (HEAD->data > data){
      HEAD->left =  insert(HEAD->left , data);
    }else if( HEAD->data < data){
      HEAD->right =  insert(HEAD->right , data);
    }
    return HEAD ;

 }
NODE* search (NODE * head , int data )
{
    if ( head->data == data || head == NULL ){
      return head ;
    }
    if (head->data > data){
     return   search(head->left , data);
    }else{
     return   search(head->right , data);
    }
}


NODE* Delete(NODE* root, int data) {
    if (root == NULL) {
        printf("The value doesn't exist\n");
        return NULL;
    }

    if (data < root->data)
        root->left = Delete(root->left, data);
    else if (data > root->data)
        root->right = Delete(root->right, data);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            NODE* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            NODE* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children
        NODE* temp = FindMin(root->right);
        root->data = temp->data;
        root->right = Delete(root->right, temp->data);
    }
    return root;
}



 void inOrder( NODE * head ){
    if ( head == NULL)
    {
        return ;
    }
        inOrder(head->left);
        printf("%d\n",head->data);
        inOrder(head->right);
 }
int main ()
{

    NODE * head = NULL ;
     head = insert( head , 55 );
      insert( head , 3 );
      insert( head , 2 );
      insert( head , 5 );
      insert( head , 995 );
      insert( head , 34 );
      insert( head , 31 );

    inOrder(head);
   head = Delete(head , 995);
        inOrder(head);

    return 0;
}