#include<iostream>
using namespace std;

struct node
{
int Key_Value;
node* Left;
node* Right;
};

class btree
{
public:
btree();
~btree();

void insert(int key);
node* search(int key);
void destroy_tree();

private:
void insert(int key, node* leaf);
node* search(int key, node* leaf);
void destroy_tree(node* leaf);

node* root;
};

btree::btree()
{
root = NULL;
}

btree::~btree()
{
destroy_tree();
}


void btree::insert(int key, node* leaf)
{
if (key < leaf->Key_Value)
{
    if (NULL != leaf->Left)
    {
        insert(key, leaf->Left);
    }
    else
    {
        leaf->Left = new node;
        leaf->Left->Key_Value = key;
        leaf->Left->Left = NULL;
        leaf->Left->Right = NULL;
    }
}
else
{
     if (NULL != leaf->Right)
     {
          insert(key, leaf->Right);
     }
     else
     {
          leaf->Right = new node;
          leaf->Right->Key_Value = key;
          leaf->Right->Left = NULL;
          leaf->Right->Right = NULL;
     }
}
}

void btree::insert(int key)
{
if (root == NULL)
{
root = new node;
root->Key_Value = key;
root->Left= NULL;
root->Right=NULL;
}
else
{

insert(key, root);
}
}


node* btree::search(int key, node* leaf)
{
if (NULL != leaf)
{
   if (leaf->Key_Value == key)
   {
        return leaf;
   }
   else if (leaf->Key_Value > key)
   {
        search(key, leaf->Left);
   }
   else
   {
        search(key, leaf->Right);
   }
}
}


node* btree::search(int key)
{
search(key, root);
}

void btree::destroy_tree(node* leaf)
{
if (NULL != leaf)
{
destroy_tree(leaf->Left);
destroy_tree(leaf->Right);
delete leaf;
}
}

void btree::destroy_tree()
{
destroy_tree(root);
}


int main()
{
int a[7]={10, 6, 14, 5, 8, 11, 18};

btree* pbtree = new btree();

for (int i=0; i<7; i++)
{
pbtree->insert(a[i]);
}

node* res = pbtree->search(11);

cout<<res->Key_Value<<endl;


return 0;
}
