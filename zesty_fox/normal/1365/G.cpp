#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1010;

int n,id[N];
i64 sum[13];

void init(){
    for(int i=0,c=0;c<n;i++)
        if(__builtin_popcount(i)==6) id[++c]=i;
}

void solve(){
    for(int i=0;i<13;i++){
        vi pos;
        for(int j=1;j<=n;j++)
            if(id[j]>>i&1) pos.pb(j);

        if(pos.size()){
            cout<<"? "<<pos.size()<<' ';
            for(auto x:pos) cout<<x<<' ';
            cout<<endl;sum[i]=rdi64();
        }
    }

    cout<<"! ";
    for(int i=1;i<=n;i++){
        i64 s=0;
        for(int j=0;j<13;j++)
            if(!(id[i]>>j&1)) s|=sum[j];
        cout<<s<<' ';
    }
    cout<<endl;
}

int main(){
    n=rdi();
    init();solve();
    return 0;
}