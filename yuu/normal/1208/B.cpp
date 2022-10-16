#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
using ll=long long;
using ld=long double;
#define taskname "B"
int n;
int a[2000];
int cnt[2000];
map <int, int> s;
///f...l
bool check(int length){
    for(int i=0; i<n; i++) cnt[i]=0;
    int now=0;
    for(int i=length; i<n; i++){
        cnt[a[i]]++;
        if(cnt[a[i]]==1) now++;
    }
    if(now==n-length) return 1;
    for(int i=length; i<n; i++){
        cnt[a[i]]--;
        if(cnt[a[i]]==0) now--;
        cnt[a[i-length]]++;
        if(cnt[a[i-length]]==1) now++;
        if(now==n-length) return 1;
    }
    return 0;
}
int main(){
    #ifdef Aria
        freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n;
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<n; i++) s[a[i]]=0;
    if(s.size()==n){
        puts("0");
        return 0;
    }
    else{
        {
            int cnt=0;
            for(auto &x: s){
                x.second=cnt;
                cnt++;
            }
        }
        for(int i=0; i<n; i++) a[i]=s[a[i]];
        int low=1, high=n-2, mid, res=n-1;
        while(low<=high){
            mid=(low+high)/2;
            if(check(mid)){
                res=mid;
                high=mid-1;
            }
            else low=mid+1;
        }
        cout<<res<<'\n';
    }
}