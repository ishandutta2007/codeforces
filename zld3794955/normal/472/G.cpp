#include<iostream>
#include<cstdio>
#include<cctype>
#include<cstring>
using namespace std;
inline int getint()
{
	char ch;
	while(!isdigit(ch=getchar())) ;
	int x=ch-'0';
	while(isdigit(ch=getchar())) x=x*10+ch-'0';
	return x;
}
const int L=202000,B=5,Bit=1<<B,SV=16,V=1<<SV;
char c1[L]={},c2[L]={};
int n,m,q;
unsigned int a[Bit][L/Bit],b[Bit][L/Bit],t[V];
inline int bitcount(unsigned int x)
{
	return t[x>>SV]+t[x&(V-1)];
}
int main()
{
	for(int i=1;i<V;++i)
		t[i]=t[i-(i&(-i))]+1;
	gets(c1);
	gets(c2);
	n=strlen(c1);
	m=strlen(c2);
	for(int j=0;j<Bit;++j)
		for(int i=j;i<n;++i)
			a[j][(i-j)>>B]|=(unsigned int)(c1[i]=='1')<<((i-j)&(Bit-1));
	for(int j=0;j<Bit;++j)
		for(int i=j;i<m;++i)
			b[j][(i-j)>>B]|=(unsigned int)(c2[i]=='1')<<((i-j)&(Bit-1));

	q=getint();
	for(int i=1,u=0,v=0,l=0;i<=q;++i)
	{
		u=getint(),v=getint(),l=getint();
		int du=u&(Bit-1),dv=v&(Bit-1),su=(u-du)>>B,sv=(v-dv)>>B;
		//cout<<"du="<<du<<" dv="<<dv<<" su="<<su<<" sv="<<sv<<endl;
		int rl=l>>B,ans=0;
		for(int j=0;j<rl;++j)
			ans+=bitcount(a[du][su+j]^b[dv][sv+j]);
		unsigned int x=a[du][su+rl],y=b[dv][sv+rl];
		//cout<<"x="<<x<<" y="<<y<<endl;
		for(int j=0;j<(l&(Bit-1));++j)
			ans+=bool((x^y)&(1u<<j));
		printf("%d\n",ans);
	}
	return 0;
}