/* section 7 intro questions*/

#include <stdbool.h>
#include <stdio.h>
#include <cs50.h>



typedef struct node
{
    int num;
    struct node* left;
    struct node* right;

}
node;


// function prototypes
bool contains(int value);
bool insert(int value);
node* build(int num);

// declare root of tree as a global variable
node* root;

node* build(int num)
{
    node* new_node = malloc(sizeof(node));
    if (!new_node)
    {
        fprintf(stderr, "out of memory!\n");
        exit(1);
    }

    //initialise node
    
    new_node->num = num;
    new_node->left = NULL;
    new_node->right = NULL;   
    
        
    return new_node;
}



int main(void)
{
    // initialise root
    root = build(7);
    
    node* new_node = build(3);
    root->left = new_node;
    
    new_node = build(9);
    root->right = new_node;
    
    new_node = build(6);
    root->left->right = new_node;
    
    new_node = build(5);
    root->left->right->left = new_node;
    
    new_node = build(2);
    root->left->left = new_node;
    
    new_node = build(8);
    root->right->left = new_node;
    
    printf("contains?: ");
    int h = GetInt();
    
    bool present = insert(h);
    
    if(present)
        printf("found\n");
    
    else if (!present)
        printf("not found\n");
    

    return 0;
}

bool contains(int value)
{
    node* newptr = root;
    
    while(newptr !=NULL)
    {
        if(value == newptr->num)
            return true;
        
        else  if(value > newptr->num)
            newptr = newptr->right;
            
        else
            newptr = newptr->left;
    }

    return false;
}

bool insert(int value)
{
    node* newptr = root;
    
    while(newptr !=NULL)
    {
        if(value == newptr->num)
            return false;
        
        if(value > newptr->num && newptr->right !=NULL)
            newptr = newptr->right;
        
        else if(value < newptr->num && newptr->left !=NULL)
            newptr = newptr->left;
        
        else if(value < newptr->num)
        {    
            node* new_node = build(value);
            newptr->left = new_node;
            return true;
        }
        
        else if(value > newptr->num)
        {
            node* new_node = build(value);
            newptr->right = new_node;
            return true;
        }   
    }
    
    return false;
}
