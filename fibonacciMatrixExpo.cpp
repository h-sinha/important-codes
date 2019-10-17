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
#define FOR(i,a,b)     for(int i=a;i<b;++i)
#define RFOR(i,a,b)     for(int i=a;i>=b;--i)
#define ln         "\n"
#define mp make_pair
#define pb push_back
#define sz(a)    ll(a.size())
#define F first
#define S second
#define all(c)    c.begin(),c.end()
#define trace(c,x) for(auto &x:c)
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef    priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e6+7;
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
ll m=1e9+7,arr[2][2],temp[2][2],aux[2][2];
ll fibo(ll n)
{
    //Base case:fib[1]=1 fib[2]=1 fib[2]=2
    FOR(i,0,2)
    {
        FOR(j,0,2)
        {
            arr[i][j]=1;
            if(i==j)temp[i][j]=1;
        }
    }
    arr[1][1]=0;
    for(;n>0;n/=2)
    {
        if(n & 1)
        {
            FOR(i,0,2)FOR(j,0,2){aux[i][j]=temp[i][j];temp[i][j]=0;}
            FOR(i,0,2)
                FOR(j,0,2)
                    FOR(k,0,2)
                     temp[i][j] = (temp[i][j]%m + (arr[i][k]%m * aux[k][j]%m)%m)%m;
        }
        FOR(i,0,2)FOR(j,0,2){aux[i][j]=arr[i][j];arr[i][j]=0;}
        FOR(i,0,2)
                FOR(j,0,2)
                    FOR(k,0,2)
                        arr[i][j] = (arr[i][j]%m + (aux[i][k]%m * aux[k][j]%m)%m)%m;
    }
    return temp[1][0]%m;
}
int main()
{
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,n;	
    cin>>n;
    cout<<fibo(n);
    return 0;
}
