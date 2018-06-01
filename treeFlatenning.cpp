#include<bits/stdc++.h>
using namespace std;
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define RFOR(i, a, b) for (int i = (a); i >= (b); --i)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef long double ld;
const int L=1e5;
std::map<int, int> counter;
set<int> SET;
pair<int,string> PAIR;
#define sz(a)	ll(a.size()) 
#define ln "\n"
int t=1,m=1;
std::vector<int> v[100002];
std::vector<bool> visit(100002);
int distanceroot[100002],start[100002],arr[100002];
int modu=1000000007;
std::vector<int> aux[400002];
void build(int s,int e,int index)
{
	if(s>=e)
	{
		aux[index].pb(distanceroot[arr[s]]);
		return;
	}
	int mid=(s+e)/2;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	FOR(i,0,sz(aux[index<<1]))
		aux[index].pb(aux[index<<1][i]);
	FOR(i,0,sz(aux[(index<<1)+1]))
		aux[index].pb(aux[(index<<1)+1][i]);
	sort(aux[index].begin(), aux[index].end());
	return;
}
int query(int s,int e,int l,int r,int x,int index)
{
	if(e<l || s>r )return 0;
	if(s>=l && e<=r)
	{
		int ans=0;
		std::vector<int> ::iterator it;
		return upper_bound(aux[index].begin(), aux[index].end(),x)-lower_bound(aux[index].begin(), aux[index].end(),x);
	}
	int mid=(s+e)/2;
	int q1=query(s,mid,l,r,x,index<<1);
	int q2=query(mid+1,e,l,r,x,(index<<1)+1);
	return q1+q2;
}
int dfs(int vertex,int dist)
{
	if(visit[vertex])return 0;
	start[vertex]=t;
	arr[t]=vertex;
	t++;
	distanceroot[vertex]=dist+1;
	FOR(i,0,sz(v[vertex]))
		dfs(v[vertex][i],dist+1);
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int a,n,b;
	cin>>n;
	FOR(i,0,n-1)
	{
		cin>>a>>b;
		v[a].pb(b);
		v[b].pb(a);
	}
	dfs(1,-1);
	build(1,t-1,1);
	return 0;
}
