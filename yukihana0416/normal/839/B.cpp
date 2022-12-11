#include <bits/stdc++.h>
using namespace std;

#define LL __int64

#define fi first
#define se second
#define lson l,mid,id<<1
#define rson mid+1,r,id<<1|1
#define ls id<<1
#define rs id<<1|1
#define MID(a,b) (((a)+(b))>>1)
#define maxx(a,b) ((a)<(b)?(b):(a))
#define minx(a,b) ((a)<(b)?(a):(b))
#define absx(a) ((a)<0?-(a):(a))
#define mk(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define itr iterator
#define lowbit(x) ((x)&-(x))

typedef unsigned LL ULL;
typedef unsigned uint;
typedef map<int,int> mii;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<LL,LL> pLL;

template< typename T > inline void read(T &x) {
    x=0; bool f=0; char ch=getchar();
    while(ch<'0' || ch>'9') {if(ch=='-') f=1; ch=getchar();}
    while(ch>='0' && ch<='9') {x=x*10+ch-'0'; ch=getchar();}
    if(f) x=-x;
}

template< typename T > inline void Max(T &a, T b) {if(a<b) a=b;}
template< typename T > inline void Min(T &a, T b) {if(b<a) a=b;}
template< typename T > inline T Abs(T a) {if(a<0) return -a; else return a;}

const double pi=(double) acos(-1.0);
const int MOD=(int) 1e9+7;
const int INF=(int) 0x3f3f3f3f;
const LL  LINF=(LL) INF<<32|INF;
const int SINF=(uint) ~0>>1;
const LL  SLINF=(ULL) (-1)>>1;
const double DINF=(double) 1e50;
const double eps=(double) 1e-8;
const int maxn=(int) 2e5+20;
const int maxm=(int) 1e6+20;
const int maxk=(int) 5e2+20;

inline int sig(double x) {return x<-eps?-1:x>eps;}

//--------------start------------------

int n;
priority_queue<int> pq;
int f,t,s;


void work()
{
    read(f); t=f*2; s=0;
    read(n);
    while(n--)
    {
        int x; read(x);
        pq.push(x);
    }

    while(!pq.empty())
    {
        int x=pq.top(); pq.pop();
//        cout <<"num : " <<x <<endl;
//        cout <<f <<" " <<t <<" " <<s <<endl;
        if(f)
        {
            f--;
            if(x>=3)
            {
                x-=min(x,4);
                if(x) pq.push(x);
            }
            else if(x==2)
            {
                if(t) t--, f++;
                else s++;
            }
            else if(x==1)
            {
                if(s) s--, f++;
                else t++;
            }
        }
        else if(t)
        {
            t--;
            x-=min(x,2);
            if(x) pq.push(x);
        }
        else if(s)
        {
            s--;
            x-=min(x,1);
            if(x) pq.push(x);
        }
        else
        {
            puts("NO");
            return ;
        }
//        cout <<f <<" " <<t <<" " <<s <<endl;
    }
    puts("YES");
}

//--------------end--------------------

int main()
{
#ifdef yukihana0416
freopen("in.txt","r",stdin);
//freopen("out.txt","w",stdout);
#endif // yukihana0416
    work();
    return 0;
}