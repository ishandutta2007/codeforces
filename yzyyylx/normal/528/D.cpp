#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define db double
#define eps 0.5
#define N 600100
using namespace std;

int n,m,K,l,ans,S[N],T[N],rev[N],qz[N],qa[N];
const db pi=acos(-1);
char str[N];
bool ok[N];
struct Xs
{
    db ss,xs;
    Xs operator + (const Xs &u) const{return (Xs){ss+u.ss,xs+u.xs};}
    Xs operator - (const Xs &u) const{return (Xs){ss-u.ss,xs-u.xs};}
    Xs operator * (const Xs &u) const{return (Xs){ss*u.ss-xs*u.xs,ss*u.xs+xs*u.ss};}
}a[N],b[N];

inline int zh(char u){return u=='A'?0:u=='C'?1:u=='G'?2:3;}
inline void fft(Xs *a,bool dft)
{
//    puts("in");
    int i,j,k;
    Xs x,y,ea,now;
    for(i=0;i<l;i++) if(i<rev[i]) swap(a[i],a[rev[i]]);
    for(i=1;i<l;i<<=1)
    {
	ea=(Xs){cos(pi/i),sin(pi/i)};
	for(j=0;j<l;j+=(i<<1))
	{
	    now=(Xs){1,0};
	    for(k=j;k<i+j;k++)
	    {
		x=a[k];
		y=a[k+i]*now;
		a[k]=x+y;
		a[k+i]=x-y;
		now=now*ea;
	    }
	}
    }
    if(!dft)
    {
	for(i=0;i<l;i++) a[i].ss/=(db)l;
	reverse(a+1,a+l);
    }
//    puts("out");
}

int main()
{
    int i,j;
    cin>>n>>m>>K;
    scanf("%s",str);
    for(i=0;i<n;i++) S[i]=zh(str[i]);
    scanf("%s",str);reverse(str,str+m);
    for(i=0;i<m;i++) T[i]=zh(str[i]);
    for(i=0;i<=n-m;i++) ok[i]=1;
    for(i=1;i<=n;i<<=1);l=(i<<1);
    for(i=1;i<l;i++) rev[i]=(rev[i>>1]>>1)|((i&1)*l/2);
//    return 0;
    for(i=0;i<4;i++)
    {
	qz[0]=(S[0]==i);for(j=1;j<n;j++) qz[j]=qz[j-1]+(S[j]==i);
	for(j=0;j<m;j++) a[j]=(Xs){T[j]==i,0};for(j=m;j<l;j++) a[j]=(Xs){0,0};
	for(j=0;j<n;j++) b[j]=(Xs){qz[min(n-1,j+K)]-(j-K-1>=0?qz[j-K-1]:0)>0,0};for(j=n;j<l;j++) b[j]=(Xs){0,0};
	qa[0]=(T[0]==i);for(j=1;j<m;j++) qa[j]=qa[j-1]+(T[j]==i);for(j=m;j<l;j++) qa[j]=qa[j-1];
//	for(j=0;j<l;j++) cout<<qa[j]<<" ";puts("");
	
//	for(j=0;j<l;j++) cout<<(int)(a[j].ss+0.5)<<" ";puts("");
//	for(j=0;j<l;j++) cout<<(int)(b[j].ss+0.5)<<" ";puts("");
	
	fft(a,1),fft(b,1);
	for(j=0;j<l;j++) b[j]=a[j]*b[j];
	fft(b,0);
	
//	if(!i) for(j=0;j<l;j++) if(!(int)(b[j].ss-qa[j]+0.5)) cout<<j<<" ";puts("");puts("");
	
	for(j=0;j<=n-m;j++)
	{
	    if(fabs(b[j+m-1].ss-qa[j+m-1])>eps) ok[j]=0;
	}
    }
//    for(i=0;i<=n-m;i++) cout<<ok[i]<<" ";puts("");
    for(i=0;i<=n-m;i++) ans+=ok[i];
    cout<<ans;
}