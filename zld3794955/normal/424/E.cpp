#include<bits/stdc++.h>
using namespace std;
namespace jenga {
inline char get_unempty_char()
{
	char ch;
	while(isspace(ch=getchar())) ;
	return ch;
}
const double eps(1e-12),Inf=1e+64;
typedef unsigned long long i64u;
const int RED=1,BLUE=2,GREEN=3,EMPTY=0,N=6,Base=67,mod=1<<20,modd=mod-1;
int n,last[mod]={},next[mod]={},total_edge=0,s[N*3-1]={},tot=0;
int order[1<<6]={};
i64u hv[mod]={};
double f[mod]={};
inline void add(i64u hash,double v)
{
	int u=hash&modd;
	next[++total_edge]=last[u];
	last[u]=total_edge;
	f[total_edge]=v;
	hv[total_edge]=hash;
}
inline int get_num(char ch)
{
	if(ch=='R') return RED;
	if(ch=='B') return BLUE;
	if(ch=='G') return GREEN;
	if(ch=='E') return EMPTY;
	assert(false);
}
void init()
{
	n=get_unempty_char()-'0';
	for(int a=0;a<=3;++a)
		for(int b=0;b<=3;++b)
			for(int c=0;c<=3;++c)
				order[a|(b<<2)|(c<<4)]=a<c?(a|(b<<2)|(c<<4)):(c|(b<<2)|(a<<4));
	for(int i=1;i<=n;++i)
	{
		s[i]|=get_num(get_unempty_char())<<0;
		s[i]|=get_num(get_unempty_char())<<2;
		s[i]|=get_num(get_unempty_char())<<4;
		s[i]=order[s[i]];
	}
	tot=n;
}
inline i64u hash(int *s,int k,int up)
{
	static int v[N*3+10]={};
	i64u h=0;
	int tot=0;
	for(int i=1;i<=k;++i)
		if(s[i])
			v[++tot]=s[i];
	sort(v+1,v+tot+1);
	for(int i=1;i<=tot;++i)
		h=h*Base+v[i];
	h=h*Base+up;
	return h;
}
double work(int *s,int tot,int up)
{
	up=order[up];
	i64u h=hash(s,tot,up);
	for(int i=last[h&modd];i;i=next[i])
		if(hv[i]==h)
			return f[i];
	double v[4]={Inf,Inf,Inf,Inf};
	int to=tot,D=6;
	if((up&3) && ((up>>2)&3) && ((up>>4)&3))
		s[++to]=up , up=0;
	for(int i=1;i<=tot;++i)
	{
		int c1=s[i]&3 , c2=(s[i]>>2)&3 , c3=(s[i]>>4)&3 , ns=s[i];
		if(c1 && c2 && c3 && v[c2]>eps)
		{
			s[i]=0;
			if(!(up&3)) v[c2]=min(v[c2],work(s,to,up|c2));
			else if(!(up>>4&3)) v[c2]=min(v[c2],work(s,to,up|c2<<4));
			if(!(up>>2&3)) v[c2]=min(v[c2],work(s,to,up|c2<<2));
			s[i]=ns;
		}
		if(c1 && v[c1]>eps)
		{
			s[i]=c3;
			if(!(up&3)) v[c1]=min(v[c1],work(s,to,up|c1));
			else if(!(up>>4&3)) v[c1]=min(v[c1],work(s,to,up|c1<<4));
			if(!(up>>2&3)) v[c1]=min(v[c1],work(s,to,up|c1<<2));
			s[i]=ns;
		}
		if(c3 && v[c3]>eps)
		{
			s[i]=c1;
			if(!(up&3)) v[c3]=min(v[c3],work(s,to,up|c3));
			else if(!(up>>4&3)) v[c3]=min(v[c3],work(s,to,up|c3<<4));
			if(!(up>>2&3)) v[c3]=min(v[c3],work(s,to,up|c3<<2));
			s[i]=ns;
		}
	}
	double sum=0;
	if(v[1]!=Inf) sum+=v[1] , D-=1;
	if(v[2]!=Inf) sum+=v[2]*2 , D-=2;
	if(v[3]!=Inf) sum+=v[3]*2 , D-=2;
	sum=D==6 ? 0 : (sum+6)/(6-D);
	add(h,sum);
	return sum;
}
int Main()
{
	init();
	printf("%.15f\n",work(s,tot-1,s[tot]));
	cerr<<"total_edge="<<total_edge<<endl;
	return 0;
}
}
int main()
{	
	//freopen("jenga.in","r",stdin);
	//freopen("jenga.out","w",stdout);
	jenga::Main();
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}