#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using u64=unsigned long long;
using db=double;
using pii=pair<int,int>;
using vi=vector<int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch-'0'),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back

int query(int i,int j){
    cout<<"? "<<i<<' '<<j<<endl;
    return rdi();
}

bool answer(int x,int y){
    cout<<"! "<<x<<' '<<y<<endl;
    return rdi()==1;
}

const int N=2e4+10;

int n;
void solve(){
    n=rdi();
    int j=1,k=2;
    for(int i=3;i<=n;i++){
        int x=query(i,j),y=query(i,k);
        if(x<y) j=i;
        else if(x>y) k=i;
    }
    answer(j,k);
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}