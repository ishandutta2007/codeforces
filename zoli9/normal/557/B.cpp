#include <iostream>
#include <algorithm>
using namespace std;
long long n, w;
long long fiumax, lanymax;
long long tea[200009];
int ren(const void *a, const void *b)
{
    return (*(long long*)a)-(*(long long*)b);
}
int main()
{
    cout.precision(7);
    cin>>n>>w;
    for(int i=1; i<=2*n; i++)
    {
        cin>>tea[i];
    }
    qsort(tea+1, 2*n, sizeof(long long), ren);
    fiumax=tea[n+1];
    lanymax=tea[1];
    if(fiumax>2*lanymax)
    {
        cout<<min(3*n*lanymax, w);
        return 0;
    }
    cout<<min(1.5*(long double)n*(long double)fiumax, (long double)w);
    return 0;
}