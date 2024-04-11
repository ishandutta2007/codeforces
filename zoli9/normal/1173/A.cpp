#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
typedef long long ll;
typedef pair<int, int> pii;
int n;
int x, y, z;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>x>>y>>z;
    if(x>y+z)
    {
        cout<<"+"<<endl;
        return 0;
    }
    if(y>x+z)
    {
        cout<<"-"<<endl;
        return 0;
    }
    if(z==0) cout<<"0"<<endl;
    else cout<<"?"<<endl;
    return 0;
}