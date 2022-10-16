#include <bits/stdc++.h>
using namespace std;
int feq[200001];
int n, k;
int main(){
    cin>>n>>k;
    for(int i=0, a; i<n; i++){
        cin>>a;
        feq[a]++;
    }
    int low=1, high=n, mid, res=0;
    while(low<=high){
        mid=(low+high)/2;
        int cnt=0;
        for(int i=1; i<=200000; i++) cnt+=feq[i]/mid;
        if(cnt>=k){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    for(int i=1; i<=200000; i++){
        while(k&&(feq[i]>=res)){
            k--;
            feq[i]-=res;
            cout<<i<<" \n"[k==0];
        }
    }
}