#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(ll i=a;i<b;++i)
#define RFOR(i,a,b) 	for(ll i=a;i>=b;--i)
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
ll arr[200002],seg[800010],lazy[800010];
void lazyupdate(ll s,ll e,ll index)
{
	if(lazy[index])
	{
		seg[index]+=(e-s+1)*lazy[index];
		if(s!=e)
		{
			lazy[index<<1]+=lazy[index];
			lazy[(index<<1)+1]+=lazy[index];
		}
		lazy[index]=0;
	}
	return;
}
ll query(ll s,ll e,ll index,ll l,ll r)
{
	lazyupdate(s,e,index);
	if(e<l || s>r )return 0;
	if(s>=l && e<=r)
		return seg[index];
	ll q1,q2,mid=(s+e)/2;
	q1=query(s,mid,index<<1,l,r);
	q2=query(mid+1,e,(index<<1)+1,l,r);
	return (q1+q2);
}
void update(ll s,ll e,ll index,ll start,ll end,ll upd)
{
	lazyupdate(s,e,index);
	if(end<s||start>e || s>e)return;
	if(start<=s && end>=e)
	{
		seg[index]+=(e-s+1)*upd;
		if(s!=e)
		{
			lazy[index<<1]+=upd;
			lazy[(index<<1)+1]+=upd;
		}
		return;
	}
	ll mid=(s+e)/2;
	update(s,mid,index<<1,start,end,upd);
	update(mid+1,e,(index<<1)+1,start,end,upd);
	seg[index]=(seg[index<<1]+seg[(index<<1)+1]);
	return;
}
int  main()
{
	 	ios_base::sync_with_stdio(false);
		cin.tie(NULL);
		ll m,n,type,t,c,v,p,q;
	 	cin>>t;
	 	while(t--)
	 	{
	 		FOR(i,1,600020)seg[i]=0,lazy[i]=0;
	 		cin>>n>>c;
	 		while(c--)
	 		{
	 			cin>>type>>p>>q;
	 			if(type)
	 				cout<<query(1,n,1,p,q)<<endl;
	 			else 
	 			{
	 				cin>>v;
	 				update(1,n,1,p,q,v);
	 			}
	 		}
	 	}

		return 0;
}