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
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
std::vector<bool> visit(100002);
std::vector<ll> dist(100002);
std::vector<pii> v[100002];
ll nodeflag[100002],modu=1000000007,flag=0;
priority_queue<pii,std::vector<pii>,greater<pii> > qq;
int myrandom (int i) { return std::rand()%i;}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll f=0,n,m,source,target,a,b,c;
	cin>>n>>m;
	cin>>source>>target;
	while(m--)
	{
			cin>>a>>b>>c;
			v[a].pb(mp(c,b));
			v[b].pb(mp(c,a));
	}
	fill(dist.begin(), dist.end(),LLONG_MAX);
	dist[source]=0;
	pii temp;
	qq.push(mp(0,source));
	while(sz(qq))
	{
		temp=qq.top();
		ll node=temp.S;
		ll wt=temp.F;
		visit[node]=1;
		qq.pop();
		for(auto &x:v[node])
		{
			if(dist[x.S]>=dist[node]+x.F)
			{
				//In case of negative cycle break
				if(visit[x.F]){f=1;break;}
				dist[x.S]=dist[node]+x.F;
				x.F=dist[x.S];
				qq.push(x);
			}
		}
		//Negative cycle
		if(f)break;
	}
	if(dist[target]==LLONG_MAX || f)cout<<"-1"<<ln;
	else cout<<dist[target]<<ln;
	return 0;

}
	