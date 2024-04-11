#include <iostream>
using namespace std;
int n;
int ered;
int t[1009];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        if(i==1) ered=t[i];
    }
    while(1)
    {
        bool v=true;
        for(int i=1; i<=n; i++)
        {
            if(t[i]!=i-1)
            {
                v=false;
                break;
            }
        }
        if(v)
        {
            cout<<"Yes";
            return 0;
        }
        for(int i=1; i<=n; i++)
        {
            if(i%2)
            {
                t[i]++;
                if(t[i]==n)
                {
                    t[i]=0;
                }
            }
            else
            {
                t[i]--;
                if(t[i]==-1)
                {
                    t[i]=n-1;
                }
            }
        }
        if(t[1]==ered)
        {
            break;
        }
    }
    cout<<"No";
    return 0;
}