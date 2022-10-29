#include <bits/stdc++.h>
using namespace std;

const int N = 1000006;

int p[N];
bool vis[N];

int main ()
{
    int n;
    scanf("%d",&n);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&p[i]);
    }
    int ans=0;
    for (int i=1;n>=i;i++)
    {
        if (!vis[i])
        {
            ++ans;
            int now=i;
            while (!vis[now])
            {
                vis[now] = true;
                now = p[now];
            }
        }
    }
    if (ans&1) puts("Um_nik");
    else puts("Petr");
}