#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
#define lowb(x) ((x)&(-x))
int a[200010];
int b[200010];
int c[200010];
int cnt[200010];
int main()
{
    int n;cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    for(int i=0;i<=200000;i++)
    {
        if(cnt[i]>2)
        {
            cout<<"NO"<<endl;
            return 0;
        }
    }
    sort(a,a+n);
    int oldn=-1;
    int pb=0,pc=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]==oldn)c[pc++]=a[i];
        else b[pb++]=a[i];
        oldn=a[i];
    }
    cout<<"YES"<<endl;
    cout<<pb<<endl;
    for(int i=0;i<pb;i++)cout<<b[i]<<" ";
    cout<<endl;
    cout<<pc<<endl;
    for(int i=pc-1;i>=0;i--)cout<<c[i]<<" ";
    cout<<endl;
}