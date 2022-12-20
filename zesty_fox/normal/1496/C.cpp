#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>

#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdl read<ll>
#define fi first
#define sec second
#define pb push_back
#define mp make_pair

const int N=100010;
int T,n,r[N],m[N],cntr,cntm;
#define abs(x) ((x)>=0?(x):(-(x)))

bool cmp(int x,int y){return abs(x)<abs(y);}
int main(){
    T=rdi();
    while(T--){
        n=rdi();cntr=cntm=0;
        for(int i=1;i<=(n<<1);i++){
            int x=rdi(),y=rdi();
            if(!x) r[++cntr]=y;
            else m[++cntm]=x;
        }
        sort(r+1,r+n+1,cmp);sort(m+1,m+n+1,cmp);
        double ans=0;
        for(int i=1;i<=n;i++){
            ans+=sqrt((ll)abs(r[i])*abs(r[i])+(ll)abs(m[i])*abs(m[i]));
        }
        printf("%.10lf\n",ans);
    }
    return 0;
}