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

int n, a[1000*1000];
int main()
{
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i=0;i<n;++i) scanf("%d", &a[i]);
    sort(a, a+n);
    long long s=0;
    for (int i=0;i<n;++i) s+=a[i]*1LL*min(n, i+2);
    if (n==1) s=a[0];
    cout<<s<<endl;
    return 0;
}