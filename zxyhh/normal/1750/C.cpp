#include<bits/stdc++.h>
#define ll long long
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
int n,m;
#define maxn 200005
char a[maxn];
char b[maxn];
std::vector< std::pair<int,int> > vt;
void solve() {
    n=rd();
    vt.clear();
    ll ans=0;
    scanf("%s",a+1);
    scanf("%s",b+1);
    bool flag1=1,flag2=1;
    for(int i=1;i<=n;i++) {
        if (a[i]!=b[i]) {
            flag1=0;
        }
        else flag2=0;
    }
    if (!flag1&&!flag2) {
        printf("NO\n");
        return ;
    }
    int cnt=0;
    for(int i=1;i<=n;i++) {
        if (a[i]=='1') {
            vt.push_back({i,i});
            cnt++;
        }
    }
    if (cnt%2==(flag1)) {
        vt.push_back({1,1});
        vt.push_back({2,2});
        vt.push_back({1,2});
    }
    printf("YES\n");
    printf("%d\n",vt.size());
    for(auto i:vt) {
        printf("%d %d\n",i.first,i.second);
    }
}
int main() {
    int T=rd();
    for(int i=1;i<=T;i++) {
        solve();
    }
}