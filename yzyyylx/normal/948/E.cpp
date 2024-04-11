#include<bits/stdc++.h>
#define N 100100
using namespace std;

int Q,n,m;
struct Str
{
    int n,qz[N],yi[N];
    char str[N];
    inline int calc(int u,int v){return qz[v]-qz[u-1]+(str[v]=='A')*2*(u<=v);}
    inline void pre()
    {
	int i,j;
	n=strlen(str+1);
	for(i=1;i<=n;i++) qz[i]=qz[i-1]+(str[i]!='A');
	for(i=1;i<=n;i++)
	{
	    if(str[i]=='A') yi[i]=yi[i-1]+1;
	    else yi[i]=0;
	}
//	for(i=1;i<=n;i++) cout<<qz[i]<<" ";puts("");
    }
}A,B;

int main()
{
    int i,j,p,q,l,r,cs,ct;
    scanf("%s%s",A.str+1,B.str+1);
    A.pre(),B.pre();
    cin>>Q;
    while(Q--)
    {
	scanf("%d%d%d%d",&p,&q,&l,&r);
	int a=min(A.yi[q],q-p+1),b=min(B.yi[r],r-l+1);
	if(a<b)
	{
	    printf("0");
	    continue;
	}
	q-=min(a,b),r-=min(a,b);
	if(p>q && l<=r)
	{
	    printf("0");
	    continue;
	}
	q-=min(q-p+1,A.yi[q])/3*3;
	if(l>r)
	{
	    if((q-p+1)%3==0 && A.yi[q]>=q-p+1) printf("1");
	    else printf("0");
	    continue;
	}
	cs=A.calc(p,q);
	ct=B.calc(l,r);
//	cerr<<p<<" "<<q<<" "<<l<<" "<<r<<" "<<cs<<" "<<ct<<endl;
	if(cs>ct || ((cs-ct)&1)) printf("0");
	else printf("1");
    }
}