#include <bits/stdc++.h>
using namespace std;
long long n;
long long t[2009];
long long hanynagyobb[10009];
long long panasz;
long long hanykul[5009];
long long osszesen;
long long o2;
long double w1;
long double w2;
vector<long long> v;
int main()
{
    cout.precision(10);
    cout<<fixed;
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    for(int i=1; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            v.push_back(abs(t[i]-t[j]));
        }
    }
    sort(v.begin(), v.end());
    /*for(int i=0; i<v.size(); i++)
    {
        cout<<v[i]<<endl;
    }*/
    hanynagyobb[v[v.size()-1]]=0;
    long long cnt=v[v.size()-1];
    int index=v.size()-1;
    long long mennyi=0;
    for(long long i=cnt; i>=0; i--)
    {
        hanynagyobb[i]=mennyi;
        while(index>=0 && v[index]==i)
        {
            mennyi++;
            index--;
        }
    }
    for(int i=0; i<v.size(); i++)
    {
        hanykul[v[i]]++;
    }
    for(int i=0; i<=5000; i++)
    {
        for(int j=0; j<=5000; j++)
        {
            panasz+=(hanykul[i]*hanykul[j]*hanynagyobb[i+j]);
        }
    }
    //cout<<panasz<<endl;
    o2=n*(n-1);
    o2/=2;
    osszesen=o2*o2*o2;
    //cout<<osszesen;
    w1=(long double) panasz;
    w2=(long double) osszesen;
    cout<<w1/w2;
    return 0;
}