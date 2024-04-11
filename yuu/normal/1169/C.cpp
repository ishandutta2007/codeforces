#include <bits/stdc++.h>
using namespace std;
int a[300000];
int n, m;
bool check(int k){
    int low=0;
    for(int i=0; i<n; i++){
        int last=(a[i]+k)%m;
        if(last>=a[i]){
            if(low>last) return 0;
            if(low<=a[i]) low=a[i];
        }
        else if(low>last&&low<a[i]) low=a[i];
    }
    return 1;
}
int main(){
    cin>>n>>m;
    for(int i=0; i<n; i++) cin>>a[i];
    int low=0, high=m-1, res=m, mid;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid)){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    cout<<res;
}