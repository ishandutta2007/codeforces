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

const int N=300010;
vector<int> g[N],_g[N];
int n,m,cnt[N],in[N],_in[N],ans;

queue<int> q;
void topo(vector<int>* g,int* in){
    while(!q.empty()) q.pop();
    int sum=n;
    for(int i=1;i<=n;i++){
        if(!in[i]) q.push(i),sum--;
    }
    while(!q.empty()){
        int x=q.front();q.pop();
        if(!q.size()) cnt[x]+=sum;
        else if(q.size()==1){
            int x1=q.front(),flg=1;
            for(auto y1:g[x1]){
                if(in[y1]==1) flg=0;
            }
            cnt[x]+=flg*sum;
        }
        else cnt[x]=-10;
        for(auto y:g[x]){
            in[y]--;
            if(!in[y]) sum--,q.push(y);
        }
    }
}

int main(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi();
        g[x].push_back(y),_g[y].push_back(x);
        in[y]++,_in[x]++;
    }
    topo(g,in);topo(_g,_in);
    for(int i=1;i<=n;i++){
        if(cnt[i]>=n-2) ans++;
    }
    printf("%d\n",ans);
    return 0;
}