#include <iostream>
#include <algorithm>
using namespace std;
int n;
struct gyerek
{
    int az;
    int score;
};
gyerek t[2009];
int rendez(const void *a, const void *b)
{
    return (*(gyerek*)b).score-(*(gyerek*)a).score;
}
int hany[2009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i].score;
        t[i].az=i;
    }
    qsort(t+1, n, sizeof(gyerek), rendez);
    hany[t[1].az]=1;
    for(int i=2; i<=n; i++)
    {
        if(t[i].score==t[i-1].score)
        {
            hany[t[i].az]=hany[t[i-1].az];
        }
        else
        {
            hany[t[i].az]=i;
        }
    }
    for(int i=1; i<=n; i++)
    {
        cout<<hany[i]<<" ";
    }
    return 0;
}