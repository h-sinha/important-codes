#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define F first
#define S second
#define all(c)	c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
int a[L];
std::vector<int> v;
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int n;
	 	cin>>n;
	 	FOR(i,0,n)cin>>a[i];
		int cur=0;
		v.pb(a[0]);
		std::vector<int> ::iterator it;
		FOR(i,1,n)
		{
			if(a[i]<v[0])v[0]=a[i];
			else if(a[i]>v[sz(v)-1])v.pb(a[i]);
			else
			{
				it=lower_bound(all(v),a[i]);
				v[it-v.begin()]=a[i];
			}
		}
		cout<<sz(v);
		return 0;
}