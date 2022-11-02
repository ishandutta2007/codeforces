#include<bits/stdc++.h>
using namespace std;
const int N=500050;
int n,a,b;
long long T,s1[N]={},s2[N]={};
char ch[N]={};
void init()
{
	scanf("%d%d%d%I64d\n",&n,&a,&b,&T);
	scanf("%s",ch+1);
	for(int i=2;i<=n;++i)
		s1[i]=s1[i-1]+a+1+(ch[i]=='w')*b;
	s2[n]=a+1+(ch[n]=='w')*b;
	for(int i=n-1;i>=2;--i)
		s2[i]=s2[i+1]+a+1+(ch[i]=='w')*b;
	T-=(ch[1]=='w')*b+1;
}
bool check(int p)
{
	//cout<<"p="<<p<<endl;
	long long st=1ll<<60;
	st=min(st,s1[p]);
	//cout<<"st="<<st<<endl;
	st=min(st,s2[n-p+2]);
	//cout<<"st="<<st<<endl;
	for(int i=2;i<p;++i)
	{
		int e=n-p+i+1;
		//cout<<"e="<<e<<" i="<<i<<endl;
		long long sum1=s1[i];
		long long sum2=s2[e];
		//cout<<"s1="<<sum1<<" s2="<<sum2<<endl;
		sum1+=s2[e]+(ch[i]=='w')*b+(i-1)*1ll*a;
		sum2+=s1[i]+(ch[e]=='w')*b+(n-e+1)*1ll*a;
		//cout<<"s1="<<sum1<<" s2="<<sum2<<endl;
		st=min(st,min(sum1,sum2));
	}
	return st<=T;
}
void work()
{
	int l=0,r=n;
	while(l!=r)
	{
		int mid=(l+r+1)>>1;
		if(check(mid))
			l=mid;
		else
			r=mid-1;
	}
	cout<<l<<endl;
}
int main()
{
	init();
	work();
	return 0;
}