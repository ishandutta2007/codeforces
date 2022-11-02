#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+10;
char s[maxn],t[maxn];
bool f[20][20];
int _,n,pre[20];
int ffind(int x){
    if (pre[x]==x) return x;
    return pre[x]=ffind(pre[x]);
}
int main(){
    cin >> _;
    while (_--){
        scanf("%d%s%s",&n,s,t);
        memset(f,0,sizeof(f));
        bool flag=0;
        for (int i=0;i<20;i++) pre[i]=i;
        int ans=0;
        for (int i=0;i<n;i++){
            flag|=s[i]>t[i];
            if (s[i]<t[i]){
                int x=ffind(s[i]-'a');
                int y=ffind(t[i]-'a');
                if (x!=y) ++ans,pre[y]=x;
            }
        }
        if (!flag) printf("%d\n",ans); else puts("-1");
    }
}