#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=150005,M=200005;
int n,k,a[N],b[N],tot,an[N],t1,t2,m;
string s;
struct data{
	char c;
	int v,num,ans;
}q[M];
inline bool cmp(data x,data y){
	return x.c<y.c;
}
inline bool cmp1(data x,data y){
	return x.num<y.num;
}
inline void doit(int x,char c)
{
	for(int i=0;i<=n;i++)an[i]=0;
	for(int i=1;i<=n;i++){
		int t=i,zs=0,ans=0;
		while(t<=n){
			if(s[t]!=c)zs++; ans++;
			an[zs]=max(an[zs],ans); t++;
		}
	}
	for(int i=1;i<=n;i++)an[i]=max(an[i],an[i-1]);
	q[x].ans=an[q[x].v];while(c==q[x+1].c||x+1<=m){x++;q[x].ans=an[q[x].v];}
}
int main()
{
	cin>>n; cin>>s;
	s=' '+s;
	cin>>m;
	for(int i=1;i<=m;i++)cin>>q[i].v>>q[i].c,q[i].num=i; 
	sort(&q[1],&q[m+1],cmp);
	for(int i=1;i<=m;i++)
		if(i==1)doit(i,q[i].c);else if (q[i].c!=q[i-1].c)doit(i,q[i].c);
	sort(&q[1],&q[m+1],cmp1);
	for(int i=1;i<=m;i++)	printf("%d\n",q[i].ans);
}