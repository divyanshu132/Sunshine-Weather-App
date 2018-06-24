// Traverse a binary tree diagonally.

#include<iostream>
#include<map>
#include<vector>
using namespace std;

struct node
{
	int data;
	struct node *left, *right;
};


node* insert(node* root, int d)
{
	node* new_node=(node*)malloc(sizeof(node));
	new_node->data=d;
	new_node->left=NULL;
	new_node->right=NULL;

	if(root==NULL)
	{
		root=new_node;
		return root;
	}
	else
	{
		if(d < root->data)
		{
			root->left=insert(root->left, d);
		}
		else
			root->right=insert(root->right,d);
	}
}


void fillmap(node* root, map<int, vector<int>> &m, int index)
{
	if(root==NULL)
		return;
	m[index].push_back(root->data); // The diagonal elements of the tree will have same index in the map.

	fillmap(root->left, m, index+1);

	fillmap(root->right, m, index);
}


void diagonalTraversal(node* root)
{
	map<int, vector<int>> m;

	fillmap(root, m, 0);

	map<int, vector<int>> :: iterator it1;
	//map<int, vector<int>> :: iterator it2;
	for(it1=m.begin();it1!=m.end();it1++)
	{
		cout<<"index: "<<it1->first<<"\t";
		for(auto it2=it1->second.begin();it2!=it1->second.end();it2++)
			cout<< *it2<<" ";
		cout<<"\n";
	}

}

int main()
{
	int a[]={4,7,8,6,3};
	int n=sizeof(a)/sizeof(a[0]);
	node* root=insert(root, a[0]);
	for(int i=1;i<n;i++)
		insert(root,a[i]);
	

	diagonalTraversal(root);
}

