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
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
std::vector<int> org[L],rev[L];
stack <int> STACK;
std::vector<bool> visit(L),visit1(L);
void dfs(int vertex)
{
	if(visit[vertex])return;
	visit[vertex]=1;
	trace(org[vertex],x)
		dfs(x);
	STACK.push(vertex);
	return;
}
void component(int vertex)
{
	if(visit1[vertex])return;
	cout<<vertex<<" ";
	visit1[vertex]=1;
	trace(rev[vertex],x)
		component(x);
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int a,b,n,m,cur;
	 	// n vertices m edges
	 	cin>>n>>m;
	 	while(m--)
	 	{
	 		cin>>a>>b;
	 		org[a].pb(b);
	 		rev[b].pb(a);
	 	}
	 	// push to stack
	 	FOR(i,1,n+1)
	 		if(!visit[i])
	 			dfs(i);
	 	// print scc
	 	while(!STACK.empty())
	 	{
	 		cur=STACK.top();
	 		STACK.pop();
	 		if(!visit1[cur])
	 		{
	 			component(cur);
	 			cout<<ln;
	 		}
	 	}
		return 0;
}