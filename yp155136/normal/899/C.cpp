#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

typedef long long LL;

int main ()
{
    int n;
    scanf("%d",&n);
    if (n==1)
    {
        puts("1");
        puts("1 1");
        return 0;
    }
    else if (n==2)
    {
        puts("1");
        puts("1 1");
        return 0;
    }
    else if (n==3)
    {
        puts("0");
        puts("2 1 2");
        return 0;
    }
    else if (n==4)
    {
        puts("0");
        puts("2 1 4");
        return 0;
    }
    LL tot = n*1LL*(n+1)/2;
    LL pre=0;
    int i;
    for (i=1;n>=i;i++)
    {
        pre += i;
        if (pre >= tot/2) break;
    }
    if (tot % 2 == 0)
    {
        set<int> group1;
        for (int x=1;i>=x;x++) group1.insert(x);
        if (pre != tot/2)
        {
            int delta = (pre-tot/2);
            group1.erase(delta);
        }
        puts("0");
        printf("%d",(int)group1.size());
        for (int x:group1)
        {
            printf(" %d",x);
        }
        puts("");
    }
    else
    {
        set<int> group1;
        for (int x=1;i>=x;x++) group1.insert(x);
        if (pre > tot/2)
        {
            group1.erase(pre - tot/2);
        }
        puts("1");
        printf("%d",(int)group1.size());
        for (int i:group1) printf(" %d",i);
        puts("");
    }
}