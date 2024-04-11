#include <bits/stdc++.h>
using namespace std;
int n, t;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int besta=-1;
    int bestp=-1;
    cin>>n>>t;
    for(int i=1; i<=n; i++)
    {
        int a, b;
        cin>>a>>b;
        while(a<t) a+=b;
        if(besta==-1 || a<besta)
        {
            besta=a;
            bestp=i;
        }
    }
    cout<<bestp<<endl;
    return 0;
}