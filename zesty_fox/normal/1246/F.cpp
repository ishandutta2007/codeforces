#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=100010;

int n;
char s[N];

int pre[N],nxt[N];
int prec[N][27],nxtc[N][27];

inline int lg2(int x) {return !x?-1:__lg(x);}

struct ST{
    int st[N][18];
    void init(char *s,int n){
        for(int i=1;i<=n;i++) st[i][0]=(1<<(s[i]-'a'));
        for(int j=1;j<=lg2(n);j++)
            for(int i=1;i<=n-(1<<j)+1;i++)
                st[i][j]=st[i][j-1]|st[i+(1<<(j-1))][j-1];
    }
    inline int query(int l,int r){
        int k=lg2(r-l+1);
        return __builtin_popcount(st[l][k]|st[r-(1<<k)+1][k]);
    }
}st;

void init(){
    st.init(s,n);

    array<int,26> pos;
    pos.fill(0);
    for(int i=1;i<=n;i++) pre[i]=pos[s[i]-'a'],pos[s[i]-'a']=i;
    pos.fill(n+1);
    for(int i=n;i>=1;i--) nxt[i]=pos[s[i]-'a'],pos[s[i]-'a']=i;

    array<int,26> p;
    for(int i=0;i<26;i++) p[i]=i;
    pos.fill(0);
    for(int i=1;i<=n;i++){
        pos[s[i]-'a']=i;
        sort(p.begin(),p.end(),[&](int x,int y){return pos[x]>pos[y];});
        for(int j=0;j<26;j++){
            nxtc[i][j+1]=nxtc[i][j];
            if(pos[p[j]]) nxtc[i][j+1]=max(nxtc[i][j+1],min(nxt[pos[p[j]]],n));
        }
    }

    pos.fill(n+1);
    for(int i=n;i>=1;i--){
        pos[s[i]-'a']=i;
        sort(p.begin(),p.end(),[&](int x,int y){return pos[x]<pos[y];});

        prec[i][0]=n+1;
        for(int j=0;j<26;j++){
            prec[i][j+1]=prec[i][j];
            if(pos[p[j]]) prec[i][j+1]=min(prec[i][j+1],max(pre[pos[p[j]]],1));
        }
    }
}

int L[N],R[N];

int jpl[18][N],jpr[18][N];
ll suml[18][N],sumr[18][N];

void solve(){
    ll ans=0;
    for(int i=1;i<=n;i++) L[i]=R[i]=i,ans+=n-1;
    for(int siz=1;siz<=26;siz++){
        for(int i=1;i<=n;i++){
            jpl[0][i]=prec[i][siz],jpr[0][i]=nxtc[i][siz];
            suml[0][i]=jpl[0][i]-1,sumr[0][i]=n-jpr[0][i];
        }
        for(int j=1;j<=lg2(n);j++){
            for(int i=1;i<=n;i++){
                jpl[j][i]=jpl[j-1][jpl[j-1][i]];
                suml[j][i]=suml[j-1][i]+suml[j-1][jpl[j-1][i]];
                jpr[j][i]=jpr[j-1][jpr[j-1][i]];
                sumr[j][i]=sumr[j-1][i]+sumr[j-1][jpr[j-1][i]];
            }
        }

        for(int i=1;i<=n;i++){
            if(st.query(L[i],R[i])!=siz) continue;
            for(int j=lg2(max(n-R[i],L[i]-1));j>=0;j--){
                int nxtl=jpl[j][L[i]],nxtr=jpr[j][R[i]];
                if(st.query(nxtl,nxtr)>siz) continue;
                ans+=suml[j][L[i]]+sumr[j][R[i]],L[i]=nxtl,R[i]=nxtr;
            }
            L[i]=prec[L[i]][siz],R[i]=nxtc[R[i]][siz];
            ans+=n-1+L[i]-R[i];
        }
    }
    cout<<ans<<endl;
}

int main(){
    scanf("%s",s+1);n=strlen(s+1);
    init();solve();
    return 0;
}