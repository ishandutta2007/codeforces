#include<bits/stdc++.h>
#define ll long long 
inline ll rd() {
    ll _x=0;int _ch=getchar(),_f=1;
    for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
    if (_ch=='-'){_f=-1;_ch=getchar();}
    for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
    return _f*_x;
}
#define maxn 100005
int n,k;
char s[205];
int cnt[27];
char ans[205];
void solve() {
    n=rd(),k=rd();
    scanf("%s",s+1);
    memset(cnt,0,sizeof cnt);
    for(int i=1;i<=n;i++) {
        cnt[s[i]-'a']++;
    }
    for(int i=1;i<=k;i++) {
        for(int j=0;j<=25&&j<=n/k;j++) {
            if (!cnt[j]||j==n/k) {
                ans[i]='a'+j;
                break;
            }
            else {
                cnt[j]--;
            }
        }
        
    }
    for(int i=1;i<=k;i++) {
        printf("%c",ans[i]);
    }
    putchar('\n');
}
int main() {
    int T=rd();
    while(T--) {
        solve();
    }
}