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

const int N=1000010,MOD=1e9+7;

int p[N],pcnt,v[N],fact[N];
void init(int lim){
    v[1]=1;
    for(int i=2;i<=lim;i++){
        if(!v[i]) {v[i]=i,p[++pcnt]=i;}
        for(int j=1;j<=pcnt;j++){
            if(p[j]>v[i]||p[j]>lim/i) break;
            v[p[j]*i]=p[j];
        }
    }

    fact[0]=1;
    for(int i=1;i<=lim;i++) fact[i]=(ll)fact[i-1]*i%MOD;
}

void nosol(){
    puts("0");
    exit(0);
}

int n,a[N],mul[N],num[N],cnt1[N],cnt2[N],ma1[N],ma2[N];
vi fac[N];
ll ans=1;

int main(){
    n=rdi();init(n);
    for(int i=1;i<=n;i++) a[i]=rdi();

    fac[1].pb(1),num[1]=1,cnt2[1]++;
    for(int i=2;i<=n;i++){
        int x=i;mul[i]=1;
        while(x>1){
            int tmp=v[x];
            while(x%tmp==0) x/=tmp;
            mul[i]*=tmp,fac[i].pb(tmp);
        }
        cnt1[mul[i]]++;
    }

    for(int i=1;i<=pcnt;i++) num[p[i]]=n/p[i],cnt2[num[p[i]]]++;

    for(int i=1;i<=n;i++){
        if(a[i]){
            if(vi(fac[i].begin(),fac[i].end()-1)!=vi(fac[a[i]].begin(),fac[a[i]].end()-1)) nosol();
            int x=fac[i].back(),y=fac[a[i]].back();
            if(num[x]!=num[y]||((ma1[x]&&ma1[x]!=y)||(ma2[y]&&ma2[y]!=x))) nosol();
            if(!ma1[x]&&!ma2[y]) cnt2[num[x]]--;
            ma1[x]=y,ma2[y]=x,cnt1[mul[a[i]]]--;
        }
    }

    for(int i=1;i<=n;i++) ans=ans*fact[cnt1[i]]%MOD*fact[cnt2[i]]%MOD;
    cout<<ans<<endl;
    return 0;
}