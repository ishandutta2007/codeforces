#include <bits/stdc++.h>
#include <cstdio>
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

const int N=110;
int p[N],n;
int query(const vi &q){
    printf("? ");
    for(auto x:q) printf("%d ",x);
    puts("");fflush(stdout);
    return rdi();
}

void print_ans(){
    printf("! ");
    for(int i=1;i<=n;i++) printf("%d ",p[i]);
    puts("");fflush(stdout);
}

int main(){
    n=rdi();int pos=0;
    for(int i=1;i<n;i++){
        vi tmp;
        for(int j=1;j<=n;j++){
            if(j!=n) tmp.pb(1);
            else tmp.pb(n-i+1);
        }
        if(query(tmp)) {pos=i;p[n]=i;break;}
    }
    if(!pos) pos=n,p[n]=n;
    for(int i=1;i<=n;i++){
        if(i==pos) continue;
        vi tmp;
        for(int j=1;j<=n;j++){
            if(j!=n) tmp.pb(pos);
            else tmp.pb(i);
        }
        p[query(tmp)]=i;
    }

    print_ans();
    return 0;
}