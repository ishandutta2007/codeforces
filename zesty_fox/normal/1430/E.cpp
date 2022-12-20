#include <iostream>
#include <cstdio>
#include <cstring>
#include <deque>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=200010;
int n,p[N];
deque<int> cnt[128];
char s[N];
ll ans;

#define lowbit(x) ((x)&(-(x)))
int c[N<<1];
void add(int x,int val){
    for(;x<=n;x+=lowbit(x)) c[x]+=val;
}

int query(int x){
    int res=0;
    for(;x>0;x-=lowbit(x)) res+=c[x];
    return res;
}

int main(){
    scanf("%d%s",&n,s+1);
    for(int i=1;i<=n;i++){
        p[i]=i;
        cnt[s[i]].push_back(i);
    }
    for(int i=1;i<=n/2;i++) swap(s[i],s[n-i+1]);
    for(int i=n;i>=1;i--){
        int x=cnt[s[i]].back();cnt[s[i]].pop_back();
        ans+=query(x-1);add(x,1);
    }
    cout<<ans<<endl;
    return 0;
}