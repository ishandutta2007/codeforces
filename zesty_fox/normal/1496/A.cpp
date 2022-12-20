#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <vector>
#include <set>
#include <queue>
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

int T;
char s[110];
int main(){
    T=rdi();
    while(T--){
        int n=rdi(),k=rdi();
        scanf("%s",s+1);
        bool flg=1;
        for(int i=1;i<=k;i++){
            if(s[i]!=s[n+1-i]) flg=0;
        }
        if(!flg||k*2==n) puts("NO");
        else puts("YES");
    }
    return 0;
}