#include<bits/stdc++.h>
using namespace std;

const int N=2e6+1e3+7;

vector<int> zeta(vector<int>f)
{
    int m=__lg(f.size());
    for(int i=0;i<m;i++)
        for(int j=0;j<f.size();j++)
            if(j>>i&1)
                f[j]^=f[j^(1<<i)];
    return f;
}

int m,n;

vector<int>b,a;

vector<int>solve (vector<int>b,int n)
{
    if(n==b.size())
        return zeta(b);
    auto c=zeta(b);
    //A ^ zeta(C)
    int m=b.size()>>1;
    vector<int>zc;
    int nn=(int)b.size()-n;
    if(n>=m)
    {
        for(int i=b.size()-1;i>=n;i--)
            zc.push_back(c[i]);
        for(int i=n;i>m;i--)
            zc.push_back(0);
    }
    else
    {
        for(int i=b.size()-1;i>=nn;i--)
            zc.push_back(c[i]);
        for(int i=nn-1;i>=0;i--)
            zc.push_back(0);
    }
    reverse(zc.begin(),zc.end());
    auto rc=solve(zc,nn);
    for(int i=0;i<nn;i++)
        b[i]=rc[i];
    return zeta(b);
}

int main()
{
    scanf("%d",&n);
    m=1;
    while(m<n)
        m<<=1;
    b.resize(m);
    for(int i=0;i<n;i++)
        scanf("%d",&b[i]);
    reverse(b.begin(),b.end()); 
    a=solve(b,n);
    reverse(a.begin(),a.begin()+n);
    for(int i=0;i<n;i++)
        printf("%d%c",a[i]," \n"[i+1==n]);
}