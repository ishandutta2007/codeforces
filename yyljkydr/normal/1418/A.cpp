#include<bits/stdc++.h>
using namespace std;

int T;

int x,y,k;

int main()
{
    cin>>T;
    while(T--)
    {
        cin>>x>>y>>k;
        cout<<(k+1ll*k*y-1+x-2)/(x-1)+k<<endl;
    }
}