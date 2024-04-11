#include <iostream>
#include <algorithm>
using namespace std;
int rendez(const void *a, const void *b)
{
    return (*(int*)a)-(*(int*)b);
}
int n;
int ossz;
int t[3009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    qsort(t+1, n, sizeof(int), rendez);
    for(int i=2; i<=n; i++)
    {
        if(t[i]<=t[i-1])
        {
            ossz+=(t[i-1]-t[i]+1);
            t[i]=t[i-1]+1;
        }
    }
    cout<<ossz;
    return 0;
}