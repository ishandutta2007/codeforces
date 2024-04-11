#include <iostream>
#include <vector>
using namespace std;
int n, m, komp;
int w;
long long s;
long long hat(int e)
{
    if(e==0)
    {
        return 1;
    }
    return 2*hat(e-1);
}
vector<int> p[75];
bool bejar[75];
int mely(int x)
{
    bejar[x]=true;
    for(int i=0; i<p[x].size(); i++)
    {
        if(!bejar[p[x][i]])
        {
            mely(p[x][i]);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        int a, b;
        cin>>a>>b;
        p[a].push_back(b);
        p[b].push_back(a);
    }
    komp=0;
    for(int i=1; i<=n; i++)
    {
        if(!bejar[i])
        {
            komp++;
            mely(i);
        }
    }
    w=n-komp;
    cout<<hat(w);
    return 0;
}