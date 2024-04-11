#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int sum[300009];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>s;
    if(n%2==1)
    {
        cout<<":("<<endl;
        return 0;
    }
    int db=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            db++;
        }
    }
    if(2*db>n)
    {
        cout<<":("<<endl;
        return 0;
    }
    sum[0]=0;
    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            sum[i+1]=sum[i]+1;
        }
        else if(s[i]==')')
        {
            sum[i+1]=sum[i]-1;
        }
        else
        {
            if(2*db<n)
            {
                sum[i+1]=sum[i]+1;
                db++;
            }
            else
            {
                sum[i+1]=sum[i]-1;
            }
        }
    }
    for(int i=1; i<n; i++)
    {
        if(sum[i]<=0)
        {
            cout<<":("<<endl;
            return 0;
        }
    }
    if(sum[n]!=0)
    {
        cout<<":("<<endl;
        return 0;
    }
    for(int i=1; i<=n; i++)
    {
        if(sum[i]>sum[i-1]) cout<<"(";
        else cout<<")";
    }
    cout<<endl;
    return 0;
}