#include <bits/stdc++.h>
using namespace std;
int n, k;
int t[509];
bool d[502][502][502]; //1..i, j ssz, r rszssz
vector<int> jok;
int main()
{
    cin>>n>>k;
    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
    }
    d[0][0][0]=true;
    for(int i=1; i<=n; i++)
    {
        for(int j=k; j>=0; j--)
        {
            for(int r=j; r>=0; r--)
            {
                if(d[i-1][j][r]) d[i][j][r]=true;
                if(t[i]<=j)
                {
                    if(j-t[i]>=r)
                    {
                        if(d[i-1][j-t[i]][r]) d[i][j][r]=true;
                    }
                    if(t[i]<=r)
                    {
                        if(d[i-1][j-t[i]][r-t[i]]) d[i][j][r]=true;
                    }
                }
            }
        }
    }
    for(int r=0; r<=k; r++)
    {
        if(d[n][k][r]) jok.push_back(r);
    }
    cout<<jok.size()<<endl;
    for(int i=0; i<jok.size(); i++)
    {
        cout<<jok[i]<<" ";
    }
    cout<<endl;
    return 0;
}