#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
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

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> pbds;
// ordered_set X
//K-th smallest
//*X.find_by_order(k-1)
//NO OF ELEMENTS < A
//X.order_of_key(A)

const int L=1e2+7;
ll mod = 1e9 + 7;
struct matrix
{
    ll B[L][L], n;
    matrix(){n = L; memset(B,0,sizeof B);}
    matrix(int _n){n = _n; memset(B, 0, sizeof B);}
    void iden(){FOR(i,0,n) B[i][i] = 1;}
    void operator += (matrix M){
        FOR(i,0,n) FOR(j,0,n) B[i][j] = B[i][j]+M.B[i][j];
    }
    void operator -= (matrix M){
        FOR(i,0,n) FOR(j,0,n) B[i][j] = B[i][j]-M.B[i][j];
    }
    void operator %= (ll mod){
        FOR(i,0,n) FOR(j,0,n) B[i][j] = (ll)B[i][j]%mod;
    }
 
    void operator *= (ll b){
        FOR(i,0,n) FOR(j,0,n) B[i][j]*=b;
    }
    matrix operator - (matrix M){
        matrix ret = (*this); ret -= M; return ret;
    }
    matrix operator + (matrix M){
        matrix ret = (*this); ret += M; return ret;
    }   
    matrix operator * (matrix M){
        matrix ret = matrix(n); memset(ret.B, 0, sizeof ret.B);
        FOR(i,0,n)
        	FOR(j,0,n)
        		FOR(k,0,n)
		        {
                    ll z=B[i][k]*M.B[k][j];
                    z%=mod;
                    ret.B[i][j] = ret.B[i][j]+z;
                    ll x=ret.B[i][j];
                    ret.B[i][j]=x%mod;
                }
        return ret;
    }
    matrix operator *= (matrix M){ *this = ((*this) * M);}
    matrix operator * (int b){
        matrix ret  = (*this); ret *= b; return ret;
    }
    vector<ll> multiply(const vector<ll> & v) const{
    	vector<ll> ret(n);
    	FOR(i,0,n)
    		FOR(j,0,n)
	    	{
    			ret[i] += (B[i][j] * v[j])%mod;
    			ret[i] %= mod;
    		}
    	return ret;
    }
};
matrix expo(matrix b,ll e,ll m,ll sz)
{
	matrix a=matrix(sz);
	a.iden();
    while(e !=0 )
    {
        if(e&1)
      	{ 
            a= (a*b);
        	a%=m;
        }
        b=(b*b);
        b%=m;
        e>>= 1;
	}
	return a;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
}