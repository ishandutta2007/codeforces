#include <stdio.h>
#include <locale>
template <typename T> inline void read(T &x){
    char c;
    while(!isdigit(c=getchar()));
    x=c-48;
    while(isdigit(c=getchar()))
    x=x*10+c-48;
}

#include <algorithm>
#include <queue>
using namespace std;
int n, qs;
struct query{
    long long t, k, d;
    int pos;
} q[100001];
bool cmp(query a, query b){
    return a.t<b.t;
}
struct cmph{
    bool operator () (int a, int b){
        return a>b;
    }
};
priority_queue <int, vector<int>, cmph> server;
long long t[101];
long long anss[100001];
long long ans[100001];
bool inheap[101];
int main(){
//    freopen("C.INP", "r", stdin);
    read(n);
    read(qs);
    for(int i=1; i<=qs; i++){
        read(q[i].t);
        read(q[i].k);
        read(q[i].d);
        q[i].pos=i;
    }
    sort(q+1, q+qs+1, cmp);
    for(int i=1; i<=qs; i++){
        for(int j=1; j<=n; j++){
            if(t[j]<q[i].t&&!inheap[j]){
                server.push(j);
                inheap[j]=1;
            }
        }
        if(server.size()<q[i].k)
            ans[i]=-1;
        else{
            for(int j=1; j<=q[i].k; j++){
                ans[i]+=server.top();
                inheap[server.top()]=0;
                t[server.top()]=q[i].t+q[i].d-1;
                server.pop();
            }
        }
    }
    for(int i=1; i<=qs; i++){
        anss[q[i].pos]=ans[i];
    }
    for(int i=1; i<=qs; i++)
        printf("%I64d\n", anss[i]);
}