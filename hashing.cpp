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
int len[302];
ll powerf[L],powerr[L],dp1[302][302],dp2[302][302],cumsum[302];
ll fwdhash[L],revhash[L],m=1e9+7;
ll fastexpo(ll x,ll y)
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
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll l,r,n,lengthis=0,ans;
	 	string s[302],cur="";
	 	cin>>n;
	 	FOR(i,0,n)
	 	{
	 		cin>>s[i];
	 		len[i]=s[i].length();
	 		if(i)cumsum[i]=cumsum[i-1]+1+len[i-1];
	 		cur+=s[i];
	 		lengthis+=len[i];
	 		cur+=" ";
	 	}
	 	powerf[0]=powerr[0]=1;
	 	FOR(i,1,100001)
	 	{
	 		powerf[i] = ( powerf[i-1]%m *97 )%m;
	 		powerr[i] = ( powerr[i-1]%m *53 )%m;
	 	}
	 	// cout<<cur<<ln;
	 	lengthis+=n-1;
	 	ans=lengthis;
	 	fwdhash[0]=(powerf[0]%m * cur[0]%m)%m;
	 	FOR(i,1,lengthis)
	 		fwdhash[i]=(fwdhash[i-1]%m + (powerf[i]%m * cur[i]%m)%m )%m;
	 	RFOR(i,lengthis - 1,1)
	 		revhash[i]=(revhash[i-1]%m + (powerr[i]%m * cur[i]%m)%m )%m;
	 	FOR(i,0,n)
	 	{
	 		FOR(j,i,n)
	 		{
	 			l=cumsum[i],r=cumsum[j]+len[j]-1;
	 			if(l)dp1[i][j] =( (fwdhash[r]%m - fwdhash[l-1]%m + m)%m * fastexpo(powerf[l],m-2)%m )%m; 
	 			else dp1[i][j] = fwdhash[r]%m; 
	 			
	 			dp2[i][j] =( (revhash[l]%m - revhash[r+1]%m + m)%m * fastexpo(powerr[r],m-2)%m )%m; 
	 			debug(dp1[i][j],dp2[i][j]);
	 		}
	 	}
		return 0;
}