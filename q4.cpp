#include <bits/stdc++.h> 
using namespace std; 

class node  
{  
    public: 
    int data;  
    node* left;  
    node* right;  
};  

int max(vector<int> inorder, int strt, int end);  
  
node* newNode(int data);  

node* buildTree (vector<int> inorder, int start, int end)  
{  
    if (start > end)  
        return NULL;  
  
    int i = max (inorder, start, end);  
  
    node *root = newNode(inorder[i]);  

    if (start == end)  
        return root;  
  
    root->left = buildTree (inorder, start, i - 1);  
    root->right = buildTree (inorder, i + 1, end);  
  
    return root;  
}  
  

int max (vector<int> arr, int strt, int end)  
{  
    int i, max = arr[strt], maxind = strt;  
    for(i = strt + 1; i <= end; i++)  
    {  
        if(arr[i] > max)  
        {  
            max = arr[i];  
            maxind = i;  
        }  
    }  
    return maxind;  
}  
  
node* newNode (int data)  
{  
    node* Node = new node(); 
    Node->data = data;  
    Node->left = NULL;  
    Node->right = NULL;  
  
    return Node;  
}  

void printPreorder(node* node) 
{ 
    if (node == NULL) 
        return; 
  
    cout << node->data << " "; 
    printPreorder(node->left);  
    printPreorder(node->right); 
}  

void zigzagtraversal(node* root) 
{  
  if (root==NULL) 
    return; 
 
  stack<node*> currentlevel; 
  stack<node*> nextlevel; 

  currentlevel.push(root); 

  bool lefttoright = true; 
  while (!currentlevel.empty()) { 
 
    node* temp = currentlevel.top(); 
    currentlevel.pop(); 

    if (temp) { 

      cout << temp->data << " "; 

      if (lefttoright) { 
        if (temp->left) 
          nextlevel.push(temp->left); 
        if (temp->right) 
          nextlevel.push(temp->right); 
      } 

      else { 
        if (temp->right) 
          nextlevel.push(temp->right); 
        if (temp->left) 
          nextlevel.push(temp->left); 
      } 
    } 

    if (currentlevel.empty()) { 
      lefttoright = !lefttoright; 
      swap(currentlevel, nextlevel); 
    } 
  } 
} 

int main()
{
	vector<int> vec;
   ifstream indata; 
   int num; 
   string name;
   cout<<"Enter name of file to read input from. For example: input.txt\n";
   cin>>name;
indata.open(name);
   if(!indata) { 
      cerr << "Error: file could not be opened" << endl;
      exit(1);
   }
indata >> num;
   while ( !indata.eof() ) { 
      //cout << "The next number is " << num << endl;
   	vec.push_back(num);
      indata >> num; 
   }
   indata.close();
   node *root = buildTree(vec, 0, vec.size() - 1);  
   printPreorder(root);
   zigzagtraversal(root);
   return 0;
}
