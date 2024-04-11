#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <functional>
#include <queue>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;
typedef pair <P,P> PP;

P st[SIZE];
vector <PP> vec;
int ans[SIZE];
int n,m,cap;
priority_queue <P,vector <P>,greater <P> > que;

bool ok(int x)
{
    while(!que.empty()) que.pop();
    int zan=cap,now=0,pos=-1;
    for(int i=0;i<vec.size();i++)
    {
        PP p=vec[i];
        if(p.first.second==1)
        {
            que.push(p.second);
        }
        else
        {
            int id=p.second.first;
            if(now==0)
            {
                if(que.empty()) return false;
                P q=que.top();que.pop();
                zan-=q.first;
                if(zan<0) return false;
                now=x;
                pos=q.second;
            }
            now--;
            ans[id]=pos;
        }
    }
    return true;
}
int main()
{
    scanf("%d %d %d",&n,&m,&cap);
    for(int i=0;i<m;i++)
    {
        int a;
        scanf("%d",&a);
        vec.push_back(PP(P(a,0),P(i,0)));
    }
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        st[i].first=a;
    }
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        st[i].second=a;
    }
    for(int i=0;i<n;i++) vec.push_back(PP(P(st[i].first,1),P(st[i].second,i)));
    sort(vec.begin(),vec.end(),greater <PP>());//
    //for(int i=0;i<vec.size();i++) printf("%d %d %d %d\n",vec[i].first.first,vec[i].first.second,vec[i].second.first,vec[i].second.second);
    int s=0,e=m+2;
    while(e-s>1)
    {
        int med=(s+e)/2;
        if(ok(med)) e=med;
        else s=med;
    }
    ok(e);
    if(e>m) puts("NO");
    else
    {
        puts("YES");
        for(int i=0;i<m;i++)
        {
            if(i!=0) printf(" ");
            printf("%d",ans[i]+1);
        }puts("");
    }
    return 0;
}