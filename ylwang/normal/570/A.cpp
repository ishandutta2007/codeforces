#include <bits/stdc++.h>
using namespace std;

const int N = 110;

int x,id,city[N];
int n,m,Max;

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        Max = INT_MIN;id = 0;
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&x);
            if(x > Max)
            {
                Max = x;
                id = j;
            }
        }
        city[id]++;
    }
    id = 0;Max = INT_MIN;
    for(int i=1;i<=n;i++)
        if(city[i] > Max)
        {
            Max = city[i];
            id = i;
        }
    printf("%d\n",id);
}