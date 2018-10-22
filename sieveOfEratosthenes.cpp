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
int main()
{
	long long int i,j,k,dsum[1000005];
	int n[104],m[104],T,a[1000004];
	for(i=0;i<=1000000;i++)
		dsum[i]=0;
	scanf("%d",&T);
	for(i=0;i<T;i++)
		scanf("%d %d",&n[i],&m[i]);
	for(i=1;i<=1000000;i++)
		a[i]=1;
	a[0]=0;
	a[1]=0;
	for(k=2;k<=1000;k++)
	{
		for(j=k*2;j<=1000000;j+=k)
			a[j]=0;
	}
	dsum[0]=0;
	for(i=1;i<=1000000;i++)
	{
		dsum[i]=dsum[i-1];
		if(a[i]==1)
			dsum[i]+=i;
	}	
	for(i=0;i<T;i++)
		printf("%lld\n",dsum[m[i]]-dsum[n[i]-1]);
	return 0;
}

