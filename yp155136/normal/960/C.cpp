#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int x,d;
    scanf("%d %d",&x,&d);
    vector<long long int> v;
    long long now = 1;
    while (x)
    {
        for (int _=32;_>=1;_--)
        {
            if (x >= (1LL<<_)-1)
            {
                x -= ((1LL<<_)-1);
                while (_--) v.push_back(now);
                now += (d+1);
                break;
            }
        }
    }
    printf("%d\n",(int)v.size());
    for (int i=0;v.size()>i;i++)
    {
        if (i) printf(" ");
        printf("%lld",v[i]);
    }
    puts("");
}