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
const int L=1e5+1;
ll out[L],color[L],start[L],ending[L],tim=1,base[L],co[L];
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
int counter[L];
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
	 	std::vector<node> v[n/316 + 5];
	 	node temp;
	 	FOR(i,0,m)
		{
			cin>>l>>r;
			temp.l=start[l], temp.r=ending[l],temp.k=r,temp.q=i;
			v[start[l]/316].pb(temp);
		}
		FOR(i,0,n/316 +1)sort(all(v[i]),comp);
		FOR(i,0,n/316 + 3)
		{
			l=r=i*316;
			add(base[l]);
			trace(v[i],x)
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