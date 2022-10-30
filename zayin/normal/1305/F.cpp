#include<bits/stdc++.h>
#define maxn 500050
using namespace std;
typedef long long LL;

int n;
LL a[maxn],ans;

int gcd(int a,int b)    {
    return !b?a:gcd(b,a%b);
}

void calc(LL x) {
    vector<LL> P;
    for (LL i=2;i*i<=x;++i) {
        if (x%i) continue;
        P.push_back(i);
        while (x%i==0) x/=i;
    }
    if (x>1) P.push_back(x);

    for (LL p:P)    {
        LL sum=0;
        for (int i=1;i<=n;++i)  {
            LL t=a[i]%p;
            if (a[i]==t)
                sum+=p-a[i];
            else
                sum+=min(t,p-t);
        }
        ans=min(ans,sum);
    }
}

int main()  {
    scanf("%d",&n);
    for (int i=1;i<=n;++i)
        scanf("%lld",a+i);
    
    srand(time(0));
	uniform_int_distribution<int> u(1,n);
	default_random_engine e(rand());

    for (int i=1;i<=n;++i)
        ans+=a[i]%2;
    for (int t=0;t<30;++t)  {
        int x=u(e);
        if (a[x]>1)
            calc(a[x]-1);
        calc(a[x]);
        calc(a[x]+1);
    }

    printf("%d\n",ans);

    return 0;
}