#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t[109];
int ren(const void *a, const void *b)
{
    return (*(int*)a)-(*(int*)b);
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    qsort(t+1, n, sizeof(int), ren);
    cout<<t[n]<<" ";
    for(int i=2; i<=n-1; i++)
    {
        cout<<t[i]<<" ";
    }
    cout<<t[1];
    return 0;
}