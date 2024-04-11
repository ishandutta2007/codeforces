#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        x -= (x%2==0);
        printf("%d%c",x," \n"[i==n]);
    }
}