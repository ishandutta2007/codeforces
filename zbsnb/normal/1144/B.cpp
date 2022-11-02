#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100010];
int b[10010];
int c[10010];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    int pb=0,pc=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]%2==0)b[pb++]=a[i];
        else c[pc++]=a[i];
    }
    if(abs(pb-pc)<=1)
    {
        cout<<0<<endl;
        return 0;
    }
    int sum=0;
    if(pb>pc)
    {
        for(int i=0;i<=pb-pc-2;i++)
        {
            sum+=b[i];
        }
    }
    else
    {
        for(int i=0;i<=pc-pb-2;i++)
        {
            sum+=c[i];
        }
    }
    cout<<sum<<endl;
}