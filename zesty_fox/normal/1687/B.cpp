#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=510;

int n,m;
pii e[N];

int query(const string &a){
    cout<<"? "<<a<<endl;
    int ret;cin>>ret;
    return ret;
}

void answer(int x) {cout<<"! "<<x<<endl;}

int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++) e[i]={query(string(i-1,'0')+'1'+string(m-i,'0')),i};
    sort(e+1,e+m+1);
    string sel=string(m,'0');int sum=0;
    for(int i=1;i<=m;i++){
        sel[e[i].se-1]='1';
        if(query(sel)!=sum+e[i].fi) sel[e[i].se-1]='0';
        else sum+=e[i].fi;
    }
    answer(sum);
    return 0;
}