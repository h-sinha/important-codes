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
int m=1000000007;
ll arr[100002];
ll seg[4000002]
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
	seg[index]=seg[index<<1]+seg[(index<<1)+1];
	return;
}
ll query(int s,int e,int l,int r,int index)
{
	if(e<l || s>r )return INT_MIN;
	if(s>=l && e<=r)
		return seg[index];
	int q1,q2,mid=(s+e)/2;
	q1=query(s,mid,l,r,index<<1);
	q2=query(mid+1,e,l,r,(index<<1)+1);
	return q1+q2;
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
	seg[index]=seg[index<<1]+seg[(index<<1)+1];
	return;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	build(1,n,1);
	return 0;
}
