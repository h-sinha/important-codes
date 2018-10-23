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
int timeis=1,m=1;
std::vector<int> v[100002];
std::vector<bool> visit(100002);
int distanceroot[100002],start[100002],arr[100002];
int modu=1000000007;
std::vector<int> aux[400002];
void build(int s,int e,int index)
{
	if(s>=e)
	{
		aux[index].pb(distanceroot[arr[s]]);
		return;
	}
	int mid=(s+e)/2;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	FOR(i,0,sz(aux[index<<1]))
		aux[index].pb(aux[index<<1][i]);
	FOR(i,0,sz(aux[(index<<1)+1]))
		aux[index].pb(aux[(index<<1)+1][i]);
	sort(aux[index].begin(), aux[index].end());
	return;
}
int query(int s,int e,int l,int r,int x,int index)
{
	if(e<l || s>r )return 0;
	if(s>=l && e<=r)
	{
		int ans=0;
		std::vector<int> ::iterator it;
		return upper_bound(aux[index].begin(), aux[index].end(),x)-lower_bound(aux[index].begin(), aux[index].end(),x);
	}
	int mid=(s+e)/2;
	int q1=query(s,mid,l,r,x,index<<1);
	int q2=query(mid+1,e,l,r,x,(index<<1)+1);
	return q1+q2;
}
int dfs(int vertex,int parent, int vertex)
{
	start[vertex]=timeis;
	arr[timeis]=vertex;
	timeis++;
	distanceroot[vertex]=dist+1;
	trace(v[vertex],x)
	{
		if(x==parent)continue;
		dfs(x, vertex, dist+1);
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,n,b;
	cin>>n;
	FOR(i,0,n-1)
	{
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,-1,-1);
	build(1,timeis-1,1);
	return 0;
}
