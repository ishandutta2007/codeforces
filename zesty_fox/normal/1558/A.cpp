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

int a,b;
set<int> s;
void solve(){
    a=rdi(),b=rdi();s.clear();
    int A=(a+b+1)/2,B=(a+b)/2;
    for(int a1=0,b1=a1-b+B;a1+b1<=a+b&&a1<=A&&b1<=B;a1++,b1++){
        if(a1<0||b1<0) continue;
        s.insert(a1+b1);
    }
    for(int a1=0,b1=a1-b+A;a1+b1<=a+b&&a1<=B&&b1<=A;a1++,b1++){
        if(a1<0||b1<0) continue;
        s.insert(a1+b1);
    }
    printf("%lu\n",s.size());
    for(auto x:s) printf("%d ",x);
    puts("");
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}