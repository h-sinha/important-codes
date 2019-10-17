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
#define least(x) (x&(-x))
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
