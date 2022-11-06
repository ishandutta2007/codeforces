#include <cstdio>
#include <algorithm>
#include <utility>
#include <vector>
#include <set>
#include <map>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int n, m;
const int M=2e6;
double lf[M], p[M];
double C(int n, int k)
{
    if (k<0||k>n) throw;
    return lf[n]-lf[k]-lf[n-k];
}
double gp(int k)
{
    double r=0;
    r+=lf[n-1];
    r+=C(m-1, k-1);
    r+=C(m*(n-1), n-k);
    r+=lf[(m-1)*n];
    r-=lf[n*m-1];
    return exp(r);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    for (int i=1;i<M;++i) lf[i]=lf[i-1]+log(i);
    scanf("%d %d", &n, &m);
    double s=0;
    for (int k=1;k<=min(n, m);++k) p[k]=gp(k), s+=p[k];
    //cerr<<s<<endl;
    double pr=0;
    for (int k=1;k<=min(n, m);++k) pr+=k*p[k]/n;
    cout<<setprecision(13)<<fixed<<pr<<endl;
    return 0;
}