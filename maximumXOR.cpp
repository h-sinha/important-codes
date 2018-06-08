#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"

#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
struct node
{
	node *child[2];
	int freq;
};
node *new_node()
{
	node *temp=new node();
	FOR(i,0,2)temp->child[i]=NULL;
	temp->freq=1;
	return temp;
}
void insert(node *root,int num)
{	
	RFOR(i,31,0)
	{
		int temp=1&(num>>i);
		if(root->child[temp]==NULL)
		{
			root->child[temp]=new_node();
			root=root->child[temp];
		}
		else
		{
			root=root->child[temp];
			root->freq++;
		}
	}
	return;
}
void remove(node *root,int num)
{
	RFOR(i,31,0)
	{
		int temp=(num>>i)&1;
		root=root->child[temp];
		root->freq--;
		// if(root->freq==0)delete root;
	}
}
int query(node *root,int num)
{
	int ans=0;
	RFOR(i,31,0)
	{
		int temp=1 & (num>>i);
		if(root->child[1-temp]!=NULL && root->child[1-temp]->freq>0){root=root->child[1-temp];ans+=(1-temp)<<i;}
		else {root=root->child[temp];ans+=temp<<i;}
	}	
	return ans^num;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n,q,num;
	 	char ch;
	 	cin>>q;
	 	node *root=new_node();
	 	insert(root,0);
	 	while(q--)
	 	{
			cin>>ch>>num;
			switch (ch)
			{
				case '+':
					insert(root,num);
					break;
				case '-':
					remove(root,num);
					break;
				case '?':
					cout<<query(root,num)<<ln;
					break;
			}	 		
	 	}
		return 0;
}