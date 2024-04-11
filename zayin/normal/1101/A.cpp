#include<bits/stdc++.h>
#define maxn 200050
using namespace std;
typedef long long LL;

int main()
{
    int T;
    cin>>T;
    while (T--)
    {
        LL l,r,d,ans;
        cin>>l>>r>>d;
        if (d<l||d>r)
            cout<<d<<endl;
        else
        {
            LL D=(r/d+1)*d;
            cout<<D<<endl;
        }
    }
    return 0;
}