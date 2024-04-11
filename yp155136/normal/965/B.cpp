#include <bits/stdc++.h>
using namespace std;

const int N = 106;

int pre[N][N];
int a[N][N];

int n;

int cal(int x1,int y1,int x2,int y2)
{
    if (x1 < 0 ||y1 < 0 || x2 > n || y2>n) return -1;
    return pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1];
}

int cnt[N][N];

int main ()
{
    int k;
    cin >> n >> k;
    for (int i=1;n>=i;i++)
    {
        string s;
        cin >>s;
        for (int j=1;n>=j;j++)
        {
            if (s[j-1] == '.') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }
    for (int i=1;n>=i;i++)
    {
        for (int j=1;n>=j;j++)
        {
            pre[i][j] = pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1] + a[i][j];
        }
    }
    //cout << cal(1,3,n,n) << endl;
    for (int i=1;n>=i;i++)
    {
        for (int j=1;n>=j;j++)
        {
            for (int kk=0;k>kk;kk++)
            {
                //cout << i+kk-k+1 << ' ' << i+kk << ' ' << j << ' ' << j << endl;
                if (cal(i+kk-k+1,j,i+kk,j) == k) cnt[i][j]++;
            }
            for (int kk=0;k>kk;kk++)
            {
                if (cal(i,j+kk-k+1,i,j+kk) == k) cnt[i][j]++;
            }
            //cout << "i = " << i << " , j = " << j << " , cnt = " << cnt[i][j] <<endl;
        }
    }
    int mx=-1;
    int x=-1,y=-1;
    for (int i=1;n>=i;i++)
    {
        for (int j=1;n>=j;j++)
        {
            if (cnt[i][j] > mx)
            {
                mx = cnt[i][j];
                x = i;
                y = j;
            }
        }
    }
    cout << x << ' ' << y <<endl;
}