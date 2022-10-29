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
using namespace std;
typedef long long ll;
int n, a[111111], b[111111], m;
ll d[111111];
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    map<int, int> s;
    for (int i=0;i<n;++i)
    {
        int a; scanf("%d", &a); ++s[a];
    }
    for (auto p:s)
    {
        a[m]=p.first;
        b[m]=p.second;
        ++m;
    }
    for (int i=0;i<m;++i)
    {
        if (i==0||a[i-1]+1<a[i]) d[i+1]=d[i]+a[i]*1LL*b[i];
        else d[i+1]=d[i-1]+a[i]*1LL*b[i];
        if (i) d[i+1]=max(d[i+1], d[i]);
    }
    cout<<d[m]<<endl;
    return 0;
}