#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
#include <string.h>
#include <numeric>
using namespace std;

const int mod=1000000007, N=1000*1000;
char S[N];
int a[N], b[N];
int add(int a, int b)
{
    a+=b; if (a>=mod) a-=mod; return a;
}
int mul(int a, int b)
{
    return (a*1LL*b)%mod;
}
void go(string s, int &mo, int &ad)
{
    mo=1; ad=0;
    for (int i=0;i<s.length();++i)
    {
        int d=s[i]-'0';
        mo=mul(mo, a[d]);
        ad=add(mul(ad, a[d]), b[d]);
    }
}
int main()
{
    // freopen("in.txt", "r", stdin);
    gets(S); string s0=S;
    vector<string> q;
    int n; scanf("%d\n", &n);
    for (int i=0;i<n;++i)
    {
        gets(S);
        q.push_back(S);
    }
    for (int i=0;i<10;++i) a[i]=10, b[i]=i;
    for (int it=n-1;it>=0;--it)
    {
        string s=q[it].substr(3);
        int d=q[it][0]-'0';
        int mo, ad;
        go(s, mo, ad);
        a[d]=mo; b[d]=ad;
    }
    int mo, ad;
    go(s0, mo, ad);
    printf("%d\n", ad);
    return 0;
}