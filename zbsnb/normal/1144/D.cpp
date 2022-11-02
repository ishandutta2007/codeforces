#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define lowb(x) ((x)&(-x))
int cnt[200010];
int a[200010];
int main()
{
    int n;cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    int num=0;
    int maxn=0;
    for(int i=0;i<=200005;i++)
    {
        if(cnt[i]>maxn)
        {
            maxn=cnt[i];
            num=i;
        }
    }
    int fpos=0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]==num)
        {
            fpos=i;
            break;
        }
    }
    cout<<n-maxn<<endl;
    for(int i=fpos-1;i>=1;i--)
    {
        if(a[i]<num)
            cout<<1<<" "<<i<<" "<<i+1<<endl;
        else
            cout<<2<<" "<<i<<" "<<i+1<<endl;
    }
    for(int i=fpos+1;i<=n;i++)
    {
        if(a[i]<num)
            cout<<1<<" "<<i<<" "<<i-1<<endl;
        if(a[i]>num)
            cout<<2<<" "<<i<<" "<<i-1<<endl;
    }
}