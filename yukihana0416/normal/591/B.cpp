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
const int maxn=(int) 2e5+20;

int n,m;

char s[maxn];

int pos[26];
int temp[26];

int main()
{
//    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    scanf("%s",s);
//    cout <<s <<endl;
    for(int i=0;i<26;i++) pos[i]=i;
    for(int p=0;p<m;p++)
    {
        char A[5],B[5];
        scanf("%s%s",A,B);
        int a=A[0]-'a', b=B[0]-'a';
//        cout <<a <<" " <<b <<endl;
        for(int i=0;i<26;i++)
        {
            if(pos[i]==a) temp[i]=b;
            else if(pos[i]==b) temp[i]=a;
            else temp[i]=pos[i];
        }
        for(int i=0;i<26;i++) pos[i]=temp[i];
//        for(int i=0;i<26;i++) cout <<pos[i] <<" ";cout <<endl;
    }
    for(int i=0;i<n;i++)
    {
        int idx=s[i]-'a';
        putchar(pos[idx]+'a');
    }
    puts("");
    return 0;
}