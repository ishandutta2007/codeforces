#include <bits/stdc++.h>
using namespace std;

const int N = 100006;
const int K = 106;

vector<int> v[K];
vector<int> G[N];
int a[N];

int dis[K][N];

int main ()
{
    memset(dis,-1,sizeof(dis));
    int n,m,k,s;
    scanf("%d %d %d %d",&n,&m,&k,&s);
    for (int i=1;n>=i;i++)
    {
        scanf("%d",&a[i]);
        v[ a[i] ].push_back(i);
    }
    for (int i=1;m>=i;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        G[x].push_back(y);
        G[y].push_back(x);
    }
    for (int i=1;k>=i;i++)
    {
        queue<int> que;
        for (int j:v[i])
        {
            dis[i][j] = 0;
            que.push(j);
        }
        while (!que.empty())
        {
            int t=que.front();
            que.pop();
            for (int j:G[t])
            {
                if (dis[i][j] == -1)
                {
                    dis[i][j] = dis[i][t] + 1;
                    que.push(j);
                }
            }
        }
    }
    for (int i=1;n>=i;i++)
    {
        vector<int> v;
        for (int j=1;k>=j;j++)
        {
            v.push_back(dis[j][i]);
            //cout << "dis[" << j << "][" << i << "] = " << dis[j][i] << endl;
        }
        sort(v.begin(),v.end());
        int sum=0;
        for (int j=0;s>j;j++)
        {
            sum += v[j];
        }
        printf("%d%c",sum," \n"[i==n]);
    }
}