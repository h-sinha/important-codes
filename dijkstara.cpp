#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
#define pii pair<ll,ll>
#define node(x)	x.second
#define wt(x)	x.first
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<ll, ll> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
std::vector<bool> visit(100002);
std::vector<ll> dist(100002);
std::vector<pii> v[100002];
ll nodeflag[100002],modu=1000000007,flag=0;
priority_queue<pii,std::vector<pii>,greater<pii> > qq;
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
		ll node=temp.second;
		ll wt=temp.first;
		visit[node]=1;
		qq.pop();
		for(auto &x:v[node])
		{
			if(dist[x.second]>=dist[node]+x.first)
			{
				//In case of negative cycle break
				if(visit[x.first]){f=1;break;}
				dist[x.second]=dist[node]+x.first;
				x.first=dist[x.second];
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
	