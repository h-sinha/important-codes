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
typedef std::complex<double> Complex;
typedef	priority_queue<pii,std::vector<pii>,greater<pii> > revpr;
const int L=1e5+7;
const double PI = 3.141592653589793238460;
void fft(std::vector<Complex>& x)
{
	  const int n = x.size();
	  if (n <= 1) return;
	  std::vector<Complex> even, odd;
	  // partitioning step
	  for (int i = 0; i < n; i += 2)even.pb(x[i]);
	  for (int i = 1; i < n; i += 2)odd.pb(x[i]);
	  fft(even);
	  fft(odd);
	  FOR(k,0,n/2)
	  {
	  	// polar(r, theta)
	    Complex t = std::polar(1.0, -2 * PI * k / n) * odd[k];
	    x[k] = even[k] + t;
	    x[k+n/2] = even[k] - t;
	  }
}
void ifft(std::vector<Complex>& x)
{
	  // conj(x)
	  trace(x,xx)xx=conj(xx);
	  fft(x);
	  trace(x,xx)xx=conj(xx);
	  trace(x,xx)xx/=sz(x);
}
int main()
{
		ios_base::sync_with_stdio(false);
	 	cin.tie(NULL);
	 	int t, n;
	 	cin >> t;
	 	double co;
	 	while(t--)
	 	{
	 		cin >> n;
	 		++n;
	 		int vect_size = 2 * (1 << int(ceil(log2(n))) );
	 		// padding up
	 		std::vector<Complex> a(vect_size - n, 0.0) , b(vect_size - n, 0.0);
	 		FOR(i,0,n)
	 		{
	 			cin >> co;
	 			a.pb(co);
	 		}
	 		FOR(i,0,n)
	 		{
	 			cin >> co;
	 			b.pb(co);
	 		}
	 		std::vector<Complex> data1(vect_size) , data2(vect_size);
	 		FOR(i,0,vect_size)data1[i] = a[i];
	 		FOR(i,0,vect_size)data2[i] = b[i];
	 		fft(data1);
	 		fft(data2);
	 		std::vector<Complex> data3(vect_size);
	 		FOR(i,0,vect_size)data3[i] = data1[i] * data2[i];

	 		// inverse point-value to coefficient form
	 		ifft(data3);
	 		std::vector<ll> ans;

	 		FOR(i,vect_size - 1 -(2*n-1),vect_size - 1)
	 			cout<<ll(round(data3[i].real())) << " ";
	 		cout<<ln;
	 	}
		return 0;
}