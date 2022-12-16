#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

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
#define pb push_back
#define mp make_pair

const int N=1000010;
int n,m,q,a[N];
char s[N];

int up[N],le[N],mup[N],mle[N];

int id(int x,int y){
    return (x-1)*m+y;
}

int lg2[N],f1[N][21];

void init(){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            up[id(i,j)]=i,le[id(i,j)]=j;
                if(i!=1&&a[id(i-1,j)]==0){
                    up[id(i,j)]=min(up[id(i,j)],up[id(i-1,j)]);
                    le[id(i,j)]=min(le[id(i,j)],le[id(i-1,j)]);
                }
                if(j!=1&&a[id(i,j-1)]==0){
                    up[id(i,j)]=min(up[id(i,j)],up[id(i,j-1)]);
                    le[id(i,j)]=min(le[id(i,j)],le[id(i,j-1)]);
                }
                if(up[id(i,j)]>1) mle[j]=max(mle[j],le[id(i,j)]);
        }
    }
    for(int i=2;i<=m;i++) lg2[i]=lg2[i>>1]+1;
    for(int i=1;i<=m;i++) f1[i][0]=mle[i];
    for(int j=1;j<=lg2[m];j++){
        for(int i=1;i<=m-(1<<j)+1;i++){
            f1[i][j]=max(f1[i][j-1],f1[i+(1<<(j-1))][j-1]);
        }
    }
}

int query1(int l,int r){
    int k=lg2[r-l+1];
    return max(f1[l][k],f1[r-(1<<k)+1][k]);
}

int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++){
        scanf("%s",s+1);
        for(int j=1;j<=m;j++) a[id(i,j)]=(s[j]=='X');
    }init();
    q=rdi();
    while(q--){
        int l=rdi(),r=rdi();
        puts(query1(l,r)<=l?"YES":"NO");
    }
    return 0;
}