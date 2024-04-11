#include <bits/stdc++.h>
using namespace std;
int n;
long long L;
long long C[39];
long long ans=-1;
long long cur=0;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>L;
    for(int i=0; i<n; i++)
    {
        cin>>C[i];
    }
    for(int i=1; i<n; i++)
    {
        C[i]=min(C[i], 2*C[i-1]);
    }
    for(int i=n-1; i>=0; i--)
    {
        /*while((1<<i)<=L)
        {
            cur+=C[i];
            L-=(1<<i);
        }*/
        int megvan=L/(1<<i);
        cur+=C[i]*megvan;
        L-=((1<<i)*megvan);
        if(L==0)
        {
            if(ans==-1 || cur<ans) ans=cur;
            cout<<ans<<endl;
            return 0;
        }
        if(ans==-1 || cur+C[i]<ans) ans=cur+C[i];
    }
    cout<<ans<<endl;
    return 0;
}