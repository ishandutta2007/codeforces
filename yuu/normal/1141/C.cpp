#include <bits/stdc++.h>
using namespace std;
int n;
long long p[200001];
long long q[200001];
bool done[200001];
int main(){
    cin>>n;
    for(int i=1; i<n; i++) cin>>q[i];
    for(int i=2; i<=n; i++) p[i]=p[i-1]+q[i-1];
    int shift=*min_element(p+1, p+n+1)-1;
    for(int i=1; i<=n; i++) p[i]-=shift;
    if(*max_element(p+1, p+n+1)!=n){
        cout<<-1<<'\n';
        return 0;
    }
    for(int i=1; i<=n; i++){
        if(done[p[i]]){
            cout<<-1<<'\n';
            return 0;
        }
        done[p[i]]=1;
    }
    for(int i=1; i<=n; i++) cout<<p[i]<<" \n"[i==n];
}