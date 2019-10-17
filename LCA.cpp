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
std::vector<int> adj[L];
int level[L],u[L],v[L],parent[L][22],mark[L];
void dfs(int vertex,int pr,int lvl)
{
	parent[vertex][0]=pr;
	level[vertex]=lvl;
	for(auto &x:adj[vertex])
		if(x!=pr)dfs(x,vertex,lvl+1);
}
int lca(int a,int b)
{
	if(level[a]>level[b])swap(a,b);
	int dist=level[b]-level[a];
	int index=0;
	while(dist>0)
	{
		if(dist&1)b=parent[b][index];
		dist>>=1;index++;
	}
	
	RFOR(i,18,0)
	{
		if(parent[a][i]!=-1 && parent[a][i]!=parent[b][i])
		{
			a=parent[a][i];
			b=parent[b][i];
		}
	}
	if(a==b)return a;
	return parent[a][0];
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	FOR(i,0,n-1)
	 	{
	 		cin>>u[i]>>v[i];
	 		adj[u[i]].pb(v[i]);
	 		adj[v[i]].pb(u[i]);
	 	}
	 	dfs(1,-1,0);
	 	FOR(j,1,19)
	 		FOR(i,1,n+1)
	 			if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
		return 0;
}
