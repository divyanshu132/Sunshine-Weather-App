// choose items such that the cost is minimum.

#include<iostream>
#include<map>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,q;
	cin>>n>>q;
	int a[n];
	for(int i=0;i<n;i++)
		cin>>a[i];

	int last=0;
	while(q)
	{
		int x,y,z;
		cin>>x>>y>>z;

		int l=((x+last)%n)+1;
		int r=((y+last)%n)+1;
		//cout<<"l: "<<l<<"r: "<<r<<"\n";
		int k=0;int b[r-l+1];
		for(int i=l-1;i<r;i++)
		{
			b[k]=a[i];
			k++;
		}
		int sum=0;
		map<int, vector<int>> ma;int f=1;
		for(int i=0;i<(int) pow(2, k);i++)
		{
			int pro=1;int c=0;
			for(int j=0;j<k;j++)
			{
				if((i & (1<<j))!=0)
					{
						ma[f].push_back(b[j]);
					}
			}
			f++;
		}
		int pro=1;sum=0;
		for(auto it=ma.begin();it!=ma.end();it++)
		{
			pro=1;
			 //i=it->second.size();
			if(it->second.size()==z)
			{
				for(auto itr=it->second.begin();itr!=it->second.end();itr++)
				{
					int x=*itr;
					pro=pro*x;
				}
				sum=sum+pro;
			}
		}
		cout<<sum<<"\n";
		last=sum;
		q--;
	}
}

