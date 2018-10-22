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
int sub[L],arr[L],parent[L][22],depth[L],ptr=1,chainNo=0,chainIndex[L],chainHead[L],posinbase[L],otherEnd[L];
std::vector<int> v[L];
std::vector<int> costs[L];
std::vector<int> indexx[L];
vector<int>seg(4*L);
void build(int s,int e,int index)
{
	if(s>=e)
	{
		seg[index]=arr[s];
		return;
	}
	int mid=(s+e)/2;
	build(s,mid,index<<1);
	build(mid+1,e,(index<<1)+1);
	seg[index]=max(seg[index<<1],seg[(index<<1)+1]);
	return;
}
int  queryseg(int s,int e,int l,int r,int index)
{
	if(e<l || s>r )return INT_MIN;
	if(s>=l && e<=r)
		return seg[index];
	int q1,q2,mid=(s+e)/2;
	q1=queryseg(s,mid,l,r,index<<1);
	q2=queryseg(mid+1,e,l,r,(index<<1)+1);
	return max(q1,q2);
}
void update(int s,int e,int index,int updind)
{
	if(updind<s||updind>e)return;
	if(updind==s && updind==e)
	{
		seg[index]=arr[s];
		return;
	}
	int mid=(s+e)/2;
	if(updind<=mid)
		update(s,mid,index<<1,updind);
	else
		update(mid+1,e,(index<<1)+1,updind);
	seg[index]=max(seg[index<<1],seg[(index<<1)+1]);
	return;
}

int dfs(int vertex,int _parent,int level)
{
	depth[vertex]=level+1;
	parent[vertex][0]=_parent;
	sub[vertex]=1;
	FOR(i,0,sz(v[vertex]))
	{
		if(v[vertex][i]!=_parent)
		{
			otherEnd[indexx[vertex][i]]=v[vertex][i];
			sub[vertex]+=dfs(v[vertex][i],vertex,level+1);
		}
	}
	return sub[vertex];
}
void HLD(int vertex,int cost,int prev)
{
	if(chainHead[chainNo]==-1)
		chainHead[chainNo]=vertex;
	chainIndex[vertex]=chainNo;
	posinbase[vertex]=ptr;
	arr[ptr++]=cost;
	int special=-1,ncost;
	FOR(i,0,sz(v[vertex]))
	{
		if(v[vertex][i]!=prev && (special==-1||sub[special]<sub[v[vertex][i]]))
		{
			special=v[vertex][i];
			ncost=costs[vertex][i];
		}
	}
	if(special!=-1)HLD(special,ncost,vertex);
	FOR(i,0,sz(v[vertex]))
	{
		if(v[vertex][i]!=prev && v[vertex][i]!=special)
		{
			chainNo++;
			HLD(v[vertex][i],costs[vertex][i],vertex);
		}
	}
	return ;
}
int findLCA(int a,int b)
{
	if(depth[a]>depth[b])swap(a,b);
	int dist=depth[b]-depth[a];
	int index=0;
	while(dist>0)
	{
		if(dist&1)b=parent[b][index];
		dist>>=1;index++;
	}
	
	RFOR(i,18,0)
	{
		if(parent[a][i]!=-1 && parent[a][i]!=parent[b][i])
		{
			a=parent[a][i];
			b=parent[b][i];
		}
	}
	if(a==b)return a;
	return parent[a][0];
}
int queryup(int u,int v)
{
	if(u==v)return 0;
	int chainu,chainv=chainIndex[v],ans=-1;
	while(1)
	{
		chainu=chainIndex[u];
		if(chainu==chainv)
		{
			if(u==v)break;
			ans=max(ans,queryseg(1,ptr,posinbase[v],posinbase[u],1));
			break;
		}
		ans=max(ans,queryseg(1,ptr,posinbase[chainHead[chainu]],posinbase[u],1));
		u=chainHead[chainu];
		u=parent[u][0];

	}
	return ans;
}
void query(int u,int v)
{
	int lca=findLCA(u,v);
	int ans=queryup(u,lca);
	int ans1=queryup(v,lca);
	cout<<max(ans,ans1)<<ln;
	return;
}
void change(int idx,int val)
{
	int u=otherEnd[idx];
	arr[posinbase[u]]=val;
	update(1,ptr,1,posinbase[u]);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL),cout.tie(NULL);
	 	int n;
	 	int t,a,b,c;
		cin>>t;
		while(t--)
		{
			ptr=0;
			cin>>n;
			FOR(i,0,n+1)
	 		{
	 			v[i].clear();
	 			costs[i].clear();
	 			indexx[i].clear();
	 			chainHead[i]=-1;
	 			FOR(j,0,20)
	 				parent[i][j]=-1;
	 		}
	 		// seg.clear();
			FOR(i,0,n-1)
			{
				cin>>a>>b>>c;
				a--,b--;
				v[a].pb(b);
				v[b].pb(a);
				costs[a].pb(c);
				costs[b].pb(c);
				indexx[a].pb(i);
				indexx[b].pb(i);
			}
			chainNo=0;
			ptr=1;
			dfs(0,-1,-1);
			HLD(0,-1,-1);
			ptr--;
			build(1,ptr,1);
	 		FOR(j,1,19)
	 		FOR(i,0,n+1)
	 			if(parent[i][j-1]!=-1)
	 				parent[i][j]=parent[parent[i][j-1]][j-1];
			int a,b;
			while(1)
			{
				string s;
				cin>>s;
				// cout<<s<<endl;
				if(s=="DONE")break;
				cin>>a>>b;
				if(s=="QUERY")
				{
					query(a,b);
				}
				else if(s=="CHANGE")
				{
					change(a-1,b);
				}
			}
		}
		return 0;
}