#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 320

using namespace std;
typedef pair <int,int> P;

int object[30]={4,7,44,47,74,77,444,447,474,477,744,747,774,777,4444,4447,4474,4477,4744,4747,4774,4777,7444,7447,7474,7477,7744,7747,7774,7777};
struct backet
{
    int back[100005];
    int cnt[SIZE][10005];
    int add[SIZE];
    bool ok[10005];
    int n;
    
    void in(int k,int x)
    {
        back[k]=x;
    }
    void make()
    {
        memset(add,0,sizeof(add));
        memset(cnt,0,sizeof(cnt));
        memset(ok,false,sizeof(ok));
        for(int i=0;i<n;i++) cnt[i/SIZE][back[i]]++;
        for(int i=0;i<30;i++) ok[object[i]]=true;
    }
    void updata(int a,int b,int v)
    {
        int s=a/SIZE,e=b/SIZE;
        while(a<b&&a%SIZE!=0)
        {
            cnt[s][back[a]]--;
            back[a]+=v;
            cnt[s][back[a]]++;
            a++;
        }
        while(a<b&&b%SIZE!=0)
        {
            b--;
            cnt[e][back[b]]--;
            back[b]+=v;
            cnt[e][back[b]]++;
        }s=a/SIZE,e=b/SIZE;
        for(int i=s;i<e;i++) add[i]+=v;
    }
    int search(int a,int b)
    {
        int ret=0;
        int s=a/SIZE,e=b/SIZE;
        while(a<b&&a%SIZE!=0)
        {
            if(ok[back[a]+add[s]]) ret++;
            a++;
        }
        while(a<b&&b%SIZE!=0)
        {
            b--;
            if(ok[back[b]+add[e]]) ret++;
        }s=a/SIZE,e=b/SIZE;
        for(int i=s;i<e;i++)
        {
            for(int j=0;j<30;j++)
            {
                if(object[j]>=add[i]) ret+=cnt[i][object[j]-add[i]];
            }
        }
        return ret;
    }
};
backet back;
char str[10];

int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    back.n=n;
    for(int i=0;i<n;i++)
    {
        int a;
        scanf("%d",&a);
        back.in(i,a);
    }
    back.make();
    for(int i=0;i<m;i++)
    {
        scanf("%s",&str);
        if(str[0]=='a')
        {
            int l,r,d;
            scanf("%d %d %d",&l,&r,&d);l--;r--;
            back.updata(l,r+1,d);
        }
        else
        {
            int l,r;
            scanf("%d %d",&l,&r);l--;r--;
            printf("%d\n",back.search(l,r+1));
        }
    }
    return 0;
}