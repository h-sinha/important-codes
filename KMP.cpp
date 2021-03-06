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
std::vector<int> lps;
void preprocess(string s)
{
	int len = s.length(), j = 0;
	lps.push_back(0);
	for (int i = 1; i < len; ++i)
	{
		if(s[i]==s[j])
		{
			j++;
			lps.push_back(j);
		}
		else
		{
			if(j == 0)
			{
				lps.push_back(0);
			}
			else
			{
				while(j > 0 && s[i] != s[j])
				{
					j = lps[j-1];
				}
				if(s[i] == s[j])
				{
					j++;
				}
				lps.push_back(j);
			}
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string text, pattern;
	cin >> text;
	cin >> pattern;
	preprocess(pattern);
	int text_length = text.length(), pattern_length = pattern.length();
	int cur = 0;
	for (int i = 0; i < text_length; ++i)
	{
		if(text[i] == pattern[cur])
		{
			cur++;
		}
		else 
		{
			if(cur != 0)
			{
				cur = lps[cur - 1];
				i--;
			}
		}
		if(cur == pattern_length)
		{
			cout << i - cur + 1 << " ";
			cur = lps[cur - 1];
		}
	}
	return 0;
}
