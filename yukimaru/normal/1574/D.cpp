#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    vector<vector<int>> a(n);
    for(int i=0;i<n;i++)
    {
        int c;
        scanf("%d",&c);
        a[i].resize(c);
        for(int j=0;j<c;j++)
            scanf("%d",&a[i][j]);
    }
    int m;
    scanf("%d",&m);
    set<vector<int>> ban;
    for(int i=0;i<m;i++)
    {
        vector<int> tmp(n);
        for(int j=0;j<n;j++)
            scanf("%d",&tmp[j]),tmp[j]--;
        ban.insert(tmp);
    }
    priority_queue<pair<int,vector<int>>> pq;
    set<vector<int>> inq;
    {
        int res=0;
        vector<int> way(n);
        for(int i=0;i<n;i++)
            res+=a[i].back(),way[i]=(int)a[i].size()-1;
        pq.push(make_pair(res,way));
        inq.insert(way);
    }
    while(!pq.empty())
    {
        int res=pq.top().first;
        vector<int> way=pq.top().second;
        pq.pop();
        if(ban.find(way)==ban.end())
        {
            for(int i=0;i<n;i++)
                printf("%d%c",way[i]+1," \n"[i==n-1]);
            return 0;
        }
        for(int i=0;i<n;i++)
        {
            if(way[i]==0)continue;
            vector<int> tmp=way; tmp[i]--;
            int now=res-a[i][way[i]]+a[i][tmp[i]];
            if(inq.insert(tmp).second)pq.push({now,tmp});
        }
    }
    return 0;
}