#include <bits/stdc++.h>
using namespace std;
int a, b, n;
int t[109][109];
int main()
{
    cin>>n>>a>>b;
    int cnt=0;
    if(a*b<n)
    {
        cout<<-1;
        return 0;
    }
    for(int i=1; i<=a; i++)
    {
        if(i%2)
        {
            for(int j=1; j<=b; j++)
            {
                if(cnt<n)
                {
                    cnt++;
                    t[i][j]=cnt;
                }
                else t[i][j]=0;
            }
        }
        else
        {
            for(int j=b; j>=1; j--)
            {
                if(cnt<n)
                {
                    cnt++;
                    t[i][j]=cnt;
                }
                else t[i][j]=0;
            }
        }
    }
    for(int i=1; i<=a; i++)
    {
        for(int j=1; j<=b; j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}