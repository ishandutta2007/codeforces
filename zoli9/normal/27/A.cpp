#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t[3005];
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
    for(int i=1; i<=n; i++)
    {
        if(t[i]!=i)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<n+1;
    return 0;
}