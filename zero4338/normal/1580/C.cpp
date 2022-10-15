#include<bits/stdc++.h>
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=2e5+5;
int n,m,sqr;
int x[maxn],y[maxn];
struct array
{
	vector<int>dif;int pos=0,val=0;
	void set(int l){dif.resize(l+1);}
	void add(int l,int r,int x)
	{
		dif[l]+=x;
		if(l<=pos&&r>=pos)val+=x;
		if(r+1<dif.size())dif[r+1]-=x;
	}
	void move()
	{
		pos++;
		if(pos==dif.size()){pos=1;val=dif[1];}
		else val+=dif[pos];
	}
}b[500];
int ls[maxn];
void add(int id,int del,int be)
{
	if(x[id]+y[id]>sqr)
		for(int i=be;i+x[id]<=m;i+=x[id]+y[id])
			b[0].add(i+x[id],min(m,i+x[id]+y[id]-1),del);
	else
	{
		be=(be+x[id])%(x[id]+y[id]);
		if(!be)be=x[id]+y[id];
		if(be-1<=x[id])b[x[id]+y[id]].add(be,be+y[id]-1,del);
		else
		{
			b[x[id]+y[id]].add(be,x[id]+y[id],del);
			b[x[id]+y[id]].add(1,be-1-x[id],del);
		}
	}
}
int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++)x[i]=read(),y[i]=read();
	sqr=sqrt(m);
	b[0].set(m);
	for(int i=1;i<=sqr;i++)b[i].set(i);
	for(int i=1;i<=m;i++)
	{
		int opt=read(),k=read();
		add(k,opt==1?1:-1,opt==1?i:ls[k]);
		ls[k]=i;
		for(int i=0;i<=sqr;i++)b[i].move();
		int ret=0;
		for(int i=0;i<=sqr;i++)ret+=b[i].val;
		printf("%d\n",ret);
	}
	return 0;
}