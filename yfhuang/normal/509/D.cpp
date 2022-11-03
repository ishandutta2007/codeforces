#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
string s;
int n,x,y,m;
int b[200],a[200],v[200][200],minv,at,maxv;
int tmp;
int ai,cc;
int g=-1;
int gcd(int a,int b)
{
    if(a<b)return gcd(b,a);
    if(a%b==0)return b;
    return gcd(b,a%b);
}
void work(int x)
{
    if(g==-1){g=x;return ;}
    g=gcd(g,x);
    return ;
}
int main()
{
    cin>>n>>m;
    maxv=1;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)
    {
        
        scanf("%d",&v[i][j]);
        if(v[i][j]>maxv)maxv=v[i][j];
    }
    a[1]=0;
    for(int j=1;j<=m;j++)b[j]=v[1][j];
    for(int i=1;i<=n;i++)a[i]=v[i][1]-b[1];
    g=-1;
    for(int i=2;i<=n;i++)for(int j=1;j<=m;j++)
    {
        
        ai=v[i][j]-b[j];
        cc=ai-a[i];
        if(cc<0)cc=-cc;
        if(cc)work(cc);
    }
    if(g!=-1&&g<=maxv)
    {
        cout<<"NO";
        return 0;
    }
    //cout<<"g:"<<g<<endl;
    if(g==-1)g=maxv+1;
    cout<<"YES"<<endl;
    cout<<g<<endl;
    for(int i=1;i<=n;i++)
    {
        a[i]%=g;
        if(a[i]<0)a[i]+=g;
        
        cout<<a[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<=m;i++)
    {
        b[i]%=g;
        if(b[i]<0)b[i]+=g;
        cout<<b[i]<<" ";
        
    }cout<<endl;
    return 0;
}