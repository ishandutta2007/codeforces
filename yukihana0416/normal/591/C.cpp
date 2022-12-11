#pragma comment(linker,"/STACK:102400000,102400000")
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cmath>
#include <climits>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <bitset>
#include <vector>
#include <cassert>
using namespace std;

#define LL long long
typedef unsigned LL LLU;
typedef unsigned uint;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;

inline LL read()
{
    LL x=0,f=1; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-')f=-f; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    return x*f;
}

#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define MK(a,b) make_pair(a,b)
#define lowbit(x) ((x)&-(x))

const double pi=(double) acos(-1.0);
const double eps=(double) 1e-8;
const int INF=(int) 0x3f3f3f3f;
const LL  LNF=(LLU)(-1) >> 2;
const int SINF=(uint) ~0U>>1;
const double DINF=(double) 1e50;
const int MOD=(int) 1e9+7;
const int maxm=(int) 1e5+20;
const int maxn=(int) 5e5+20;

int n;
int num[maxn];
int mx;

void work(int x,int y)
{
    if(x+1==y) return ;
    if(num[x]==num[y])
    {
        for(int i=x+1;i<y;i++) num[i]=num[x];
    }
    else
    {
        while(x<y)
        {
            num[x]=num[x-1];
            num[y]=num[y+1];
            x++,y--;
        }
    }
}

int main()
{
//    freopen("in.txt","r",stdin);
    mx=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) num[i]=read();
    num[n+1]=num[n];
    num[0]=num[1];
    int f,b;
    for(int i=1;i<n;i++)
    {
        int cnt=0;
        if(num[i]!=num[i+1])
        {
            f=i;
            while(num[i]!=num[i+1])
            {
                i++;
            }
            b=i;
            int cnt=b-f+1;
            if(cnt&1) cnt/=2;
            else cnt=cnt/2-1;
            mx=max(mx,cnt);
            work(f,b);
//            cout <<f <<" " <<b <<" " <<cnt <<endl;
        }
    }
    cout <<mx <<endl;
    for(int i=1;i<=n;i++) printf("%d ",num[i]);
    puts("");
    return 0;
}