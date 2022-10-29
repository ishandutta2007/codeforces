#include <cstdio>

int _[3];

int min(int a,int b)
{
    return a>b?b:a;
}

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        int x;
        scanf("%d",&x);
        _[x]++;
    }
    int ans=min(_[1],_[2]);
    _[1] -= ans;
    ans += _[1]/3;
    printf("%d\n",ans);
}