#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

typedef __int64 LL;

inline LL read()
{
    LL x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

#define maxx(a,b) ((a)<(b)?(b):(a))
#define MID(a,b) (((a)+(b))>>1)
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define MK(a,b) make_pair(a,b)

const int maxn=(int) 1000+20;
const int maxm=(int) 1e5+20;
const int INF=200000000;
const int mod=(int) 1e9+7;

vector< pair<int,int> > vec[maxn];
int n;

int main()
{
//    freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        for(int i=0;i<=1000;i++) vec[i].clear();
        for(int i=0;i<n;i++)
        {
            int x=read()/1000, y=read();
            vec[x].push_back(MK(y,i));
        }
        for(int i=0;i<=1000;i++)
        {
            sort(vec[i].begin(),vec[i].end());
            if(i%2) reverse(vec[i].begin(),vec[i].end());
        }
        for(int i=0;i<=1000;i++)
        {
            int k=vec[i].size();
            for(int j=0;j<k;j++)
                printf("%d ",vec[i][j].second+1);
        }
        puts("");
    }
    return 0;
}