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
#define pii pair<ll,ll>
typedef long long ll;
typedef long double ld;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
int dp[1002][1002];
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	string s1, s2;
	 	cin >> s1 >> s2;
	 	int len1 = s1.length(), len2 = s2.length();
	 	int insert_cost, delete_cost, replace_cost;
	 	cin >> insert_cost >> delete_cost >> replace_cost;
	 	FOR(i,0,len1+1)dp[i][0] = i * delete_cost;
	 	FOR(j,0,len2+1)dp[0][j] = j * insert_cost;
	 	// delete means deleting in s1
	 	// insert means inserting in s1
	 	FOR(i,1,len1+1)
	 	{
	 		FOR(j,1,len2+1)
	 		{
	 			dp[i][j] = min(dp[i][j-1]+insert_cost , min(dp[i-1][j]+delete_cost, dp[i-1][j-1] + !(s1[i-1] == s2[j-1]) * replace_cost  ));
	 		}
	 	}
	 	cout<<dp[len1][len2]<<ln;
		return 0;
}