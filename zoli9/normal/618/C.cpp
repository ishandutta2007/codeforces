#include <bits/stdc++.h>
using namespace std;

struct pont
{
    long long x, y;
    int az;
};
int ren(const void *a, const void *b)
{
    pont c=(*(pont*)a);
    pont d=(*(pont*)b);
    if(c.y==d.y)
    {
        if(c.x>d.x) return 1;
        return -1;
    }
    if(c.y>d.y) return 1;
    return -1;
}
long long n;

int fir(pont o, pont x, pont y)
{
    long long cc=(x.x-o.x)*(y.y-o.y)-(x.y-o.y)*(y.x-o.x);
    if(cc>0)
    {
        return 1;
    }
    else if(cc<0)
    {
        return -1;
    }
    return 0;
}
pont t[100009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i].x>>t[i].y;
        t[i].az=i;
    }
    qsort(t+1, n, sizeof(pont), ren);
    /*for(int i=1; i<=n; i++)
    {
        cout<<t[i].az<<endl;
    }*/
    int ind=3;
    while(fir(t[1], t[2], t[ind])==0) ind++;
    cout<<t[1].az<<" "<<t[2].az<<" "<<t[ind].az;
    return 0;
}