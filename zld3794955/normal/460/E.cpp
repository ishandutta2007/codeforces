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
const int N=140,V=100,T=20;
struct way
{
	int a[T],v;
}now,best;
int n,r,x[N]={},y[N]={},dis[N][N]={},u[V+V]={},*sqr=&u[V],tot=0;
void init()
{
	cin>>n>>r;
	for(int i=-75;i<=75;++i)
		sqr[i]=i*i;
	for(int i=-r;i<=r;++i)
	{
		int j=0;
		while(i*i+j*j<=r*r)
			++j;
		++tot;
		x[tot]=i,y[tot]=j-1;
		++tot;
		x[tot]=i,y[tot]=-j+1;
	}
	for(int i=1;i<=tot;++i)
		for(int j=1;j<=tot;++j)
			dis[i][j]=sqr[x[i]-x[j]]+sqr[y[i]-y[j]];
}
void work()
{
	const double ST=30000,D=0.999999;
	const int S=1000,K=1;
	//for(int hzw=1;hzw<=3;++hzw) {
	for(int i=1;i<=n;++i)
		now.a[i]=i;
	now.v=0;
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			now.v+=dis[i][j];
	double T=ST;
	while(T>1)
	{
		int k=rand()%n+1,oldk=now.a[k],oldv=now.v;
		for(int i=1;i<=n;++i)
			now.v-=dis[now.a[i]][now.a[k]];
		int to=rand()%tot+1;
		now.a[k]=to;
		for(int i=1;i<=n;++i)
			now.v+=dis[now.a[i]][now.a[k]];
		int delta=oldv-now.v;
		if(delta<=0)
		{
			if(now.v>best.v)
				best=now;
		}
		else
		{
			double p=delta*1.0/K*T/ST;
			double p2=rand()%S*1.0/S;
			if(p2<p)
				now.a[k]=oldk,now.v=oldv;
		}
		T*=D;
	}
	//}
	cout<<best.v<<endl;
	for(int i=1;i<=n;++i)
		cout<<x[best.a[i]]<<' '<<y[best.a[i]]<<endl;
	//cout<<clock()<<endl; 
}
int main()
{	
	srand(time(0));
	init();
	work();
	return 0;
}