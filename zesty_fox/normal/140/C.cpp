#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
int n,r[1000005],r1[1000005],cnt[1000005];
int now,step;
priority_queue<pair<int,int> >q;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&r[i]);
    }
    sort(r+1,r+n+1);
    for(int i=1;i<=n;i++){
        if(r[i]>r[i-1]){
            now++;
            r1[now]=r[i];
            cnt[now]++;
        }
        else cnt[now]++;
    }
    for(int i=1;i<=now;i++){
        q.push(make_pair(cnt[i],i));
    }
    while(q.size()>=3){
        int x=q.top().second,cntx=q.top().first;q.pop();
        int y=q.top().second,cnty=q.top().first;q.pop();
        int z=q.top().second,cntz=q.top().first;q.pop();
        step++;
        if(cntx-1) q.push(make_pair(cntx-1,x));
        if(cnty-1) q.push(make_pair(cnty-1,y));
        if(cntz-1) q.push(make_pair(cntz-1,z));
    }
    printf("%d\n",step);
    while(!q.empty()) q.pop();
    for(int i=1;i<=now;i++){
        q.push(make_pair(cnt[i],i));
    }
    while(q.size()>=3){
        int x=q.top().second,cntx=q.top().first;q.pop();
        int y=q.top().second,cnty=q.top().first;q.pop();
        int z=q.top().second,cntz=q.top().first;q.pop();
        if(x<y) swap(x,y),swap(cntx,cnty);
        if(y<z) swap(y,z),swap(cnty,cntz);
        if(x<y) swap(x,y),swap(cntx,cnty);
        printf("%d %d %d\n",r1[x],r1[y],r1[z]);
        if(cntx-1) q.push(make_pair(cntx-1,x));
        if(cnty-1) q.push(make_pair(cnty-1,y));
        if(cntz-1) q.push(make_pair(cntz-1,z));
    }
    return 0;
}