#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;

vector <int> vec[SIZE];
vector <int> test;
vector <int> ans;
int num[SIZE];
int n;

bool ok(int x,int y)
{
    if(abs(x-y)<=2) return true;
    if(abs(x+n-y)<=2) return true;
    if(abs(x-n-y)<=2) return true;
    return false;
}

bool dfs(int bef,int next)
{
    //printf("[pos]%d %d\n",bef,next);
    if(ans.size()==n)
    {
        for(int i=0;i<n;i++)
        {
            ans[i]++;
            if(i!=n-1) printf("%d ",ans[i]);
            else printf("%d\n",ans[i]);
        }
        return true;
    }
    for(int i=0;i<vec[next].size();i++)
    {
        int mch=0;
        int nxt=vec[next][i];
        if(num[nxt]==-1)
        {
            int mini=2*SIZE;
            bool up1=false,up2=false;
            for(int j=0;j<vec[nxt].size();j++)
            {
                if(num[vec[nxt][j]]!=-1&&!ok((int) ans.size(),num[vec[nxt][j]])) break;
                if(vec[nxt][j]==bef) up1=true;
                else if(vec[nxt][j]==next) up2=true;
            }
            if(up1&&up2)
            {
                //printf("%d\n",nxt);
                num[nxt]=ans.size();
                ans.push_back(nxt);
                if(dfs(next,nxt)) return true;
                num[nxt]=-1;
                ans.pop_back();
            }
        }
    }
    return false;
}

int main()
{
    scanf("%d",&n);
    for(int i=0;i<2*n;i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);a--;b--;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(vec[i].size()>4)
        {
            printf("%d\n",-1);
            return 0;
        }
    }
    /*for(int i=0;i<n;i++)
    {
        for(int j=0;j<vec[i].size();j++)
        {
            printf("%d ",vec[i][j]);
        }
        printf("\n");
    }*/
    if(n==5) printf("%d %d %d %d %d\n",1,2,3,4,5);
    else
    {
        for(int i=0;i<vec[0].size();i++)
        {
            int s=vec[0][i];
            int mch=0;
            for(int j=0;j<vec[0].size();j++)
            {
                for(int k=0;k<vec[s].size();k++)
                {
                    if(vec[0][j]==vec[s][k])
                    {
                        mch++;
                    }
                }
            }
            if(mch==2) test.push_back(s);
        }
        for(int i=0;i<test.size();i++)
        {
            memset(num,-1,sizeof(num));
            num[0]=0;num[test[i]]=1;
            int bef=0,next=test[i];
            ans.push_back(bef);
            ans.push_back(next);
            bool res=dfs(bef,next);
            if(res) return 0;
            ans.pop_back();ans.pop_back();
        }
        printf("%d\n",-1);
    }
    return 0;
}