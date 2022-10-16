#include <bits/stdc++.h>
using namespace std;
int n;
int a[200001];
int cnt[200001];
queue <int> q;
int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int mar=0;
    for(int i=1; i<=200000; i++) if(cnt[i]>cnt[mar]) mar=i;
    cout<<n-cnt[mar]<<'\n';
    for(int i=1; i<=n; i++) if(a[i]==mar) q.push(i);
    while(!q.empty()){
        int i=q.front();
        q.pop();
        if(i<n){
            if(a[i+1]!=mar){
                cout<<"12"[a[i]<a[i+1]]<<' '<<i+1<<' '<<i<<'\n';
                a[i+1]=mar;
                q.push(i+1);
            }
        }
        if(i>1){
            if(a[i-1]!=mar){
                cout<<"12"[a[i]<a[i-1]]<<' '<<i-1<<' '<<i<<'\n';
                a[i-1]=mar;
                q.push(i-1);
            }
        }
    }
    //for(int i=1; i<=n; i++) cout<<a[i]<<" \n"[i==n];
}