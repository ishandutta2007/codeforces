#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=3e5+3;
const int M=998244353;
int _,n,f;
char s[maxn],t[maxn];
int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d%s%s",&n,s+1,t+1);
        vector <int> ans; ans.clear();
        int l=1,r=n,pos; f=0;
        for (int i=n;i;i--){
            if (!f) pos=l++; else pos=r--;
            if ((t[i]==s[pos])^f) ans.pb(1);
            ans.pb(i);
            f^=1;
        }
        printf("%d ",(int)ans.size());
        for (auto x:ans) printf("%d ",x);puts("");
    }
}