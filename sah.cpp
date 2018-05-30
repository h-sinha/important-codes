#include<bits/stdc++.h>
using namespace std;
typedef long long ll;


ll powerr(ll x,ll y,ll m)
{
	ll temp=1;
	while(y>0)
	{
		if(y&1)temp = ((temp%m)*(x%m))%m;
		x = ((x%m)*(x%m))%m;
		y>>=1;
	}return temp;
}

int main()
{
ll t,n,k,x1,y1,c,d,e1,e2,m,C,D,E1,E2,X1,Y1,xn,yn,mm=1000000007;
cin>>t;
for(int aa=1;aa<t;aa++)
{
  cin>>n>>k>>x1>>y1>>c>>d>>e1>>e2>>m;
  C=c%m; D=d%m; E1=e1%m; E2=e2%m; X1=x1%m; Y1=y1%m;
  ll arr[n+1];
  arr[0]=(X1+Y1)%m;
  for(int i=1;i<n;i++)
  { xn=( (C%m*X1%m)%m+(D%m*Y1%m)%m +E1%m)%m;
    yn=( (D%m*X1%m)%m+(C%m*Y1%m)%m +E2%m)%m;
    arr[i]=(xn%m+yn%m)%m;
    x1=xn; y1=yn; X1=x1%m; Y1=y1%m;
  }
  ll p=1,sum=0;

  for(int z=1;z<=k;z++)
  {
    for(int i=0;i<(1<<n);i++)
    {
      for(int j=0;j<n;j++)
      {
        if(i&(1<<j))
        {
          sum=(sum%mm+ll(ll(arr[j]%mm)*ll(powerr(p,z,mm))%mm)%mm)%mm;
          p++;
        }
      }
      p=1;
    }
  }
  cout<<"Case #"<<aa<<": "<<sum<<"\n"; sum=0;
}

}