#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N = 100006;

int g[N],p[N],t[N];
int x[N],y[N];

vector<int> v[2*N];

pii ans[N];

int main ()
{
    int q,h,w;
    scanf("%d %d %d",&q,&h,&w);
    for (int i=1;q>=i;i++)
    {
        scanf("%d %d %d",&g[i],&p[i],&t[i]);
        if (g[i] == 1)
        {
            x[i] = p[i];
            y[i] = -t[i];
            v[ x[i] + y[i] + N ].push_back(i);
        }
        else if (g[i] == 2)
        {
            x[i] = -t[i];
            y[i] = p[i];
            v[ x[i] + y[i] + N ].push_back(i);
        }
    }
    for (int i=0;2*N>i;i++)
    {
        if (v[i].size() == 0) continue;
        vector<pii> answer;
        for (int j:v[i])
        {
            if (g[j] == 1) answer.push_back(make_pair(p[j],w));
            else if (g[j] == 2) answer.push_back(make_pair(h,p[j]));
        }
        sort(v[i].begin(),v[i].end(),[](const int &a,const int &b){
            return x[a] < x[b];
        });
        sort(answer.begin(),answer.end(),[](const pii &a,const pii &b){
            return a.first < b.first || a.first == b.first && a.second > b.second;
        });
        int id=0;
        for (int j:v[i])
        {
            ans[j] = answer[id];
            id++;
        }
    }
    for (int i=1;q>=i;i++)
    {
        printf("%d %d\n",ans[i].first,ans[i].second);
    }
}