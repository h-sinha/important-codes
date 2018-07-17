#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
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
struct node
{
	int num;
	node *left;
	node *right;
};
std::vector<std::vector<int> > merge(std::vector<int> left,std::vector<int> right,std::vector<int> prefix)
{
	std::vector<std::vector<int> > results;
	// cout<<prefix[0]<<" "<<sz(left)<<" "<<sz(right)<<ln;
	if(sz(left)==0 || sz(right)==0 )
	{
		std::vector<int> v;
		v.insert(v.end(),all(prefix));
		v.insert(v.end(),all(left));
		v.insert(v.end(),all(right));
		results.pb(v);
		return results;
	}
	std::vector<std::vector<int> > tmp;
	int val = left[0];
	prefix.pb(val);
	left.erase(left.begin());
	tmp=merge(left,right,prefix);
	trace(tmp,x)results.pb(x);
	prefix.pop_back();
	left.insert(left.begin(), val);

	val=right[0];
	prefix.pb(val);
	right.erase(right.begin());
	tmp=merge(left,right,prefix);
	trace(tmp,x)results.pb(x);
	prefix.pop_back();
	right.insert(right.begin(), val);
	return results;
}
std::vector<std::vector<int> > func(node *root)
{
	std::vector< std::vector<int> > result;
	if(root==NULL)
	{
		return result;
	}
	std::vector<int> prefix;
	prefix.pb(root->num);
	// cout<<root->num;
	std::vector< std::vector<int> > left_result = func(root->left);
	std::vector< std::vector<int> > right_result = func(root->right);
	std::vector<std::vector<int> > tmp;
	if(sz(left_result)==0 && sz(right_result)==0)result.pb(prefix);
	// cout<<root->num<<" - "<< sz(left_result)<<" "<<sz(right_result)<<endl;
	trace(left_result,x)
	{
		trace(right_result,y)
		{
			tmp = merge(x,y,prefix);
			trace(tmp,z)result.pb(z);
		}
	}
	return result;
}
node *insert(node *root,int val)
{
	if(root==NULL)
	{
		node * tmp=new node();
		tmp->left=NULL;
		tmp->right=NULL;
		tmp->num=val;
		return tmp;
	}
	if(val<root->num)
		root->left=insert(root->left,val);
	else 
		root->right=insert(root->right,val);
	return root;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	node *root=NULL;
	 	root=insert(root,5);
	 	root=insert(root,2);
	 	root=insert(root,8);
	 	root=insert(root,1);
	 	root=insert(root,3);
	 	// root=insert(root,7);
	 	// root=insert(root,10);
	 	std::vector<std::vector<int> > v;
	 	v=func(root);
	 	trace(v,x)
	 	{
	 		trace(x,y)cout<<y<<" ";
	 		cout<<ln;
	 	}
		return 0;
}