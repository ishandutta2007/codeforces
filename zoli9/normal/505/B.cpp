#include <iostream>
#include <vector>
using namespace std;
vector<int> p[101][101];
int n, m, q;
int qs[101];
int qe[101];
int qdarab[101];
bool bejar[101];
int mely(int l, int sz)
{
    bejar[l]=true;
    for(int f=0; f<p[sz][l].size(); f++)
    {
        if(!bejar[p[sz][l][f]])
        {
            mely(p[sz][l][f], sz);
        }
    }


    return 0;
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b, c;
        cin>>a>>b>>c;
        p[c][a].push_back(b);
        p[c][b].push_back(a);
    }
    cin>>q;
    for(int i=1; i<=q; i++)
    {
        cin>>qs[i]>>qe[i];
    }

    for(int i=1; i<=q; i++)
    {
        qdarab[i]=0;
    }

    for(int i=1; i<=q; i++)
    {
        for(int szin=1; szin<=m; szin++)
        {
            for(int x=1; x<=n; x++)
            {
                bejar[x]=false;
            }
            mely(qs[i], szin);
            if(bejar[qe[i]])
            {
                qdarab[i]++;
            }
        }
    }

    for(int i=1; i<=q; i++)
    {
        cout<<qdarab[i]<<endl;
    }


    return 0;
}