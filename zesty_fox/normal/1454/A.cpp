#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int read(){
    int f=1,x=0;char ch=getchar();
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

int T,n;
int main(){
    T=read();
    while(T--){
        n=read();
        if(n&1){
            for(int i=1;i<=n-3;i++) printf("%d ",(i&1?i+1:i-1));
            printf("%d %d %d\n",n-1,n,n-2);
        }
        else{
            for(int i=1;i<=n;i++) printf("%d ",(i&1?i+1:i-1));
            puts("");
        }
    }
    return 0;
}