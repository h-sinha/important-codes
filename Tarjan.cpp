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
#define sz(a)	int(a.size())
#define F first
#define S second
#define aint(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<int,int>
typedef long double ld;
typedef long long int  ll;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;

// typedef tree<int,nuint_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smaintest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e5+7;
int id[L],lowLink[L];
stack <int> STACK;
std::vector<int> v[L];
std::vector<bool> visit(L);
int start, mod = 1e9+7, onStack[L], cost[L];

void dfs(int vertex, int parent)
{
	onStack[vertex] = 1;
	id[vertex] = lowLink[vertex] = ++start;
	STACK.push(vertex);
	visit[vertex] = 1;
	trace(v[vertex], x)
	{
		if(visit[x])
		{
			if(onStack[x])
			lowLink[vertex] = min(lowLink[vertex], id[x]);
			continue;
		}
		dfs(x, vertex);
		lowLink[vertex] = min(lowLink[vertex], lowLink[x]);
	}
	if(id[vertex] == lowLink[vertex])
	{
		int tmp;
		while(!STACK.empty())
		{
			tmp = STACK.top();
			lowLink[tmp] = min(lowLink[tmp], lowLink[vertex]);
			STACK.pop();
			onStack[tmp] = 0;
			cout<<tmp<<" ";
			if(tmp == vertex)break;
		}
		cout<<ln;
	}	
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL), cout.tie(NULL);
		int n, m, a, b;
		cin >> n >> m;
		FOR(i,0,m)
		{
			cin >> a >> b;
			v[a].pb(b);
		}
		FOR(i,1,n+1)
			if(!visit[i])
				dfs(i, -1);
		return 0;
}