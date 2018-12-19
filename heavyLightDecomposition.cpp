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

const int N=2e5+7;
vector <int> adj[N],  indexx[N];
std::vector<ld> costs[N];
ld baseArray[N];
int ptr;
int chainNo, chainIndex[N], chainHead[N], posInBase[N];
int depth[N], parent[N][25], otherEnd[N], subsize[N];
ld seg[N*6];
void build(int s = 0, int e = ptr, int index = 1) 
{
	if(s == e-1) 
	{
		seg[index] = baseArray[s];
		return;
	}
	int mid = (s+e)>>1;
	build(s, mid, index<<1);
	build(mid, e, (index<<1)+1);
	seg[index]=(seg[index<<1] *seg[(index<<1)+1]);
}
void updateseg(int pos, ld val, int s = 0, int e = ptr, int index = 1) 
{
	if(s > pos || e <= pos) return;
	if(s == pos && s == e-1) 
	{
		seg[index] = val;
		return;
	}
	int mid = (s+e)>>1;
	updateseg(pos, val, s, mid, index<<1);
	updateseg(pos, val, mid, e, (index<<1)+1);
	seg[index] = (seg[index<<1] * seg[(index<<1)+1]);
	return;
}
ld queryseg(int l, int r, int s = 0, int e = ptr, int index = 1) 
{
	if(s >= r || e <= l) 
		return 1.0;
	if(s >= l && e <= r) 
		return seg[index];
	int mid = (s+e)>>1;
	ld query_left = queryseg(l, r, s, mid, index<<1);
	ld query_right = queryseg(l, r, mid, e, (index<<1)+1);
	return query_left * query_right;
}
ld queryup(int u, int v) 
{
	if(u == v) return 1;
	int uchain, vchain = chainIndex[v];
	ld ans = 1.0;
	while(1) 
	{
		uchain = chainIndex[u];
		if(uchain == vchain) 
		{
			if(u == v) break;
			return ans *= queryseg(posInBase[v]+1,posInBase[u]+1);
		}
		ans *= queryseg(posInBase[chainHead[uchain]],posInBase[u]+1);
		u = chainHead[uchain]; 
		u = parent[u][0]; 
	}
	return ans;
}
 
int LCA(int u, int v) 
{
	if(depth[u] > depth[v])swap(u,v);
	int dist = depth[v] - depth[u];
	int index = 0;
	while(dist > 0)
	{
		if(dist & 1)v = parent[v][index];
		dist >>= 1;
		index++;
	}
	
	RFOR(i,19,0)
	{
		if(parent[u][i]!=-1 && parent[u][i]!=parent[v][i])
		{
			u=parent[u][i];
			v=parent[v][i];
		}
	}
	if(u == v)return u;
	return parent[u][0];
}
void query(int u, int v,ld val) 
{
	int lca = LCA(u, v);
	ld ans = queryup(u,lca);
	ld temp = queryup(v,lca);
	cout<<ll(floor(floor(val/ans)/ temp))<<ln;
}
void change(int i, ld val) 
{
	int u = otherEnd[i];
	updateseg(posInBase[u], val);
}
void HLD(int curNode, ld cost, int prev) 
{
	if(chainHead[chainNo] == -1) 
	{
		chainHead[chainNo] = curNode; 
	}
	chainIndex[curNode] = chainNo;
	posInBase[curNode] = ptr; 
	baseArray[ptr++] = cost;
 
	int special = -1;
	ld ncost;
	FOR(i,0,sz(adj[curNode]))
	{
		if(adj[curNode][i] != prev) 
		{
			if(special == -1 || subsize[special] < subsize[adj[curNode][i]]) 
			{
				special = adj[curNode][i];
				ncost = costs[curNode][i];
			}
		}
	}
 
	if(special != -1) 
		HLD(special, ncost, curNode);
 
	FOR(i,0,sz(adj[curNode]))
	{ 
		if(adj[curNode][i]!=prev && special!=adj[curNode][i]) 
		{
			chainNo++;
			HLD(adj[curNode][i], costs[curNode][i], curNode);
		}
	}
	return;
}
void dfs(int vertex,int prev,int _depth) 
{
	parent[vertex][0] = prev;
	depth[vertex] = _depth;
	subsize[vertex] = 1;
	FOR(i,0,sz(adj[vertex]))
	{
		if(adj[vertex][i] != prev) 
		{
			otherEnd[indexx[vertex][i]] = adj[vertex][i];
			dfs(adj[vertex][i],vertex, _depth+1);
			subsize[vertex] += subsize[adj[vertex][i]];
		}
	}
}
int main() 
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL),cout.tie(NULL);

	int t,u,v,n,type;
	ld c;
	cin >> n >> t;
	ptr = 0;
	FOR(i,0,n)
	{
		chainHead[i] = -1;
		FOR(j,0,20)parent[i][j] = -1;
	}
	FOR(i,1,n)
	{
		cin >> u >> v >> c;
		u--,v--;
		adj[u].push_back(v);
		costs[u].push_back(c);
		indexx[u].push_back(i-1);
		adj[v].push_back(u);
		costs[v].push_back(c);
		indexx[v].push_back(i-1);
	}
	chainNo = 0;
	dfs(0, -1,0); 
	HLD(0, -1, -1); 
	build(); 
	FOR(j,1,20)
 		FOR(i,1,n+1)
 			if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
	while(t--)
	{
		cin >> type;
		if(type == 1)
		{
			cin >> u >> v >> c;
			query(--u,--v,c);
		}
		else
		{
			cin >> u >> c;
			change(--u,c);
		}
	}
	return 0;
} 