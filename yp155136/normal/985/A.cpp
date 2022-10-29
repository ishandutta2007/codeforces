#include <bits/stdc++.h>
using namespace std;

const int P = 106;

int p[P];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n/2>=i;i++)
    {
        scanf("%d",&p[i]);
    }
    sort(p+1,p+(n/2)+1);
    int ans = 123456789;
    for (int del=-1;0>=del;del++)
    {
        int tmp=0;
        for (int i=1;n/2>=i;i++)
        {
            tmp += abs(p[i] - (2*i+del));
        }
        ans = min(ans,tmp);
    }
    printf("%d\n",ans);
}