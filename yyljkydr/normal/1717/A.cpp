#include<bits/stdc++.h>
using namespace std;

int T;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        cout<<n+(n/2)*2+(n/3)*2<<"\n";
    }
}