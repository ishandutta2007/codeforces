#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int N=410;
char s1[N],s2[N];
int T,len1,len2;
int gcd(int x,int y){
    return x==0?y:gcd(y%x,x);
}

inline int lcm(int x,int y){
    return x/gcd(x,y)*y;
}

int main(){
    T=rdi();
    while(T--){
        scanf("%s%s",s1,s2);
        len1=strlen(s1),len2=strlen(s2);
        int len=lcm(len1,len2),flg=1;
        for(int i=0;i<len;i++){
            if(s1[i%len1]!=s2[i%len2]) {flg=0;break;}
        }
        if(flg){
            for(int i=0;i<len;i++) putchar(s1[i%len1]);
            puts("");
        }
        else puts("-1");
    }
    return 0;
}