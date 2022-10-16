#include <bits/stdc++.h>
using namespace std;
int done[10000001];
int n, a;
long long ans=1e18;
int ba, bb;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    for(int i=1; i<=n; i++){
        cin>>a;
        if(done[a]){
            if(ans>a){
                ans=a;
                ba=done[a];
                bb=i;
            }
        }
        else done[a]=i; 
    }
    for(int gcd=1; gcd<=10000000; gcd++){
        int a=-1;
        for(int now=gcd; now<=10000000; now+=gcd){
            if(done[now]){
                if(a==-1) a=now;
                else{
                    if(ans>((long long)(a))*now/gcd){
                        ans=((long long)(a))*now/gcd;
                        ba=done[a];
                        bb=done[now];
                    }
                    break;
                }
            }
        } 
    }
    if(ba>bb) swap(ba, bb);
    cout<<ba<<' '<<bb<<'\n';
}