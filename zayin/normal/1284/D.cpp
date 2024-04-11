#include<bits/stdc++.h>
#define maxn 100050
using namespace std;
typedef long long LL;

LL hs[maxn],val[maxn];

int n;
int sa[maxn],ea[maxn];
int sb[maxn],eb[maxn];

int Rd() {
	static uniform_int_distribution<int> u(0,50);
	static default_random_engine e(rand());
    return u(e);
}

int t[maxn],pos[maxn];
LL L[maxn],R[maxn];

LL tmp[maxn];

void deal(int *A,int *B,LL *C,LL *D)  {
    for (int i=1;i<=n;++i)
        t[i]=A[i],pos[i]=i;
    sort(t+1,t+n+1);
    sort(pos+1,pos+n+1,[&](const int&i,const int&j) {
        return A[i]<A[j];
    });

    for (int i=1;i<=n;++i)
        L[i]=val[pos[i]]^L[i-1];
    for (int i=n;i;--i)
        R[i]=val[pos[i]]^R[i+1];
    for (int i=1;i<=n;++i)  {
        int x=lower_bound(t+1,t+n+1,B[i])-t;
        C[i]=L[x-1];
        int y=upper_bound(t+1,t+n+1,B[i])-t;
        D[i]=R[y];
    }
}

LL la[maxn],ra[maxn];
LL lb[maxn],rb[maxn];

int main()  {
    srand(time(0));
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%d%d%d%d",sa+i,ea+i,sb+i,eb+i),val[i]=Rd();
    
    deal(ea,sa,la,tmp);
    deal(sa,ea,tmp,ra);
    deal(eb,sb,lb,tmp);
    deal(sb,eb,tmp,rb);

    bool flag=1;
    for (int i=1;i<=n;++i)
        flag&=((la[i]^ra[i])==(lb[i]^rb[i]));
    puts(flag?"YES":"NO");
    return 0;
}