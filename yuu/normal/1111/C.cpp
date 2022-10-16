#include <bits/stdc++.h>
using namespace std;
int n, k;
long long a, b;
int p[100001];
int find_first(int x){
    int low=1, high=k, mid, res=k+1;
    while(low<=high){
        mid=(low+high)/2;
        if(p[mid]>=x){
            res=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    return res;
}
int find_last(int x){
    int low=1, high=k, mid, res=0;
    while(low<=high){
        mid=(low+high)/2;
        if(p[mid]<=x){
            res=mid;
            low=mid+1;
        }
        else high=mid-1;
    }
    return res;
}
long long solve(int l, int r){
    int be=find_first(l);
    int en=find_last(r);
    if(be>en) return a;
    long long res=b*(en-be+1)*(r-l+1);
    if(l==r) return res;
    int m=(l+r)/2;
    res=min(res, solve(l, m)+solve(m+1, r));
    return res;
}
int main(){
    cin>>n>>k>>a>>b;
    for(int i=1; i<=k; i++) cin>>p[i];
    sort(p+1, p+k+1);
    cout<<solve(1, 1<<n);
}