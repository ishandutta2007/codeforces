#include <iostream>
#include <map>
using namespace std;
typedef long long tint;

map<tint, tint> apps;

int main()
{
    tint n, m, dx, dy;
    cin >> n >> m >> dx >> dy;
    
    tint inv=0;
    for(tint i=0; i<n; i++)
    {
        if((dx*i)%n==1) inv=i;
    }
    
    for(int i=0; i<m; i++)
    {
        tint a, b;
        cin >> a >> b;
        a=(inv*(n-a))%n;
        b=(b+dy*a)%n;
        if(apps.count(b))
        {
            apps[b]++;
        }
        else
        {
            apps[b]=1;
        }
    }
    
    tint best=0, besty=0;
    for(map<tint, tint>::iterator it=apps.begin(); it!=apps.end(); it++)
    {
        if(it->second>best)
        {
            best=it->second;
            besty=it->first;
        }
    }
    
    cout << 0 << " " << besty << endl;
}