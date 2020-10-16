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

int HeightOfTree(node* root) 
{ 
    if (root == NULL) 
	{  return 0;} 
  
    int lheight = HeightOfTree(root->left); 
    int rheight = HeightOfTree(root->right); 
  
    return max(lheight + 1, rheight + 1); 
} 
  
void Print_Level_Right_To_Left(node* root, int level) 
{ 
    if (root == NULL) 
	{return; }
  
    if (level == 1) 
	{ cout << root->data << " "; }
  
    else if (level > 1) { 
        Print_Level_Right_To_Left(root->right, level - 1); 
        Print_Level_Right_To_Left(root->left, level - 1); 
    } 
} 
  
void Print_Level_Left_To_Right(node* root, int level) 
{ 
    if (root == NULL) 
	{return;} 
  
    if (level == 1) 
	{cout << root->data << " "; }
  
    else if (level > 1) { 
        Print_Level_Left_To_Right(root->left, level - 1); 
        Print_Level_Left_To_Right(root->right, level - 1); 
    } 
} 
  
void PrintReverseZigZag(node* root) 
{ 
    int flag = 1; 
  
    int height = HeightOfTree(root); 
  
    for (int i = height; i >= 1; i--) { 
        if (flag == 1) { 
            Print_Level_Right_To_Left(root, i); 
            flag = 0; 
        } 
        else if (flag == 0) { 
            Print_Level_Left_To_Right(root, i); 
            flag = 1; 
        } 
    } 
}
void printPostorder(node* root) 
{ 
    if (root == NULL) 
	{return;} 
 
    printPostorder(root->left); 
 
    printPostorder(root->right); 
  
    cout << root->data << " "; 
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
   cout<<"The post-order traversal:"<<endl;
   printPostorder(root);
   cout<<endl;
   cout<<"The pre-order traversal is"<<endl;
   printPreorder(root);
   cout<<endl;
   cout<<"The zig-zag traversal of the binary tree is: "<<endl;
   zigzagtraversal(root);
   cout<<endl;
   cout<<"The Reverse zig-zag traversal is:"<<endl;
   PrintReverseZigZag(root);

   
   return 0;
}
