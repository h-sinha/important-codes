#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)     for(int i=a;i<b;++i)
#define RFOR(i,a,b)     for(int i=a;i>=b;--i)
#define ln         "\n"
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define sz(a)    int(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
typedef long long ll;
typedef long double ld;
map<int,int> counter;
ll parent[100005],freq[100005],size[100005];
int co=0,tot=0;
set<ll>SET;
std::vector<ll> b;
ll find(int x)
{
    if(parent[x]==x)return x;
    parent[x]=find(parent[x]);
    return parent[x];
}
void un(ll x,ll y)
{
    ll px=find(x);
    ll py=find(y);
    // if(px==py)return;
    // --freq[size[px]];
    // if(freq[size[px]]==0)SET.erase(size[px]);
    //  --freq[size[py]];
    // if(freq[size[py]]==0)SET.erase(size[py]);
    size[px]+=size[py];
    parent[py]=px;
    // freq[size[px]]++;
    // if(freq[size[px]]==1)
    // SET.insert(size[px]);
    return ;

}
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL),cout.tie(NULL);
        return 0;
}