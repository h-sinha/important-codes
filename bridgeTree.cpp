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
std::vector<int> adj[L], bridge_tree[L]; // graph, bridge tree
bool visit1[L], visit0[L]; // visit array for both dfs
int start, ar[L]; // stores visit time
int u[L], v[L]; // storing original graph
int cur_comp, comp[L]; // for components in bridge tree
int isBridge[L]; //stores if edge is bridge or not
queue<int>q[L]; // queue for performing bfs

// finds adjacent vertex
int find_next(int i,int vertex)
{
	return ((u[i] == vertex) ? v[i] : u[i]);
}
// finds all bridges
int dfs0(int vertex, int edge)
{
	ar[vertex] = ++start;
	int cur = ar[vertex], e, nxt;
	visit0[vertex] = 1;
	FOR(i,0,sz(adj[vertex]))
	{
		e = adj[vertex][i];
		nxt = find_next(e, vertex);
		if(!visit0[nxt])
			cur = min(cur, dfs0(nxt, e));
		else if(e != edge) 
			cur = min(cur, ar[nxt]);
	}
	if(ar[vertex] == cur && edge != -1)
	{
		isBridge[edge] = 1;
	}
	return cur;
}

// makes bridge tree
void dfs1(int vertex)
{
	visit1[vertex] = 1;
	comp[vertex] = ++cur_comp;
	q[vertex].push(vertex);
	int tmp, e, nxt;
	while(!q[vertex].empty())
	{
		tmp = q[vertex].front();
		comp[tmp] = comp[vertex];
		q[vertex].pop();
		FOR(i,0,sz(adj[tmp]))
		{
			e = adj[tmp][i];
			nxt = find_next(e, tmp);
			if(visit1[nxt])continue;
			if(isBridge[e])
			{
				bridge_tree[comp[vertex]].pb(cur_comp + 1);
				bridge_tree[cur_comp + 1].pb(comp[vertex]);
				dfs1(nxt);
			}
			else 
			{
				q[vertex].push(nxt);
				visit1[nxt] = 1;
			}
		}
	}
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a, b, n, m;
	 	cin >> n >> m;
	 	FOR(i,1,m+1)
	 	{
	 		cin >> a >> b;
	 		u[i] = a;
	 		v[i] = b;
	 		adj[a].pb(i);
	 		adj[b].pb(i);
	 	}
	 	FOR(i,1,n+1)
	 	{
	 		if(!visit0[i])
	 			dfs0(i, -1);
	 	}
	 	FOR(i,1,n+1)
	 	{
			if(!visit1[i])
	 			dfs1(i);
	 	}
		return 0;
}