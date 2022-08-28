#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;

vector <P> vec[SIZE];
int back[SIZE],dist[SIZE],ch[SIZE];
queue < queue <int> > que[SIZE];
bool use[SIZE];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++)
    {
        int a,b,c;
        scanf("%d %d %d",&a,&b,&c);
        vec[a].push_back(P(b,c));
        vec[b].push_back(P(a,c));
    }
    memset(back,-1,sizeof(back));
    memset(dist,-1,sizeof(dist));
    queue <int> Q,start;
    Q.push(n-1);
    dist[n-1]=0;
    while(!Q.empty())
    {
        int v=Q.front();Q.pop();
        start.push(v);
        use[v]=true;
        for(int i=0;i<vec[v].size();i++)
        {
            int to=vec[v][i].first;
            if(vec[v][i].second==0&&back[to]==-1)
            {
                back[to]=v;
                dist[to]=dist[v]+1;
                Q.push(to);
            }
        }
    }
    que[0].push(start);
    for(int i=0;i<n;i++)
    {
        while(!que[i].empty())
        {
            queue <int> f=que[i].front();que[i].pop();
            for(int j=0;j<10;j++)
            {
                Q=f;
                queue <int> nxt;
                while(!Q.empty())
                {
                    int v=Q.front();Q.pop();
                    for(int k=0;k<vec[v].size();k++)
                    {
                        int to=vec[v][k].first;
                        if(vec[v][k].second==j&&!use[to])
                        {
                            use[to]=true;
                            back[to]=v;
                            ch[to]=j;
                            nxt.push(to);
                        }
                    }
                }
                if(!nxt.empty()) que[i+1].push(nxt);
            }
        }
    }
    string ret="";
    int now=0,cnt=0;
    while(1)
    {
        cnt++;
        if(now==n-1) break;
        ret+='0'+ch[now];
        now=back[now];
    }
    while(!ret.empty()&&ret[ret.size()-1]=='0')
    {
        ret.resize(ret.size()-1);
    }
    reverse(ret.begin(),ret.end());
    if(!ret.empty()) printf("%s\n",ret.c_str());
    else puts("0");
    printf("%d\n",cnt);
    now=0;
    for(int i=0;i<cnt;i++)
    {
        if(i!=0) printf(" ");
        printf("%d",now);
        now=back[now];
    }puts("");
    return 0;
}