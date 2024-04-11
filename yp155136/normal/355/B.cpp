#include <bits/stdc++.h>
using namespace std;

//#define int long long

int main ()
{
    int c1,c2,c3,c4;
    cin >> c1 >> c2 >> c3 >> c4;
    int ans = c4;
    int n,m;
    cin >> n >> m;
    int a[n];
    int gee=0;
    for (int i=0;n>i;i++)
    {
        cin >> a[i];
        gee += min(c1*a[i],c2);
    }
    gee = min(gee,c3);
    int gee2=0;
    int b[m];
    for (int i=0;m>i;i++)
    {
        cin >> b[i];
        gee2 += min(c1*b[i],c2);
    }
    gee2 = min(gee2,c3);
    cout << min(c4,gee + gee2)<<endl;
}