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
#define pii pair<int,int>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
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