#include <bits/stdc++.h>
using namespace std;
int n;
int t[100009];
int leg=0;
int cnt;
int main()
{
    cin>>n;
    cnt=1;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(i>1)
        {
            if(t[i]>=t[i-1])
            {
                cnt++;
            }
            else
            {
                leg=max(leg, cnt);
                cnt=1;
            }
        }
    }
    leg=max(leg, cnt);
    cout<<leg;

    return 0;
}