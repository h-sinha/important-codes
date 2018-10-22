// prints the number of points covered by n line segments in a 2D plane
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
const int L=1e3+7;
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
struct line
{
	ll x1,x2,y1,y2,a,b,c;	
};
line inp[1002];
ll get(ll x1, ll y1, ll x2, ll y2)
{
	return __gcd(abs(x1-x2),abs(y1-y2)) + 1;
}
void add(ll i,ll x1,ll y1,ll x2,ll y2)
{
	inp[i].a = y1-y2;
	inp[i].b = x2-x1;
	inp[i].c = -inp[i].a*x1 - inp[i].b*y1;
}
ll det(ll a,ll b,ll c,ll d)
{
	return a*d - b*c;
}
ll x,y;
bool llersect(ll i,ll j)
{
	ll dx = det(inp[i].c,inp[i].b,inp[j].c,inp[j].b);
	ll dy = det(inp[i].a,inp[i].c,inp[j].a,inp[j].c);
	ll d = det(inp[i].a,inp[i].b,inp[j].a,inp[j].b);
	if(d == 0)return 0;
	if(dx % d || dy %d )return 0;
	x = -dx/d, y=-dy/d;
	if(inp[i].x1 > inp[i].x2)swap(inp[i].x1,inp[i].x2);
	if(inp[j].x1 > inp[j].x2)swap(inp[j].x1,inp[j].x2);
	if(inp[i].y1 > inp[i].y2)swap(inp[i].y1,inp[i].y2);
	if(inp[j].y1 > inp[j].y2)swap(inp[j].y2,inp[j].y1);
	if(x<inp[i].x1 || x>inp[i].x2)return 0;
	if(y<inp[i].y1 || y>inp[i].y2)return 0;
	if(x<inp[j].x1 || x>inp[j].x2)return 0;
	if(y<inp[j].y1 || y>inp[j].y2)return 0;
	return 1;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	ll n,x1,x2,y2,y1;
	 	ll ans =0 ;
	 	cin >> n;
	 	set<pii>SET;
	 	FOR(i,0,n)
	 	{
	 		cin >> x1 >> y1 >> x2 >> y2;
	 		inp[i].x1= x1;
	 		inp[i].x2= x2;
	 		inp[i].y1= y1;
	 		inp[i].y2= y2;
	 		ans += get(x1,y1,x2,y2);
	 		add(i,x1,y1,x2,y2);
	 		FOR(j,0,i)
	 		{
	 			if(llersect(i,j))SET.insert(mp(x,y));
	 		}
	 		ans -= sz(SET);
	 		SET.clear();
	 	}
	 	cout<<ans;
		return 0;
}