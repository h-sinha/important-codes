#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e6+7;
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
int children[L], comp[L], parent[L];
int component(int x)
{
	if(parent[x] == x)return x;
	return parent[x] = component(parent[x]);
}
void merge(int a, int b)
{
	int pa = component(a);
	int pb = component(b);
	if(children[pa] > children[pb])
	{
		children[pb] += children[pa];
		parent[pa] = pb;
	}
	else
	{
		children[pa] += children[pb];
		parent[pb] = pa;
	}
	return;
}
int main()
{
	int n, m, a, b, type;
	cin >> n ;
	for (int i = 1; i <= n ; ++i)
	{
		parent[i] = i;
		children[i] = 1;
	}
	for (int i = 0; i < 10; ++i)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> a >> b;
			merge(a, b);
		}
		else 
		{
			cin >> a;
			cout<<component(a)<<endl;
		}
	}
}