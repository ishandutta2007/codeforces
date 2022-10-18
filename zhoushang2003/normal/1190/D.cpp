#include<bits/stdc++.h>
using namespace std;
const int N=3e5+1,I=1e9;
struct S
{
	int x,y;
};
long long n,x,h,C,p[N],a[N],w[N],s[N][2],t,A,c[N],l,Q[N],V,y,M;
S W[N];
bool E(S x,S y)
{
	return x.x<y.x;
}
bool Y(S x,S y)
{
	if(x.y!=y.y)
		return x.y<y.y;
	return x.x<y.x;
}
void U(int k)
{
    w[k]=w[s[k][0]]+w[s[k][1]]+1;
}
void S(long long &k,bool b)
{
    t=s[k][b],s[k][b]=s[t][!b],s[t][!b]=k,U(k),U(t),k=t;
}
void T(long long &k)
{
    if(!k)
    {
        k=++C,p[k]=rand(),a[k]=x,w[k]=1;
        return;
    }
    w[k]++;
    if(x<=a[k])
    {
        T(s[k][0]);
        if(p[s[k][0]]<p[k])
            S(k,false);
    }
    else
    {
        T(s[k][1]);
        if(p[s[k][1]]<p[k])
            S(k,true);
    }
}
void D(long long &k)
{
    if(a[k]==x)
    {
        if(!s[k][0]||!s[k][1])
        {
            k=s[k][0]+s[k][1];
            return;
        }
        if(p[s[k][0]]<p[s[k][1]])
            S(k,false),D(s[k][1]);
        else
            S(k,true),D(s[k][0]); 
    }
    else if(a[k]<x)
        D(s[k][1]);
    else
        D(s[k][0]);
    U(k);
}
int R(int k)
{
    if(!k)
        return 1;
    if(a[k]>=x)
        return R(s[k][0]);
    return R(s[k][1])+w[s[k][0]]+1;
}
int K(int k,int x)
{
    if(w[s[k][0]]==x-1)
        return a[k];
    if(w[s[k][0]]>=x)
        return K(s[k][0],x);
    return K(s[k][1],x-w[s[k][0]]-1);
}
long long L(int k)
{
    if(!k)
        return -I;
    if(a[k]>=x)
        return L(s[k][0]);
    return max(a[k],L(s[k][1]));
}
long long X(int k)
{
    if(!k)
        return I;
    if(a[k]<=x)
        return X(s[k][1]);
    return min(a[k],X(s[k][0]));
}
int main()
{
    srand(time(NULL));
    ios::sync_with_stdio(false);
    cin>>n;
	for(int i=1;i<=n;i++)
		cin>>W[i].x>>W[i].y;
	sort(W+1,W+n+1,E);
	for(int i=1;i<=n;i++)
		if(W[i].x==W[i-1].x)
			Q[i]=Q[i-1];
		else
			Q[i]=i;
	for(int i=1;i<=n;i++)
		W[i].x=Q[i];
	sort(W+1,W+n+1,Y);
	for(int i=1;i<=n;i++)
		c[W[i].x]++;
	for(int i=1;i<N;i++)
		if(c[i])
			x=i,T(h),V++;
	l=1;
	while(l<=n)
	{
		M=l;
		while(M<=n)
			if(W[M].y==W[l].y)
				M++;
			else
				break;
		x=W[l].x,y=R(h)-1,A-=y*(y+1)/2;
		for(int i=l+1;i<M;i++)
			x=W[i].x,y=R(h),x=W[i-1].x,y-=R(h)+1,A-=y*(y+1)/2;
		x=W[M-1].x,y=V-R(h),A-=y*(y+1)/2;
		A+=V*(V+1)/2;
		for(int i=l;i<M;i++)
		{
			c[W[i].x]--;
			if(!c[W[i].x])
				V--,x=W[i].x,D(h);
		}
		l=M;
	}
	cout<<A;
    return 0;
}