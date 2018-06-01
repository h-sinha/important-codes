#include<stdio.h>
int main()
{
	long long int i,j,k,dsum[1000005];
	int n[104],m[104],T,a[1000004];
	for(i=0;i<=1000000;i++)
		dsum[i]=0;
	scanf("%d",&T);
	for(i=0;i<T;i++)
		scanf("%d %d",&n[i],&m[i]);
	for(i=1;i<=1000000;i++)
		a[i]=1;
	a[0]=0;
	a[1]=0;
	for(k=2;k<=1000;k++)
	{
		for(j=k*2;j<=1000000;j+=k)
			a[j]=0;
	}
	dsum[0]=0;
	for(i=1;i<=1000000;i++)
	{
		dsum[i]=dsum[i-1];
		if(a[i]==1)
			dsum[i]+=i;
	}	
	for(i=0;i<T;i++)
		printf("%lld\n",dsum[m[i]]-dsum[n[i]-1]);
	return 0;
}

