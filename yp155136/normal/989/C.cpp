#include <bits/stdc++.h>
using namespace std;

int adj[56][56];
int cnt[4];


void solve_1(int a,int b,int c,int d)
{
    memset(adj,-1,sizeof(adj));
    cnt[0] = a;
    cnt[1] = b;
    cnt[2] = c;
    cnt[3] = d;
    int n=50,m=50;
    int mn_id = -1;
    if (cnt[0] == 1) mn_id = 0;
    else if (cnt[1] == 1) mn_id = 1;
    else if (cnt[2] == 1) mn_id = 2;
    else if (cnt[3] == 1) mn_id = 3;
    for (int i=0;n>i;i++)
    {
        for (int j=0;m>j;j++)
        {
            if (i%2 == 0 && j%2 == 0)
            {
                bool found = false;
                for (int k=0;4>k;k++)
                {
                    if (k == mn_id) continue;
                    if (cnt[k])
                    {
                        found = true;
                        adj[i][j] = k;
                        cnt[k]--;
                        break;
                    }
                }
                if (!found) adj[i][j] = mn_id;
            }
            else
            {
                adj[i][j] = mn_id;
            }
            printf("%c",char(adj[i][j] + 'A'));
        }
        puts("");
    }
}

int main ()
{
    int a,b,c,d;
    scanf("%d %d %d %d",&a,&b,&c,&d);
    puts("50 50");
    if (min( min(a,b) , min(c,d) ) == 1)
    {
        solve_1(a,b,c,d);
        return 0;
    }
    int n=50,m = 50;
    cnt[0]=a,cnt[1]=b,cnt[2]=c,cnt[3]=d;
    cnt[0]--;
    for (int i=0;8>i;i++)
    {
        for (int j=0;m>j;j++)
        {
            if (i%2 == 0 && j%2 == 0)
            {
                if (cnt[1] != 1)
                {
                    adj[i][j] = 1;
                    cnt[1]--;
                }
                else adj[i][j] = 0;
            }
            else adj[i][j] = 0;
            printf("%c",char(adj[i][j] + 'A'));
        }
        puts("");
    }
    for (int i=8;10>i;i++)
    {
        for (int j=0;m>j;j++)
        {
            adj[i][j] = 1;
            printf("%c",char(adj[i][j] + 'A'));
        }
        puts("");
    }
    int mn_id = 1;
    for (int i=10;n>i;i++)
    {
        for (int j=0;m>j;j++)
        {
            if (i%2 == 0 && j%2 == 0)
            {
                bool found = false;
                for (int k=0;4>k;k++)
                {
                    if (k == mn_id) continue;
                    if (cnt[k])
                    {
                        found = true;
                        adj[i][j] = k;
                        cnt[k]--;
                        break;
                    }
                }
                if (!found) adj[i][j] = mn_id;
            }
            else
            {
                adj[i][j] = mn_id;
            }
            printf("%c",char(adj[i][j] + 'A'));
        }
        puts("");
    }
}