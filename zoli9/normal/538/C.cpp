#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, m;
int day[100009];
int h[100009];
long long veg=0;
int main()
{
    cin>>n>>m;
    for(int i=1; i<=m; i++)
    {
        cin>>day[i]>>h[i];
    }
    veg=h[1]+day[1]-1;
    for(int i=1; i<m; i++)
    {
        if(abs(day[i+1]-day[i])<abs(h[i+1]-h[i]))
        {
            cout<<"IMPOSSIBLE";
            return 0;
        }
        int maxi=max(h[i], h[i+1]);
        int mini=min(h[i], h[i+1]);
        long long l=day[i+1]-day[i]+mini-maxi;
        l/=2;
        l+=maxi;
        veg=max(veg, l);
    }
    long long c=h[m]+n-day[m];
    veg=max(veg, c);
    cout<<veg;
    return 0;
}