#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vll;

int n, m;
vector<vector<bool> > t;
vector<vector<int> > dad;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        vector<bool> bb;
        vector<int> dd;
        char ccc;
        for(int j=0; j<m; j++)
        {
            cin>>ccc;
            if(ccc=='.') bb.push_back(false);
            else bb.push_back(true);
            dd.push_back(0);
        }
        t.push_back(bb);
        dad.push_back(dd);
    }
    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(i==n-1 && j==m-1)
            {
                dad[i][j]=1;
                continue;
            }
            if(t[i][j]) continue;
            if(j<m-1 && dad[i][j+1]>0)
            {
                dad[i][j]=1;
                continue;
            }
            if(i<n-1 && dad[i+1][j]>0)
            {
                dad[i][j]=2;
                continue;
            }
        }
    }
    if(dad[0][0]==0)
    {
        cout<<0<<endl;
        return 0;
    }
    //cout<<"asd"<<endl;
    int nx=0;
    int ny=0;
    if(dad[0][0]==1) ny++;
    else nx++;
    while(!(nx==n-1 && ny==m-1))
    {
        t[nx][ny]=true;
        if(dad[nx][ny]==1) ny++;
        else nx++;
    }
    dad.assign(n, vector<int>(m, 0));

    for(int i=n-1; i>=0; i--)
    {
        for(int j=m-1; j>=0; j--)
        {
            if(i==n-1 && j==m-1)
            {
                dad[i][j]=1;
                continue;
            }
            if(t[i][j]) continue;
            if(j<m-1 && dad[i][j+1]>0)
            {
                dad[i][j]=1;
                continue;
            }
            if(i<n-1 && dad[i+1][j]>0)
            {
                dad[i][j]=2;
                continue;
            }
        }
    }
    if(dad[0][0]==0)
    {
        cout<<1<<endl;
        return 0;
    }

    cout<<2<<endl;

    return 0;
}