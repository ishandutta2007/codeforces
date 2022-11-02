#include <iostream>
using namespace std;
int n;
int t[100005];
int v[100005];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    t[0]=0;
    v[0]=0;
    for(int i=1; i<=n; i++)
    {
        v[i]=v[i-1]+t[i-1]-t[i];
    }
    int mini=0;
    for(int i=1; i<=n; i++)
    {
        if(v[i]<mini)
        {
            mini=v[i];
        }
    }
    mini*=-1;
    cout<<mini;
    return 0;
}