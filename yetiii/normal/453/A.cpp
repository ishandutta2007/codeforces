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

double p(int k, int m, int n)
{
    double t=k*1.0/m, r=1;
    while (n)
    {
        if (n&1) r*=t;
        t*=t; n>>=1;
    }
    return r;
}
int main()
{
    //freopen("in.txt", "r", stdin);
    int n, m;
    scanf("%d %d", &m, &n);
    double rs=0;
    for (int k=1;k<=m;++k) rs+=k*(p(k, m, n)-p(k-1, m, n));
    cout<<setprecision(10)<<fixed<<rs<<endl;
    return 0;
}