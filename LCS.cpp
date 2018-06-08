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
#define F first
#define S second
typedef long long ll;
typedef long double ld;
int dp[102][102];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
		string s1,s2;
		pii pos;
		cin>>s1>>s2;
		int len1=s1.length(),len2=s2.length(),mx=INT_MIN;
		FOR(i,0,len2+1)dp[i][0]=0;
		FOR(j,0,len1+1)dp[0][j]=0;
		FOR(i,1,len1+1)
		{
			FOR(j,1,len2+1)
			{
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				if(s1[i-1]==s2[j-1])
					dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1);
			}
		}
		string ans="";
		cout<<dp[len1][len2]<<ln;
		int previ,prevj;
		int i=len1,j=len2;
		mx=dp[len1][len2];
		while(mx>0)
		{
			while(dp[i][j]==mx)
			{
				previ=i,prevj=j;
				if(dp[i-1][j]>dp[i][j-1])
					i--;
				else
					j--;

			}
			ans+=s1[previ-1];
			mx--;
		}	
		reverse(ans.begin(), ans.end());
		cout<<ans<<ln;
		return 0;
}