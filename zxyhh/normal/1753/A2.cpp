#include<bits/stdc++.h>
#define ll long long
inline ll rd(){
    ll x=0;int ch=getchar(); bool f=1;
    while (!isdigit(ch)&&(ch!='-')&&(ch!=EOF)) ch=getchar();
    if (ch=='-'){f=0;ch=getchar();}
    while (isdigit(ch)){x=(x<<1)+(x<<3)+ch-'0';ch=getchar();}
    return f?x:-x;
}
void solve() ;
int main() {
    int T;
    T=rd();
    for(int i=1;i<=T;i++) {
        solve();
    }
}
#define maxn 200005
int a[maxn];
void solve() {
    int n=rd(),cnt=0;
    for(int i=1;i<=n;i++) {
        a[i]=rd();
        cnt+=(a[i]!=0);
    }
    if (cnt%2==1) {
        printf("-1\n");
        return ;
    }
    std::vector<std::pair<int,int>> ans;
    for(int i=1,j;i<=n;i=j+1) {
        if (a[i]==0) {
            ans.push_back(std::make_pair(i,i));
            j=i;
            continue;
        }
        for(j=i+1;j<=n;j++) {
            if (a[j]) break;
        }
        if (a[i]==a[j]) {
            if (j==i+1) {
                ans.push_back(std::make_pair(i,j));
            }
            else {
                ans.push_back(std::make_pair(i,j-2));
                ans.push_back(std::make_pair(j-1,j));
            }
        }
        else {
            ans.push_back(std::make_pair(i,j-1));
            ans.push_back(std::make_pair(j,j));
        }
    }
    printf("%d\n",ans.size());
    for(auto i:ans) {
        printf("%d %d\n",i.first,i.second);
    }
}