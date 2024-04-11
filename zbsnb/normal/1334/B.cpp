#include<bits/stdc++.h>
using namespace std;
#define ll long long 
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int t;cin>>t;
    while(t--){
        int n,m;cin>>n>>m;
        priority_queue<int> q;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            q.push(tmp);
        }
        ll ans=0;int cnt=0;
        while(!q.empty()){
            int tmp=q.top();q.pop();
            if((ans+tmp)/(cnt+1)>=m) ans+=tmp,cnt++;
            else break;
        }
        cout<<cnt<<endl;
    }
}