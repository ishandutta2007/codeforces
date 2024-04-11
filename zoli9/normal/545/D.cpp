#include <iostream>
#include <algorithm>
using namespace std;
int n;
long long ido=0;
int db=0;
int t[100009];
int rendez(const void *a, const void *b)
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
    qsort(t+1, n, sizeof(int), rendez);
    for(int i=1; i<=n; i++)
    {
        if(ido<=t[i])
        {
            db++;
            ido+=t[i];
        }
    }
    cout<<db;
    return 0;
}