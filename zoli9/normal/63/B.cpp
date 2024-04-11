#include <iostream>
using namespace std;
int t[105];
int n, k;
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    int cnt=0;
    while(t[1]!=k)
    {
        bool v=true;
        if(t[n]<k)
        {
            t[n]++;
            v=true;
        }
        else
        {
            v=false;
        }
        for(int i=n-1; i>=1; i--)
        {
            if(v)
            {
                if(t[i]<t[i+1]-1)
                {
                    v=true;
                    t[i]++;
                }
                else
                {
                    v=false;
                }
            }
            else
            {
                if(t[i]<t[i+1])
                {
                    t[i]++;
                    v=true;
                }
                else
                {
                    v=false;
                }
            }
        }
        cnt++;
    }
    cout<<cnt;
    return 0;
}