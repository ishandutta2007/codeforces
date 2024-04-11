#include <iostream>
#include <vector>
using namespace std;
bool bejar[10005];
int n, m;
int akt;
int sor[10005];
int szint[10005];
int sk, sv;
vector<int> p[10005];
int main()
{
    cin>>n>>m;
    for(int i=1; i<=10000; i++)
    {
        if(i-1>=1 && i-1<=10000)
        {
            p[i].push_back(i-1);
        }
                if(2*i>=1 && 2*i<=10000)
        {
            p[i].push_back(2*i);
        }
    }

    sv=1;
    sk=1;
    szint[n]=0;
    sor[1]=n;

    while(sk<=sv)
    {
        akt=sor[sk];
        sk++;
        for(int i=0; i<p[akt].size(); i++)
        {
            if(!bejar[p[akt][i]])
            {
                bejar[p[akt][i]]=true;
                sv++;
                sor[sv]=p[akt][i];
                szint[sor[sv]]=szint[akt]+1;
            }
        }
    }
    cout<<szint[m];
    return 0;
}