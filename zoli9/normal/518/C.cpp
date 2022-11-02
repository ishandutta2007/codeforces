#include <iostream>
using namespace std;
int n, m, k;
int sor[100005];
int alk[100005];
int hanyadik[100005];
long long valasz;
int main()
{
    valasz=0;
    cin>>n>>m>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>sor[i];
        hanyadik[sor[i]]=i;
    }
    for(int i=1; i<=m; i++)
    {
        cin>>alk[i];
        valasz+=((hanyadik[alk[i]]/k) + 1);
        if(hanyadik[alk[i]]%k==0)
        {
            valasz--;
        }
        if(hanyadik[alk[i]]>1)
        {
            int e=sor[hanyadik[alk[i]]-1];
            sor[hanyadik[alk[i]]-1]=alk[i];
            sor[hanyadik[alk[i]]]=e;
            hanyadik[e]++;
            hanyadik[alk[i]]--;
        }
    }
    cout<<valasz;
    return 0;
}