#include <bits/stdc++.h>
using namespace std;
int n;
long long t[59];
long long mennyi[59];
bool megesz[59];
long long sum[59];
long long bob[2];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    sum[0]=0;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        sum[i]=sum[i-1]+t[i];
    }
    mennyi[n]=t[n];
    megesz[n]=true;
    for(int i=n-1; i>=1; i--)
    {
        mennyi[i]=t[i]+(sum[n]-sum[i]-mennyi[i+1]);
        long long ot=mennyi[i+1];
        if(ot>mennyi[i])
        {
            mennyi[i]=ot;
        }
        else
        {
            megesz[i]=true;
        }
        //cout<<i<<" "<<mennyi[i]<<endl;
    }
    int cur=0;
    for(int i=1; i<=n; i++)
    {
        //cout<<"m "<<megesz[i]<<endl;
        if(megesz[i])
        {
            bob[cur]+=t[i];
            cur=1-cur;
        }
        else
        {
            bob[1-cur]+=t[i];
        }
        //cout<<"* "<<bob[0]<<" "<<bob[1]<<endl;
    }
    cout<<bob[1]<<" "<<bob[0]<<endl;
    return 0;
}