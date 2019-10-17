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
ll ans=0;
ll co,temp,cur,n,h;
bool check(ll val)
{
	ll temp=min(val,h);
	ll aux=(val)*(val)-((temp)*(temp-1))/2;
	if(aux>n)return 0;
	return 1;
}
void ser()
{
	ll l=1,r=2e9,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		if(check(mid))
			l=mid;
		else r=mid;
	}
	if(!check(r))r=l;
	temp=min(r,h);
	ll aux=(2*r-1)-(temp-1);
	ll co=r*r-temp*(temp-1)/2;
	n-=co;
	temp=n%r;
	if(temp)
	cout<<aux+n/r+1;
	else cout<<aux+n/r;
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	cin>>n>>h;
	 	ser();
		return 0;
}