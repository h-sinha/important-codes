#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
ll ans=0;
ll fastexpo(ll x,ll y,ll m){ll temp=1;while(y>0){if(y&1)temp = ((temp%m)*(x%m))%m;x = ((x%m)*(x%m))%m;y>>=1;}return temp;}
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