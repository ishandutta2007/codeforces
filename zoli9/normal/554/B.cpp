#include <iostream>
using namespace std;
int n;
char c[109][109];
int main()
{
    cin>>n;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin>>c[i][j];
        }
    }
    int maxi=0;
    for(int i=1; i<=n; i++)
    {
        int cnt=0;
        for(int j=i; j<=n; j++)
        {
            bool v=true;
            for(int k=1; k<=n; k++)
            {
                if(c[i][k]!=c[j][k])
                {
                    v=false;
                }
            }
            if(v)
            {
                cnt++;
            }
        }
        maxi=max(maxi, cnt);
    }
    cout<<maxi;
    return 0;
}