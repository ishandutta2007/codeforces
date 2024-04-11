#include <iostream>
using namespace std;
int n, m, db;
int t[1001];
bool v[501];
struct konyv
{
    int id;
    int tomeg;
};
konyv k[501];
konyv x[501];
konyv akt;
long long veg=0;
int main()
{
    cin>>n>>m;
    for(int i=1; i<=n; i++)
    {
        cin>>k[i].tomeg;
        k[i].id=i;
    }
    for(int i=1; i<=m; i++)
    {
        cin>>t[i];
    }
    for(int i=1; i<=n; i++)
    {
        v[i]=false;
    }
    db=0;
    for(int i=1; i<=m; i++)
    {
        if(!v[t[i]])
        {
            db++;
            x[db]=k[t[i]];
            v[t[i]]=true;
        }
    }


    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=db; j++)
        {
            if(x[j].id==t[i])
            {
                akt=x[j];
                for(int aaa=j-1; aaa>=1; aaa--)
                {
                    veg+=x[aaa].tomeg;
                    x[aaa+1]=x[aaa];
                }
                x[1]=akt;
                break;
            }
        }
    }

cout<<veg;
    return 0;
}