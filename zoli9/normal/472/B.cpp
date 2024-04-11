#include <iostream>
#include <algorithm>
using namespace std;
int n, k, osszeg;
int t[2001];
int ren(const void *a, const void *b)
{
    return (*(int*)b)-(*(int*)a);
}
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    qsort(t+1, n, sizeof(int), ren);
    osszeg=0;
    for(int i=1; i<=n; i++)
    {
        if(i % k==1 || k==1)
        {
            osszeg+=2*(t[i]-1);

        }
    }

    cout<<osszeg;

    return 0;
}