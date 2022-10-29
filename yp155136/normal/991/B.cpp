#include <bits/stdc++.h>
using namespace std;

int a[106];
int pre[106];

int main ()
{
    int n;
    scanf("%d",&n);
    int _5 = 0;
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        _5 += (a[i] == 5);
    }
    sort(a+1,a+n+1);
    int nn;
    for (nn=1;n>=nn;nn++)
    {
        if (a[nn] == 5) break;
    }
    reverse(a+1,a+n+1);
    //reverse(a+1,a+nn);
    for (int i=1;n>=i;i++)
    {
        pre[i] = pre[i-1] + a[i];
    }
    int ans = n;
    for (int i=1;n>=i;i++)
    {
        if ( 2*(pre[i] + (n-i)*5 )>= 9*n) ans = n-i;
    }
    printf("%d\n",ans);
}