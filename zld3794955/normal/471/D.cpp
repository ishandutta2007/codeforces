#include<iostream>
#include<cstdio>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cmath>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<deque>
#include<fstream>
#include<functional>
#include<iomanip>
#include<list>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<stdexcept>
#include<string>
#include<vector>
#include<utility>
using namespace std;
const double eps(1e-8);
const double pi(3.14159265358979);
const int N=200020,W=200020;
int n,w,a[N]={},b[W]={},next[W]={};
void init()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=w;++i)
		scanf("%d",&b[i]);
	for(int i=1;i<n;++i)
		a[i]=a[i+1]-a[i];
	for(int i=1;i<w;++i)
		b[i]=b[i+1]-b[i];
}
void get_next()
{
	int k=0;
	next[1]=0;
	for(int i=2;i<w;++i)
	{
		while(k && b[k+1]!=b[i])
			k=next[k];
		if(b[k+1]==b[i])
			++k;
		next[i]=k;
	}
}
void KMP()
{/*
	for(int i=1;i<n;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	for(int i=1;i<w;++i)
		cout<<b[i]<<' ';
	cout<<endl;*/
	if(w==1)
	{
		printf("%d\n",n);
		return;
	}
	int pos=0,ans=0;
	for(int i=1;i<n;++i)
	{
		while(pos && a[i]!=b[pos+1])
			pos=next[pos];
		if(b[pos+1]==a[i])
			++pos;
		if(pos==w-1)
		{
			++ans;
			//cout<<"i="<<i<<endl;
			pos=next[pos];
		}
		//cout<<"pos="<<pos<<endl;
	}
	printf("%d\n",ans);
}
int main()
{	
	init();
	get_next();
	KMP();
	return 0;
}