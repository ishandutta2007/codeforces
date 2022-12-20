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
#define rdl read<ll>
#define fi first
#define sec second
#define pb push_back
#define mp make_pair

const int N=1010;
double e[N][N],p[N],E[N];
int n,vis[N];
int main(){
    n=rdi();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) e[i][j]=rdi()/100.0;
    }
    for(int i=1;i<=n;i++){
        E[i]=1,p[i]=1-e[i][n];
    }
    if(n==1){
        puts("0");
        return 0;
    }
    E[n]=0;vis[n]=1;
    for(int i=1;i<=n;i++){
        int x;double minx=1e30;
        for(int j=1;j<=n;j++){
            if(!vis[j]&&E[j]/(1-p[j])<minx) minx=E[j]/(1-p[j]),x=j;
        }
        vis[x]=1;
        if(x==1){   
            printf("%.15lf\n",E[1]/(1-p[1]));
            return 0;
        }
        for(int j=1;j<=n;j++){
            E[j]+=E[x]/(1-p[x])*e[j][x]*p[j];
            p[j]*=(1-e[j][x]);
        }
    }
    return 0;
}