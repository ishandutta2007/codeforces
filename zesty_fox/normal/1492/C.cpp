#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=200010;

int n,m,ans;
char s[N],t[N];

int pre[N],suf[N];
vi pos[N];

int main(){
    n=rdi(),m=rdi();
    scanf("%s%s",s+1,t+1);

    for(int i=1;i<=n;i++) pos[s[i]-'a'+1].pb(i);

    {
    int pos=m;
    for(int i=n;i>=1;i--){
        if(pos&&t[pos]==s[i]) pos--;
        suf[i]=pos+1;
    }

    pos=1;
    for(int i=1;i<=n;i++){
        if(pos<=m&&t[pos]==s[i]) pos++;
        pre[i]=pos-1;
    }
    }

    for(int i=1;i<m;i++){
        int now=t[i]-'a'+1,nxt=t[i+1]-'a'+1,pos1,pos2;

        int l=0,r=pos[now].size()-1;
        while(l<r){
            int mid=(l+r)>>1;
            if(pre[pos[now][mid]]>=i) r=mid;
            else l=mid+1;
        }
        pos1=pos[now][l];

            
        l=0,r=pos[nxt].size()-1;
        while(l<r){
            int mid=(l+r+1)>>1;
            if(suf[pos[nxt][mid]]<=i+1) l=mid;
            else r=mid-1;
        }
        pos2=pos[nxt][l];
    
        ans=max(ans,abs(pos2-pos1));
    }
    printf("%d\n",ans);
    return 0;
}