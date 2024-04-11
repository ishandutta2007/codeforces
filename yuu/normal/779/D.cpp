#include <iostream>
#include <stdio.h>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
using namespace std;
#define taskname "D"
string p, t, temp;
int a[200001];
int n, m;
bool check(int s){
    temp=t;
    FOR(i, 1, s)
        temp[a[i]]='A';
    int i=1;
    FOR(j, 1, n){
        if(temp[j]==p[i]){
            i++;
            if(i>m) return 1;
        }
    }
    return 0;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>t>>p;
    n=t.size();
    m=p.size();
    t='A'+t;
    p='A'+p;
    FOR(i, 1, n)
        cin>>a[i];
    int ans=0;
    int l=1, r=n-m;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){
            ans=max(ans, mid);
            l=mid+1;
        }
        else r=mid-1;
    }
    cout<<ans;
}