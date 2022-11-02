#include<bits/stdc++.h>
using namespace std;
const int N=2020,Bitmod=(1<<30)-1;
int a,b,c,miu[N]={};
inline int f(int x,int y)
{
	int s=0;
	for(int i=1;i<=x;++i)
		if(__gcd(i,y)==1)
			s+=x/i;
	return s;
}
int main()
{
	cin>>a>>b>>c;
	if(a<b) swap(a,b);
	if(a<c) swap(a,c);
	miu[1]=1;
	for(int i=1;i<=a;++i)
		for(int j=i+i;j<=a;j+=i)
			miu[j]-=miu[i];
	long long ans=0;
	for(int i=1;i<=a;++i)
		for(int x=min(b,c);x>=1;--x)
			if(__gcd(i,x)==1)
				ans+=miu[x]*(a/i)*f(b/x,i)*f(c/x,i);
	cout<<(ans&Bitmod)<<endl;
	return 0;
}