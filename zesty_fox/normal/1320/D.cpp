#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int INF=0x3f3f3f3f,N=200010,MOD=332119187,P=197,val[2]={97,131};
#define rdi read<int>
#define rdl read<ll>
#define mp make_pair
#define pb push_back
#define fi first
#define sec second

int n,q,even[N],pos,L[N],R[N];
char s[N];
ll ha[N],ha1[N],ppow[N];
void pre(){
    ppow[0]=1;
    for(int i=1;i<=pos;i++){
        ha[i]=(ha[i-1]*P+val[even[i]])%MOD;
        ha1[i]=(ha1[i-1]*P+val[!even[i]])%MOD;
        ppow[i]=ppow[i-1]*P%MOD;
    }   
    ha[pos+1]=ha[pos],ha1[pos+1]=ha1[pos],ppow[pos+1]=ppow[pos]*P%MOD;
}

inline ll substr(int l,int r){
    int l1=L[l],r1=R[r];
    if(l&1) return (ha1[r1]-ha1[l1-1]*ppow[r1-l1+1]%MOD+MOD)%MOD;
    else return (ha[r1]-ha[l1-1]*ppow[r1-l1+1]%MOD+MOD)%MOD;
}

int main(){
    n=rdi();scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        if(s[i]=='0') even[++pos]=(i&1),R[i]=R[i-1]+1;
        else R[i]=R[i-1];
    }
    L[n+1]=pos+1;
    for(int i=n;i>=1;i--){
        if(s[i]=='0') L[i]=L[i+1]-1;
        else L[i]=L[i+1];
    }
    pre();
    q=rdi();
    while(q--){
        int l1=rdi(),l2=rdi(),len=rdi();
        if(substr(l1,l1+len-1)==substr(l2,l2+len-1)) puts("Yes");
        else puts("No");
    }
    return 0;
}