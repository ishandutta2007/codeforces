#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
int t,n,step[200005][2];
priority_queue<int> q;
int main(){
    cin>>t;
    while(t--){
        cin>>n;int s=0;
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++) q.push(i);
        while(!q.empty()){
            if(q.size()==1){
                printf("%d\n",q.top());
                for(int i=1;i<=s;i++){
                    printf("%d %d\n",step[i][0],step[i][1]);
                }
                break;
            }
            int x=q.top();q.pop();
            int y=q.top();q.pop();
            step[++s][0]=x,step[s][1]=y;
            q.push(((x+y)&1)?(x+y+1)/2:(x+y)/2);
        }
    }
    return 0;
}