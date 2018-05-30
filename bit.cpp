#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define least(x) (x&(-x))
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
int n,m,type,a,b;
int modu=1000000007;
int arr[400010],start[200010],sign[200002],ending[200010],aux[400060],t=1,val[200010];
std::vector<bool> visit(200002);
std::vector<int> v[200002];
void dfs(int vertex,int s)
{
	if(visit[vertex])return;
	start[vertex]=t;t++;
	sign[vertex]=s;
	visit[vertex]=1;
	for(auto&x:v[vertex])
		dfs(x,-s);
	ending[vertex]=t;t++;
	return;
}
void update(int x,int value)
{
	while(x<=2*n)
	{
		aux[x]+=value;
		x=x+least(x);
	}
	return;
}
int query(int x)
{
	int ret=0;
	while(x>0)
	{
		ret+=aux[x];
		x-=least(x);
	}
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x,va;
	cin>>n>>m;
	FOR(i,1,n+1)cin>>val[i];
	FOR(i,0,n-1)
	{
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,1);
	while(m--)
	{
		cin>>type;
		switch(type)
		{
			case 1:
				cin>>x>>va;
				update(start[x],va*sign[x]);
				update(ending[x]+1,-va*sign[x]);
				break;
			case 2:
				cin>>x;
				cout<<val[x]+sign[x]*query(start[x])<<ln;
		}
	}
	return 0;
}
