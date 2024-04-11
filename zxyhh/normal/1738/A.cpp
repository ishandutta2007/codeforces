#include<bits/stdc++.h>
#define ll long long 
ll rd() {
    ll x=0,f=1;
    char ch=getchar();
    for(;ch!=EOF&&ch!='-'&&!(ch>='0'&&ch<='9');ch=getchar());
    if (ch=='-') ch=getchar(),f=-1;
    for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
    return x*f;
}
int n;
int a[100005];
int b[100005];
std::vector<int> A,B;
int main() {
    int T=rd();
    while(T--) {
        n=rd();
        A.clear(),B.clear();
        for(int i=1;i<=n;i++) {
            a[i]=rd();
        }
        for(int i=1;i<=n;i++) {
            b[i]=rd();
            if (a[i]==0) A.push_back(b[i]);
            else B.push_back(b[i]);
        }
        std::sort(A.begin(),A.end());
        std::sort(B.begin(),B.end());
        if (A.size()<B.size()) std::swap(A,B);
        ll sum=0;
        if (!B.size()) {
            for(auto i:A) {
                sum+=i;
            }
            printf("%lld\n",sum);
            continue;
        }
        for(int i=0;i<A.size()-B.size();i++) {
            sum+=A[i];
        }
        for(int i=A.size()-B.size(),j=0;i<A.size();i++,j++) {
            sum+=2ll*A[i]+2ll*B[j];
        }
        printf("%lld\n",sum-(A.size()==B.size())*std::min(A[0],B[0]));
    }
}