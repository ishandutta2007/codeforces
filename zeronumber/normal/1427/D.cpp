#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=111;
const int M=1000000007;
int n,k,a[maxn],c[maxn],pos[maxn],pt[maxn];
char s[maxn];
vector<vi> ans;
int check(){
    for (int i=1;i<=n;i++) pos[a[i]]=i;
    for (int i=1;i<n;i++) if (pos[i]>pos[i+1]) return i;
    return -1;
}
void work(vi &b){
    ans.pb(b);
    int tot=0,m=b.size();
    for (int i=0;i<m;i++) pt[i+1]=pt[i]+b[i];
    for (int i=m-1;i>=0;i--)
        for (int j=pt[i]+1;j<=pt[i+1];j++) c[++tot]=a[j];
    for (int i=1;i<=n;i++) a[i]=c[i];
}
int main(){
    cin >> n;
    for (int i=1;i<=n;i++) cin >> a[i];
    while (check()!=-1){
        int p=check();
        int LL=pos[p+1]-1;
        int RR=n-pos[p];
        int L=1;
        while (p+L<n&&pos[p+L]+1==pos[p+L+1]) ++L;
        int R=pos[p]-pos[p+1]+1-L;
        vi res; res.clear();
        if (LL) res.pb(LL);
        res.pb(L); res.pb(R);
        if (RR) res.pb(RR);
        work(res);
    }
    printf("%d\n",ans.size());
    for (auto b:ans){
        printf("%d",b.size());
        for (auto x:b) printf(" %d",x);puts("");
    }
    return 0;
}