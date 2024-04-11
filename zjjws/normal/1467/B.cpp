#include <cstdio>
#define LL long long

const int maxn = 3e5 + 5;

template<typename T>
inline T min(const T &a,const T &b){
	return a<b?a:b;
}

int n,a[maxn];bool is[maxn];

inline LL rin()
{
    LL s=0;
    bool bj=false;
    char c=getchar();
    for(;(c>'9'||c<'0')&&c!='-';c=getchar());
    if(c=='-')bj=true,c=getchar();
    for(;c>='0'&&c<='9';c=getchar())s=(s<<1)+(s<<3)+(c^'0');
    if(bj)s=-s;
    return s;
}
int calc(int i){
	if(i<=1||i>=n) return 0;
	if(a[i]>a[i-1]&&a[i]>a[i+1]) return 1;
	if(a[i]<a[i-1]&&a[i]<a[i+1]) return 1;
	return 0;
}

inline void work()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    int sum = 0;
    for(int i=2;i<=n-1;i++)sum+=calc(i);
    if(sum==0)
    {
        printf("0\n");
        return;
    }
    int answer = sum;
    for(int i=1;i<=n;i++)
    {
        int now = sum;int old = a[i];
        now-=calc(i-1)+calc(i)+calc(i+1);
        a[i]=a[i-1];
        now+=calc(i-1)+calc(i)+calc(i+1);
        answer = min(answer,now);
        now=sum;a[i]=old;
        now-=calc(i-1)+calc(i)+calc(i+1);
        a[i]=a[i+1];
        now+=calc(i-1)+calc(i)+calc(i+1);
        answer = min(answer,now);
        a[i]=old;
    }
    printf("%d\n",answer);
    return;
}

int main(){
    for(int T=rin();T;T--)work();
	return 0;
}