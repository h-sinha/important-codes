#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) 	for(int i=a;i<b;++i)
#define RFOR(i,a,b) 	for(int i=a;i>=b;--i)
#define ln 		"\n"
#define mp make_pair
#define pb push_back
#define pii pair<ll,ll>
#define sz(a)	ll(a.size())
#define debug1(x) cout<<x<<endl
#define debug2(x,y) cout<<x<<"-->"<<y<<endl
#define debug3(x,y,z) cout<<x<<"-->"<<y<<"-->"<<z<<endl
#define first F
#define second S
typedef long long ll;
typedef long double ld;
map<ll,ll> counter;
ll y,x[4][4],m=1e9+7,dp[4][4],aux[4][4];
void fastexpomat()
{
	ll temp[4][4];
	FOR(i,0,4)
	{
		FOR(j,0,4)
		{
			if(i==j)
			{
				temp[i][j]=1;
				dp[i][j]=0;
			}
			else
			{
				dp[i][j]=1;
				temp[i][j]=0;
			}
		}
	}
	while(y>0)
	{


		if(y&1)
		{
			FOR(i,0,4)FOR(j,0,4){aux[i][j]=temp[i][j];temp[i][j]=0;}
			FOR(i,0,4)
				FOR(j,0,4)
					FOR(k,0,4)
						temp[i][j] = (temp[i][j]%m + (dp[i][k]%m * aux[k][j]%m)%m)%m;
		}
		FOR(i,0,4)FOR(j,0,4){aux[i][j]=dp[i][j];dp[i][j]=0;}
		FOR(i,0,4)
				FOR(j,0,4)
					FOR(k,0,4)
						dp[i][j] = (dp[i][j]%m + (aux[i][k]%m * aux[k][j]%m)%m)%m;
		y>>=1;
	}
	
	cout<<temp[3][3];
	return;
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		cin>>y;
		fastexpomat();
		return 0;
}