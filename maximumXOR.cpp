#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#ifdef DEBUG
#define debug(...) __f(#__VA_ARGS__, __VA_ARGS__)
	template <typename Arg1>
	void __f(const char* name, Arg1&& arg1){
		cerr << name << " : " << arg1 << std::endl;
	}
	template <typename Arg1, typename... Args>
	void __f(const char* names, Arg1&& arg1, Args&&... args){
		const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
	}
#else
#define debug(...)
#endif
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
map<ll,ll> counter;
ll fastexpo(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}
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
	}
}
int query(node *root,int num)
{
	int ans=0;
	RFOR(i,31,0)
	{
		int temp=1 & (num>>i);
		if(root->child[1-temp]!=NULL && root->child[1-temp]->freq>0)
		{
			root=root->child[1-temp];
			ans+=(1-temp)<<i;
		}
		else 
		{
			root=root->child[temp];
			ans+=temp<<i;
		}
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