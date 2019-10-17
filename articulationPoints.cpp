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
int lowLink[L], id[L];
int start, rootOutEdge;
std::vector<int> v[L]; 
std::vector<int> visit(L), ans(L);
void articulationPoints(int root, int vertex, int parent)
{
	if(parent == root)rootOutEdge++;
	lowLink[vertex] = id[vertex] = ++start;
	visit[vertex] = 1;
	trace(v[vertex], x)
	{
		if(x == parent)continue;
		if(visit[x])
		{
			lowLink[vertex] = min(lowLink[vertex], id[x]);
			continue;
		}
		articulationPoints(root, x, vertex);
		lowLink[vertex] = min(lowLink[vertex], lowLink[x]);
		if(id[vertex]<=lowLink[x] && vertex!=root)
		{
			ans[vertex] = 1;
		}
	}
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		int n, m, a, b, co;
		cin >> n >> m;
		FOR(i,0,m)
		{
			cin >> a >> b;
			v[a].pb(b);
			v[b].pb(a);
		}
		FOR(i, 1, n+1)
		{
			if(!visit[i])
			{
				rootOutEdge = 0;
				articulationPoints(i, i, -1);
				if(rootOutEdge > 1)ans[i] = 1;
			}
		}
		cout<<"Total number of articulation points = "<<accumulate(all(ans), 0)<<ln;
		FOR(i,1,n+1)
			if(ans[i])cout<<i<<" ";
		return 0;
}