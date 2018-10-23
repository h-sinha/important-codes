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
const int L=1e5+7;
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
ll out[L],color[L],start[L],ending[L],tim=1,base[L],co[L],counter[L];
std::vector<int> v[L];
void eulerTour(int vertex,int parent)
{
	start[vertex]=tim++;
	trace(v[vertex],x)
		if(x!=parent)eulerTour(x,vertex);
	ending[vertex]=tim-1;
	return;
}
struct node
{
	ll l,r,k,q;
};
bool comp(node x, node y)
{
	return x.r<y.r;
}
void add(ll val)
{
	counter[val]++;
	co[counter[val]]++;
	return;
}
void remove(ll val)
{
	counter[val]--;
	co[counter[val]+1]--;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,m,cur=0,l,r,a,b,k;
	 	cin>>n>>m;
	 	FOR(i,1,n+1)cin>>color[i];
	 	FOR(i,0,n-1)
	 	{
	 		cin>>a>>b;
	 		v[a].pb(b);
	 		v[b].pb(a);
	 	}
	 	eulerTour(1,-1);
	 	FOR(i,1,n+1)base[start[i]]=color[i];
	 	std::vector<node> qq[n/316 + 5];
	 	node temp;
	 	FOR(i,0,m)
		{
			cin>>l>>r;
			temp.l=start[l], temp.r=ending[l],temp.k=r,temp.q=i;
			qq[start[l]/316].pb(temp);
		}
		FOR(i,0,n/316 +1)sort(all(qq[i]),comp);
		FOR(i,0,n/316 + 3)
		{
			l=r=i*316;
			add(base[l]);
			trace(qq[i],x)
			{
				while(l<x.l)
				{
					remove(base[l]);
					l++;
				}
				while(l>x.l)
				{
					--l;
					add(base[l]);
				}
				while(r>x.r)
				{
					remove(base[r]);
					--r;
				}
				while(r<x.r)
				{
					++r;
					add(base[r]);
				}
				out[x.q]=co[x.k];
			}
			FOR(j,l,r+1)remove(base[j]);
		}
		FOR(i,0,m)cout<<out[i]<<ln;
		return 0;
}