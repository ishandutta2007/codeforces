#include <iostream>
#include <cstdio>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <queue>
#include <cmath>
#include <cstring>
using namespace std;

#ifdef __LOCALE__
#define see(a) std::cout << #a << "=" << a << std::endl
#else
#define see(a) //std::cout << #a << "=" << a << std::endl
#endif
#define foreach(a,b) for (int a=0;a<(int)b.size();a++)
#define rep(i,n) for (int i=0;i<n;i++)
#define repa(i,n) for (int i=1;i<=n;i++)
#define repi(i,a,b) for (int i=a;i<=b;i++) 
typedef pair < int , int > pr;
typedef pair < pr  , int > prr;
#define L first
#define R second

int main(){
    int a , b , c;
    scanf("%d%d%d",&a,&b,&c);
    int mx = a - b + c;
    int mn = a - b - c;
    if (mx > 0 && mn > 0) puts("+");
    else if (mx == 0 && mn == 0) puts("0");
    else if (mx < 0 && mn < 0) puts("-");
    else puts("?");
    return 0;
}