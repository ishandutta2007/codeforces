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
const int N=1000*1000;
//const int N=10;
long long a[N+5], b[N+5];
char s[N];
void re(long long *a)
{
    gets(s);
    int n=strlen(s);
    int la=N-1;
    for (int i=n-1, j=la;i>=0;--i, --j) a[j]=s[i]-'0';
}
int cm(long long a, long long b)
{
    if (a>b+b) return 2;
    long long t1=5*a*a, t2=(b+b-a)*(b+b-a);
    if (t1==t2) throw;
    return t1<t2?0:2;
}
int cmp()
{
    for (int i=0;i<N;++i)
    {
        long long t=min(a[i], b[i]);
        a[i]-=t;
        b[i]-=t;
        if (a[i]>2000000) return 2;
        if (b[i]>2000000) return 0;
        if (i+2<N)
        {
            a[i+1]+=a[i]; a[i+2]+=a[i]; a[i]=0;
            b[i+1]+=b[i]; b[i+2]+=b[i]; b[i]=0;
        }
    }
    if (a[N-1]==b[N-1]&&a[N-2]==b[N-2]) return 1;
    if (a[N-1]<=b[N-1]&&a[N-2]<=b[N-2]) return 0;
    if (a[N-1]>=b[N-1]&&a[N-2]>=b[N-2]) return 2;
    if (a[N-2]) return cm(a[N-2], b[N-1]);
    return 2-cm(b[N-2], a[N-1]);
}
int main()
{
    //freopen("in.txt", "r", stdin);
    re(a); re(b);
    printf("%c\n", "<=>"[cmp()]);
    return 0;
}