#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
const int power2[21]={0,1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,\
32768,65536,131072,262144,524288};
long long n,m,a[20]={},p=0,d[20]={0,1};
long long f[530000][103]={};
bool in[530000][103]={};
queue<pair<int,int> >q;
int main()
{	
	cin>>n>>m;
	while(n)
	{
		a[++p]=n%10;
		n/=10;
	}
	sort(a+1,a+p+1);
	a[0]=-1;
	for(int i=2;i<=p;++i)
		d[i]=d[i-1]*10%m;
	for(int i=1;i<=p;++i)
		if(a[i]!=0 && a[i]!=a[i-1])
		{
			++f[power2[i]][a[i]*d[p]%m];
			q.push(make_pair(power2[i],a[i]*d[p]%m));
			in[power2[i]][a[i]*d[p]%m]=true;
		}
	while(!q.empty())
	{
		pair<int,int>s=q.front();
		q.pop();
		int state=s.first,mod=s.second,t=p;
		//cout<<"state="<<state<<" mod="<<mod<<endl;
		for(int i=1;i<=p;++i)
			if(state&power2[i])
				--t;
		for(int i=1;i<=p;++i)
		{
			if((state&power2[i])==0 && (a[i]!=a[i-1] || (state&(power2[i-1]))))
			{
				int ns=state|power2[i];
				int nm=(mod+a[i]*d[t])%m;
				f[ns][nm]+=f[state][mod];
				if(!in[ns][nm])
				{
					q.push(make_pair(ns,nm));
					in[ns][nm]=true;
				}
			}
		}
	}
	//for(int i=1;i<=power2[p+1]-1;++i)
	//	cout<<f[i][0]<<' '<<f[i][1]<<endl;
	cout<<f[power2[p+1]-1][0]<<endl;
	return 0;
}