#include <bits/stdc++.h>
using namespace std;
int n, m;
struct elel
{
    int suly;
    int berake;
    int az;
};
elel el[100009];
int rendez(const void *x, const void *y)
{
    elel xx=(*(elel*)x);
    elel yy=(*(elel*)y);
    if(xx.suly==yy.suly)
    {
        return yy.berake-xx.berake;
    }
    return xx.suly-yy.suly;
}
int kezd[100009];
int veg[100009];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>el[i].suly>>el[i].berake;
        el[i].az=i;
    }
    qsort(el+1, m, sizeof(elel), rendez);
    int elem=1;
    int szabadx=1;
    int szabady=3;
    for(int i=1; i<=m; i++)
    {
        if(el[i].berake==1)
        {
            elem++;
            kezd[el[i].az]=elem-1;
            veg[el[i].az]=elem;
        }
        else
        {
            if(szabadx>elem || szabady>elem)
            {
                cout<<-1;
                return 0;
            }
            kezd[el[i].az]=szabadx;
            veg[el[i].az]=szabady;
            if(szabadx+2<szabady) szabadx++;
            else
            {
                szabady++;
                szabadx=1;
            }
        }
    }
    for(int i=1; i<=m; i++)
    {
        cout<<kezd[i]<<" "<<veg[i]<<endl;
    }
    return 0;
}