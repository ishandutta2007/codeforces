#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int a[101];
int b[101];


int ren(const void *x, const void *y)
{
    return (*(int*)x)-(*(int*)y);
}



int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>b[i];
    }

    qsort(a+1, n, sizeof(int), ren);
    qsort(b+1, m, sizeof(int), ren);

    int l, q;
    l=1;
    q=0;
    for(int i=1; i<=n; i++)
    {
        for(int j=l; j<=m; j++)
        {
            if(a[i]==b[j]+1 || a[i]==b[j] || a[i]==b[j]-1)
            {
                l=j+1;
                q++;
                break;
            }
        }
    }
    cout<<q;
    return 0;
}