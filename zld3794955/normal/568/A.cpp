#include<bits/stdc++.h>
using namespace std;
const int N=5001000;
int A,B,p[N]={},t1=0,q[N]={},t2=0,v=5000000;
bool del[N]={};
void init()
{
	int a[20]={},l=1;
	a[1]=1;
	q[++t2]=1;
	for(int i=2;i<=v;++i)
	{
		if(!del[i])
			p[++t1]=i;
		for(int j=1;i*p[j]<=v;++j)
		{
			del[i*p[j]]=true;
			if(i%p[j]==0)
				break;
		}
		int j=1;
		for(;a[j]==9;++j)
			a[j]=0;
		++a[j];
		if(j>l) l=j;
		bool flag=true;
		for(int k=1;k<=l;++k)
			if(a[k]!=a[l+1-k])
				flag=false;
		if(flag)
			q[++t2]=i;
	}/*
	for(int i=1;i<=t1;++i)
		cout<<p[i]<<' ';
	cout<<endl;
	for(int i=1;i<=t2;++i)
		cout<<q[i]<<' ';
	cout<<endl;*/
}
void work()
{
	cin>>A>>B;
	long long t1=0,t2=0,ans=0;
	for(int i=1;i<=v;++i)
	{
		if(p[t1+1]==i) ++t1;
		if(q[t2+1]==i) ++t2;
		if(A*t2 >= B*t1) ans=i;
		//cout<<"i="<<i<<" t1="<<t1<<" t2="<<t2<<endl;
	}
	cout<<ans<<endl;
}
int main()
{
	init();
	work();
	return 0;
}