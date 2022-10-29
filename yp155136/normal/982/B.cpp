#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

#define F first
#define S second

int main ()
{
    int n;
    scanf("%d",&n);
    set<pii> _0,_1;
    for (int i=1;n>=i;i++)
    {
        int w;
        scanf("%d",&w);
        _0.insert(make_pair(w,i));
    }
    getchar();
    for (int i=1;2*n>=i;i++)
    {
        if (i!=1) printf(" ");
        char c = getchar();
        if (c == '0')
        {
            pii p = (*_0.begin());
            _0.erase(_0.begin());
            printf("%d",p.S);
            _1.insert(make_pair(-p.F,p.S));
        }
        else if (c == '1')
        {
            pii p = (*_1.begin());
            _1.erase(_1.begin());
            printf("%d",p.S);
        }
    }
    puts("");
}