#include <bits/stdc++.h>
using namespace std;
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
const int N=710;
int n,a[N];
bool ll[N][N],rr[N][N],f[N][N];
int gcd(int x,int y){return !x?y:gcd(y%x,x);}
int main(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),ll[i][i]=rr[i][i]=1;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++) f[i][j]=f[j][i]=(gcd(a[i],a[j])>1);
    }
    for(int len=1;len<=n;len++){
        for(int l=1,r=len;r<=n;l++,r++){
            for(int k=l;k<=r;k++){
                if(ll[l][k]&&rr[k][r]){
                    if(l==1&&r==n) puts("Yes"),exit(0);
                    if(f[l-1][k]) rr[l-1][r]=1;
                    if(f[k][r+1]) ll[l][r+1]=1;
                }
            }
        }
    }
    puts("No");
    return 0;
}