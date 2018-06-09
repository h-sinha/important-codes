#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b)     for(int i=a;i<b;++i)
#define RFOR(i,a,b)     for(int i=a;i>=b;--i)
#define ln         "\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)    ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define first F
#define second S
typedef long long ll;
typedef long double ld;
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
