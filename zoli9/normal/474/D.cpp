#include <iostream>
using namespace std;
int t, k;
int a[100001];
int b[100001];
int din[100001];
int kum[100001];
int main()
{
    cin>>t>>k;
    for(int i=1; i<=t; i++)
    {
        cin>>a[i]>>b[i];
    }
    din[0]=1;
    for(int i=1; i<k; i++)
    {
        din[i]=1;
    }
    for(int i=k; i<=100000; i++)
    {
        din[i]=din[i-1]+din[i-k];
        if(din[i]>=0)
        {
            din[i]=din[i]%1000000007;
        }
        else
        {
            din[i]=din[i]%1000000007+1000000007;
        }
    }
    kum[0]=0;
    for(int i=1; i<=100000; i++)
    {
        kum[i]=kum[i-1]+din[i];
        if(kum[i]>=0)
        {
            kum[i]=kum[i]%1000000007;
        }
        else
        {
            kum[i]=kum[i]%1000000007+1000000007;
        }
    }
    for(int i=1; i<=t; i++)
    {
        if((kum[b[i]]-kum[a[i]-1])>=0)
        {
            cout<<(kum[b[i]]-kum[a[i]-1])%1000000007<<endl;
        }
        else
        {
            cout<<((kum[b[i]]-kum[a[i]-1])%1000000007)+1000000007<<endl;
        }
    }

    return 0;
}