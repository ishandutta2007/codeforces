#include<iostream>
#include<cstdio>
#include<cassert>
#include<cctype>
#include<queue>
using namespace std;
const double eps(1e-50);
const int K=2,L=250,B=8,S=1<<B,Unknown=-1;
int x,k,p,table[S]={};
double f[K][2][L][S]={};
bool in[K][2][L][S]={};
struct state
{
	int l,t1,t2,s;
};
queue<state> q;
void init()
{
	for(int i=0;i<S;++i)
		for(int t=0;t<B;++t)
			if((i&(1<<t))==0)
				++table[i];
			else
				break;
	scanf("%d%d%d",&x,&k,&p);
	int ls=x/S,p1=ls%2,p2=0;
	while(ls && ls%2==p1)
	{
		++p2;
		ls/=2;
	}
	f[0][p1][p2][x%S]=1;
	in[0][p1][p2][x%S]=true;
	q.push((state){0,p1,p2,x%S});
}
void multi2(const state &start)
{
	//cout<<"multi"<<endl;
	//cout<<start.l<<' '<<start.t1<<' '<<start.t2<<' '<<start.s<<endl;
	state end={start.l+1,start.s>>(B-1),Unknown,(start.s<<1)&(S-1)};
	end.t2=start.t2*(end.t1==start.t1)+1;
	//cout<<end.l<<' '<<end.t1<<' '<<end.t2<<' '<<end.s<<endl<<endl;
	double &from=f[start.l&1][start.t1][start.t2][start.s];
	double &to=f[end.l&1][end.t1][end.t2][end.s];
	if(in[end.l&1][end.t1][end.t2][end.s]==0)
	{
		q.push(end);
		in[end.l&1][end.t1][end.t2][end.s]=true;
	}
	to+=from*(p/100.0);
}
void add1(const state &start)
{
	//cout<<"add"<<endl;
	//cout<<start.l<<' '<<start.t1<<' '<<start.t2<<' '<<start.s<<endl;
	state end={start.l+1,start.t1,Unknown,Unknown};
	if(start.s==S-1)
	{
		end.t1=!end.t1;
		if(end.t1==1)
			end.t2=1;
		else
			end.t2=start.t2;
		end.s=0;
	}
	else
	{
		end.t2=start.t2;
		end.s=start.s+1;
	}
	//cout<<end.l<<' '<<end.t1<<' '<<end.t2<<' '<<end.s<<endl<<endl;
	double &from=f[start.l&1][start.t1][start.t2][start.s];
	double &to=f[end.l&1][end.t1][end.t2][end.s];
	if(in[end.l&1][end.t1][end.t2][end.s]==0)
	{
		q.push(end);
		in[end.l&1][end.t1][end.t2][end.s]=true;
	}
	to+=from*((100-p)/100.0);
}
inline int value(const state &now)
{
	return (now.t1==0 && now.s==0) ? now.t2+8 : table[now.s];
}
void work()
{
	double expect=0;
	while(!q.empty())
	{
		state now=q.front();
		//cout<<now.l<<' '<<now.t1<<' '<<now.t2<<' '<<now.s<<endl;
		//cout<<f[now.l][now.t1][now.t2][now.s]<<endl;
		q.pop();
		in[now.l&1][now.t1][now.t2][now.s]=false;
		double &p=f[now.l&1][now.t1][now.t2][now.s];
		if(now.l==k)
		{
			expect+=value(now)*p;
			continue;
		}
		if(p==0)
		{
			//assert(false);
			continue;
		}
		multi2(now);
		add1(now);
		p=0;
	}
	printf("%.13f\n",expect);
}
int main()
{	
	init();
	work();
	return 0;
}