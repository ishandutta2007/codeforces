#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define db double
#define For(i,x,y) for (i=x;i<=y;i++)
using namespace std;
int i,j,k,n,m,a,b,c,d,A,B;
int main() {
    scanf("%d%d%d%d",&a,&b,&c,&d);
    if (b*c<=d*a) A=a*d-b*c,B=a*c,A*=c,B*=d;
    else A=b*c-a*d,B=b*d,A*=d,B*=c;
    if (!A) printf("0/1\n");
    else k=__gcd(A,B),printf("%d/%d\n",A/k,B/k);
    return 0;
}