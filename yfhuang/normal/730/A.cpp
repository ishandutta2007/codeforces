#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int r[110],rmin;
struct as{int i,x;}a[110];
bool cmp(as a1,as a2){return a1.x>a2.x;}
int n;
bool flg;
int g[20000][110];
int t;
int main()
{
    cin>>n;
    rmin=110;
    for(int i=1;i<=n;i++){cin>>r[i];rmin=min(rmin,r[i]);}
    
    for(int R=rmin;R>0;R--)
    {
        flg=1;t=0;
        memset(g,0,sizeof(g));
        int s=0;
        for(int i=1;i<=n;i++){a[i].i=i;a[i].x=r[i]-R;s+=a[i].x;}
        
        sort(a+1,a+n+1,cmp);
        
        if(s%2==1)
        {
            if(n<3||a[3].x==0){flg=0;continue;}
            else
            {
                t++;
                g[t][a[1].i]=1;
                g[t][a[2].i]=1;
                g[t][a[3].i]=1;
                a[1].x--;
                a[2].x--;
                a[3].x--;
            }
        }
        
        while(1)
        {
            sort(a+1,a+n+1,cmp);
            if(a[1].x==0&&a[2].x==0){flg=1;break;}
            
            if(a[2].x==0){flg=0;break;}
            t++;
            g[t][a[1].i]=1;
            g[t][a[2].i]=1;
            a[1].x--;
            a[2].x--;
        
        }
        if(flg)
        {
            cout<<R<<endl;
            cout<<t<<endl;
            for(int i=1;i<=t;i++){for(int j=1;j<=n;j++)cout<<g[i][j];cout<<endl;}
            return 0;
        }
        
    }
        int R=0;
        flg=1;t=0;
        memset(g,0,sizeof(g));
        int s=0;
        for(int i=1;i<=n;i++){a[i].i=i;a[i].x=r[i]-R;s+=a[i].x;}
        while(1)
        {
            sort(a+1,a+n+1,cmp);
            if(a[1].x==0&&a[2].x==0){flg=1;break;}
            t++;
            g[t][a[1].i]=1;
            g[t][a[2].i]=1;
            if(a[1].x)a[1].x--;
            if(a[2].x)a[2].x--;
        }
        if(flg)
        {
            cout<<R<<endl;
            cout<<t<<endl;
            for(int i=1;i<=t;i++){for(int j=1;j<=n;j++)cout<<g[i][j];cout<<endl;}
            return 0;
        }
    

    return 0;
    
}