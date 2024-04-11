#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,m;
long long cnt[maxn],c[maxn];
struct cmp{
    int idx;
    bool operator < (const cmp& tmp)const{
        if(c[idx]>c[tmp.idx]) return true;
        else if(c[idx]==c[tmp.idx]) return idx>tmp.idx;
        return false;
    }
};
priority_queue<cmp> q;

int main(){
    cin>>n>>m;
    for(int i=1;i<=n;++i) scanf("%I64d",cnt+i);
    for(int i=1;i<=n;++i) scanf("%I64d",c+i);
    for(int i=1;i<=n;++i) q.push((cmp){i});
    for(int i=1;i<=m;++i){
        int t,d; scanf("%d%d",&t,&d);
        long long val=0;
        if(cnt[t]>=d) cnt[t]-=d,val+=d*c[t],d=0;
        else if(cnt[t]<d) d-=cnt[t],val+=cnt[t]*c[t],cnt[t]=0;
        while(d){
            if(q.empty()) break;
            int new_t;
            do{
                new_t=q.top().idx;
                q.pop();
            }while(!q.empty() and cnt[new_t]==0);
            if(cnt[new_t]==0) break;
            if(cnt[new_t]>=d){
                val+=d*c[new_t],cnt[new_t]-=d,d=0;
                if(cnt[new_t]) q.push((cmp){new_t});
            }
            else{
                d-=cnt[new_t],val+=cnt[new_t]*c[new_t],cnt[new_t]=0;
            }
        }
        if(d) val=0;
        printf("%I64d\n",val);
    }
    return 0;
}