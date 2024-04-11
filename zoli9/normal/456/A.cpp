#include <iostream>
#include <algorithm>
using namespace std;
int n;
int v=false;
struct gep
{
    int a, b;
};
gep g[100005];
int ren(const void *x, const void *y)
{
    if((*(gep*)x).a-(*(gep*)y).a!=0)
    {
        return (*(gep*)x).a-(*(gep*)y).a;
    }
    return (*(gep*)x).b-(*(gep*)y).b;
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>g[i].a>>g[i].b;
    }
    qsort(g+1, n, sizeof(gep), ren);
    for(int i=2; i<=n; i++)
    {
        if(g[i].a>g[i-1].a && g[i].b<g[i-1].b)
        {
            v=true;
        }
    }
    if(v)
    {
        cout<<"Happy Alex";
        return 0;
    }
    cout<<"Poor Alex";
    return 0;
}