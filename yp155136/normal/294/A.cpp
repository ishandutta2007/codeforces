#include <bits/stdc++.h>
using namespace std;

const int N = 106;

int a[N];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
    }
    int m;
    scanf("%d",&m);
    for (int i=1;m>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        int ii=i;
        i=x;
        a[i-1] += (y-1);
        a[i+1] += (a[i]-y);
        a[i] = 0;
        i=ii;
    }
    for (int i=1;n>=i;i++)
    {
        printf("%d\n",a[i]);
    }
}