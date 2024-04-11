#include <bits/stdc++.h>
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
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=300010,INF=INT_MAX;

int n,w,c[N][3],sel[N];
ll ans;

priority_queue<pii,vector<pii>,greater<pii>> q1, q2, q3;
//                                           0:2 0:1 1:2
priority_queue<pii> q4, q5;
//                  1:0 2:1

void pop_illegal(){
    while(!q1.empty()&&sel[q1.top().se]!=0) q1.pop();
    while(!q2.empty()&&sel[q2.top().se]!=0) q2.pop();
    while(!q3.empty()&&sel[q3.top().se]!=1) q3.pop();
    while(!q4.empty()&&sel[q4.top().se]!=1) q4.pop();
    while(!q5.empty()&&sel[q5.top().se]!=2) q5.pop();
}

struct Oper{int typ,i,j;};

pair<ll,Oper> query(int op){
    if(op==1){
        if(q1.empty()||q4.empty()) return mp(INF,Oper());
        return mp(q1.top().fi-q4.top().fi,(Oper){op,q1.top().se,q4.top().se});
    }
    else if(op==2){
        if(q1.empty()||q5.empty()) return mp(INF,Oper());
        return mp(q1.top().fi-q5.top().fi,(Oper){op,q1.top().se,q5.top().se});
    }
    else if(op==3){
        if(q2.empty()) return mp(INF,Oper());
        return mp(q2.top().fi,(Oper){op,q2.top().se,0});
    }
    else{
        if(q3.empty()) return mp(INF,Oper());
        return mp(q3.top().fi,(Oper){op,q3.top().se,0});
    }
}

void modify(Oper op){
    int i=op.i,j=op.j;
    if(op.typ==1){
        sel[i]+=2,sel[j]-=1;
        q5.push(mp(c[i][2]-c[i][1],i));
        q1.push(mp(c[j][2],j));
        q2.push(mp(c[j][1],j));
    }
    else if(op.typ==2){
        sel[i]+=2,sel[j]-=1;
        q5.push(mp(c[i][2]-c[i][1],i));
        q3.push(mp(c[j][2]-c[j][1],j));
        q4.push(mp(c[j][1],j));
    }
    else if(op.typ==3){
        sel[i]++;
        q3.push(mp(c[i][2]-c[i][1],i));
        q4.push(mp(c[i][1],i));
    }
    else{
        sel[i]++;
        q5.push(mp(c[i][2]-c[i][1],i));
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),w=rdi();
    for(int i=1;i<=n;i++){
        c[i][1]=rdi(),c[i][2]=rdi();
        q1.push(mp(c[i][2],i)),q2.push(mp(c[i][1],i));
    }
    while(w--){
        pop_illegal();
        Oper op;ll minx=INF;
        for(int i=1;i<=4;i++){
            auto tmp=query(i);
            if(tmp.fi<minx) minx=tmp.fi,op=tmp.se;
        }
        ans+=minx,modify(op);
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<sel[i];
    cout<<endl;
    return 0;
}