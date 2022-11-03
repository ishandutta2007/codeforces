#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int a[110],d[110];
int pre,nex,pi,pj,ni,nj,tmp;
int p[110],ne[110];
int main()
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)cin>>a[i]>>d[i];
    for(int i=1;i<=n;i++)
    {
        p[i]=a[i]*200+n-i+1;
        ne[i]=(a[i]+d[i])*200+n-i+1;
     //   cout<<"  i:"<<i<<"  p:"<<p[i]<<"  ne:"<<ne[i]<<endl;
    }
    
    for(int i=1;i<=n;i++)for(int j=1;j<i;j++)
    {
        pi=p[i];
        ni=ne[i];
        pj=p[j];
        nj=ne[j];
        if(pi>=ni)
        {
            pi=-pi;ni=-ni;pj=-pj;nj=-nj;
        }
        if(pj<pi)
        {
            if(pi<nj&&nj<ni)ans+=2;
            if(ni<nj)ans+=1;
        }
        if(pi<pj&&pj<ni)
        {
            if(nj<pi)ans+=1;
            if(pi<nj&&nj<ni)ans+=1;
            if(ni<nj)ans+=2;
        }
        if(ni<pj)
        {
            if(nj<ni)ans+=1;
        }
        
        
    }
    cout<<ans;
    
}