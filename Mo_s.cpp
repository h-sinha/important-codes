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
int a[L],out[L],mark[L],counter[L];
std::map<int, int> hashing;
ll ans=0;
struct node
{
	int l,r,q;
};
bool comp(node x, node y)
{
	if(x.l/900==y.l/900)return x.r<y.r;
	return x.l<y.l;
}
void add(int idx) 
{
	counter[mark[idx]]++;
	if(counter[mark[idx]]==a[idx])ans++;
	else if(counter[mark[idx]]==a[idx]+1)ans--;
}

void remove(int idx) 
{
	counter[mark[idx]]--;
	if(counter[mark[idx]]==a[idx]-1)ans--;
	else if(counter[mark[idx]]==a[idx])ans++;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int curl,curr,n,m,l,r,b,k,cur=-1;
	 	cin>>n>>m;
	 	FOR(i,0,n)
	 	{
	 		cin>>a[i];
	 		if(hashing.find(a[i])!=hashing.end())
	 			mark[i]=hashing[a[i]];
	 		else 
	 		{
	 			hashing[a[i]]=++cur;
	 			mark[i]=cur;
	 		}
	 	}
	 	std::vector<node> v(m);
	 	node temp;
	 	FOR(i,0,m)
		{
			cin>>l>>r;
			l--,r--;
			v[i].l=l,v[i].r=r,v[i].q=i;
		}
		sort(all(v),comp);
		l=0,r=-1;
		FOR(i,0,m)
		{
			curl=v[i].l,curr=v[i].r;
			while(r<curr)
			{
				++r;
				add(r);
			}
			while(r>curr)
			{
				remove(r);
				--r;
			}
			while(l<curl)
			{
				remove(l);
				l++;
			}
			while(l>curl)
			{
				--l;
				add(l);
			}
			out[v[i].q]=ans;
		}
		FOR(i,0,m)cout<<out[i]<<ln;
		return 0;
}