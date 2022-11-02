#include <iostream>
#include <algorithm>
using namespace std;
int n, k, db, osszeg;
struct mm
{
    int id;
    int v;
};
mm t[101];

int ren(const void *a, const void *b)
{
    return (*(mm*)a).v-(*(mm*)b).v;
}

int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i].v;
        t[i].id=i;
    }

    qsort(t+1, n, sizeof(mm), ren);


    db=0;
    osszeg=0;
    while(osszeg>-1)
    {
        if(db==n)
        {
            break;
        }
        db++;
        osszeg+=t[db].v;
        if(osszeg>k)
        {
            db--;
            break;
        }
    }

    cout<<db<<endl;
    for(int j=1; j<=db; j++)
    {
        cout<<t[j].id<<" ";
    }

    return 0;
}