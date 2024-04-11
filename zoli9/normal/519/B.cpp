#include <iostream>
#include <algorithm>
using namespace std;
int n;
int t1[100005];
int t2[100005];
int t3[100005];
int ren(const void *a, const void *b)
{
    return (*(int*)a)-(*(int*)b);
}
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t1[i];
    }
    for(int i=1; i<=n-1; i++)
    {
        cin>>t2[i];
    }
    for(int i=1; i<=n-2; i++)
    {
        cin>>t3[i];
    }
    qsort(t1+1, n, sizeof(int), ren);
    qsort(t2+1, n-1, sizeof(int), ren);
    qsort(t3+1, n-2, sizeof(int), ren);
    for(int i=1; i<=n; i++)
    {
        if(i==n)
        {
            cout<<t1[n]<<endl;
        }
        else
        {
            if(t1[i]!=t2[i])
            {
                cout<<t1[i]<<endl;
                break;
            }
        }
    }

    for(int i=1; i<=n-1; i++)
    {
        if(i==n-1)
        {
            cout<<t2[n-1]<<endl;
        }
        else
        {
            if(t2[i]!=t3[i])
            {
                cout<<t2[i];
                break;
            }
        }
    }
    return 0;
}