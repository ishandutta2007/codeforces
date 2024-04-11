#include<bits/stdc++.h>
using namespace std;
#define N 300005
typedef pair<int,int> pi;
map <pi ,int> f;
long long ans;
int n,a[N],q,s[N];
inline void add(int x) {
    if (x==0) return;
    if (s[x]<a[x]) ans--;
    s[x]++;
}
inline void del(int x) {
    if (x==0) return;
    s[x]--;
    if (s[x]<a[x]) ans++;
}
int main() {
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {
    	scanf("%d",&a[i]);
    	ans+=a[i];
    }
    scanf("%d",&q);
    while (q--) {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        if (f.find((pi){x,y})!=f.end()) 
        del(f[(pi){x,y}]);
        f[(pi){x,y}]=z; 
        add(z);
        printf("%lld\n",ans);
    }
}