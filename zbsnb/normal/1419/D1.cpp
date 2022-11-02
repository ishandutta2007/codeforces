#include<bits/stdc++.h>
using namespace std;
int a[100010];
int main(){
    int n;cin>>n;
    priority_queue<int> q;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        q.push(tmp);
    }
    for(int i=1;i<=n-n/2;i++){
        a[i*2-1]=q.top();q.pop();
    }
    for(int i=1;i<=n/2;i++){
        a[i*2]=q.top();q.pop();
    }
    int ans=0;
    for(int i=2;i<=n-1;i++){
        if(a[i]<a[i-1]&&a[i]<a[i+1]) ans++;
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++) cout<<a[i]<<" ";
    cout<<endl;
}