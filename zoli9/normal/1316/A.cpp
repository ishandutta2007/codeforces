#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n, m;
        int sum=0;
        cin>>n>>m;
        for(int i=1; i<=n; i++)
        {
            int a;
            cin>>a;
            sum+=a;
        }
        if(sum>m) cout<<m<<endl;
        else cout<<sum<<endl;
    }
    return 0;
}