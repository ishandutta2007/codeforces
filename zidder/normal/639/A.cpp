#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
priority_queue < pair <int, int> > p;
int n,i,q,a[150150],mark[150150],k,j,x,y;
pair <int, int> w;
int main()
{
    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &q);
    for (i=1; i<=n; i++)
        scanf("%d", a+i);
    w.first=w.second=0;
    for (i=0; i<k; i++)
        p.push(w);
    for (i=0; i<q; i++)
    {
        scanf("%d", &x);
        scanf("%d", &y);
        if (x==1)
        {
            w=p.top();
            if ((-1)*w.first>a[y]) continue;
            mark[w.second]=0;
            mark[y]=1;
            p.pop();
            w.first=(-1)*a[y];
            w.second=y;
            p.push(w);
            continue;
        }
        if (mark[y]==1) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}