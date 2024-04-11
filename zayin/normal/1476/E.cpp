#include<bits/stdc++.h>
#define maxn 100050
using namespace std;

int n,m,k;
map<string,int> patternid;
string pattern[maxn];

int deg[maxn];
vector<int> G[maxn];

void join(int i,int j)  {
    if (j==i||!j) return ;
    ++deg[j],G[i].push_back(j);
}

int main()  {
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;++i)
        cin>>pattern[i],patternid[pattern[i]]=i;
    for (int i=1,j;i<=m;++i)  {
        string text;
        cin>>text>>j;
        for (int l=0;l<k;++l)
            if (pattern[j][l]!=text[l]&&pattern[j][l]!='_')
                return puts("NO"),0;
        for (int s=0;s<(1<<k);++s)  {
            string t=text;
            for (int i=0;i<k;++i)
                if (s>>i&1)
                    t[i]='_';
            join(j,patternid[t]);
        }
    }

    vector<int> seq;
    queue<int> q;

    for (int i=1;i<=n;++i)
        if (!deg[i])
            q.push(i);
    
    while (q.size())    {
        int i=q.front(); q.pop();
        seq.push_back(i);
        for (int j:G[i])    {
            if (!--deg[j])
                q.push(j);
        }
    }
    if (seq.size()!=n)
        puts("NO");
    else    {
        puts("YES");
        for (int i:seq) cout<<i<<" "; cout<<endl;
    }
    return 0;
}