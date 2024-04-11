#include <bits/stdc++.h>
using namespace std;

int main()
{
    int test;
    cin>>test;
    while(test--)
    {
        int n;
        cin>>n;
        int s=0;
        int ans=0;
        for(int i=0; i<n; i++)
        {
            int a;
            cin>>a;
            if(a==0)
            {
                ans++;
                s++;
            }
            else
            {
                s+=a;
            }
        }
        if(s==0) ans++;
        cout<<ans<<endl;
    }
    return 0;
}