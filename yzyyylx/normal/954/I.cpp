#include<bits/stdc++.h>
#define db double
#define N 300100
const db pi=acos(-1);
using namespace std;

int n,m,l,rev[N];
char S[N],T[N];
struct Bcj
{
    int fa[10],ans;
    int ff(int u){return u==fa[u]?u:fa[u]=ff(fa[u]);}
    void init(){int i;for(i=0;i<6;i++) fa[i]=i;}
    void mg(int u,int v)
    {
	u-='a',v-='a';
	u=ff(u),v=ff(v);
	if(u==v) return;
	ans++;
	fa[u]=v;
    }
}bcj[N];
struct Xs
{
    db ss,xs;
    Xs operator + (const Xs &u) const{return (Xs){ss+u.ss,xs+u.xs};}
    Xs operator - (const Xs &u) const{return (Xs){ss-u.ss,xs-u.xs};}
    Xs operator * (const Xs &u) const{return (Xs){ss*u.ss-xs*u.xs,ss*u.xs+xs*u.ss};}
}a[N],b[N];

inline void fft(Xs *a,bool dft)
{
    int i,j,k;
    Xs x,y,dw,now;
    for(i=0;i<l;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    for(i=1;i<l;i<<=1)
    {
	dw=(Xs){cos(pi/(db)i),sin(pi/(db)i)};
	for(j=0;j<l;j+=(i<<1))
	{
	    now=(Xs){1,0};
	    for(k=j;k<j+i;k++)
	    {
		x=a[k];
		y=a[k+i]*now;
		a[k]=x+y;
		a[k+i]=x-y;
		now=now*dw;
	    }
	}
    }
    if(!dft)
    {
	for(i=0;i<l;i++) a[i].ss/=(db)l;
	reverse(a+1,a+l);
    }
}

inline void work(int u,int v)
{
//    cerr<<u<<" "<<v<<endl;
    int i;
    for(i=0;i<l;i++) a[i]=b[i]=(Xs){0,0};
    for(i=0;i<n;i++) a[i].ss=(S[i]==u);
    for(i=0;i<m;i++) b[i].ss=(T[i]==v);
    reverse(b,b+m);
//    for(i=0;i<l;i++) cout<<(int)(a[i].ss+0.5)<<" ";puts("");
//    for(i=0;i<l;i++) cout<<(int)(b[i].ss+0.5)<<" ";puts("");
    fft(a,1),fft(b,1);
    for(i=0;i<l;i++) a[i]=a[i]*b[i];
    fft(a,0);
//    for(i=0;i<l;i++) cout<<(int)(a[i].ss+0.5)<<" ";puts("");puts("");
    for(i=0;i<=n-m;i++)
    {
	if(fabs(a[i+m-1].ss)>0.5)
	    bcj[i].mg(u,v);
    }
//    cerr<<" "<<u<<" "<<v<<endl;
}

int main()
{
    int i,j;
    scanf("%s%s",S,T);
    n=strlen(S);
    m=strlen(T);
    for(i=0;i<=n-m;i++) bcj[i].init();
    for(l=1;l<n;l<<=1);l<<=1;
    for(i=1;i<l;i++) rev[i]=(rev[i>>1]>>1)|((i&1)*l/2);
//    for(i=0;i<l;i++) cout<<rev[i]<<' ';return 0;
    for(i='a';i<='f';i++)
    {
	for(j='a';j<='f';j++)
	{
	    if(i==j) continue;
	    work(i,j);
	}
    }
    for(i=0;i<=n-m;i++) printf("%d ",bcj[i].ans);
}