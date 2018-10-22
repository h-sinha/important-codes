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
ll parent[100005],freq[100005],size[100005];
int co=0,tot=0;
set<ll>SET;
std::vector<ll> b;
ll find(int x)
{
    if(parent[x]==x)return x;
    parent[x]=find(parent[x]);
    return parent[x];
}
void un(ll x,ll y)
{
    ll px=find(x);
    ll py=find(y);
    // if(px==py)return;
    // --freq[size[px]];
    // if(freq[size[px]]==0)SET.erase(size[px]);
    //  --freq[size[py]];
    // if(freq[size[py]]==0)SET.erase(size[py]);
    size[px]+=size[py];
    parent[py]=px;
    // freq[size[px]]++;
    // if(freq[size[px]]==1)
    // SET.insert(size[px]);
    return ;

}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL),cout.tie(NULL);
        return 0;
}