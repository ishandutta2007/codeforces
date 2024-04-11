#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int t[5009][5009];
void tolt(int x, int y, int cnt)
{
    for(int i=y; i<y+4; i++)
    {
        t[x][i]=cnt;
        cnt++;
    }
    for(int i=y+3; i>=y; i--)
    {
        t[x+1][i]=cnt;
        cnt++;
    }
    for(int i=y; i<y+4; i++)
    {
        t[x+2][i]=cnt;
        cnt++;
    }
    for(int i=y+3; i>=y; i--)
    {
        t[x+3][i]=cnt;
        cnt++;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int c=0;
    for(int i=0; i<n; i+=4)
    {
        for(int j=0; j<n; j+=4)
        {
            tolt(i, j, c);
            c+=16;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<t[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}