#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[200010];
int cnt[200010];
int p[400010];
const int base=200005;
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;cin>>n;
    
    for(int i=1;i<=n;i++){
        cin>>a[i];
        cnt[a[i]]++;
    }
    int maxn=0,_cnt=0,pos=-1;
    for(int i=1;i<=100;i++){
        if(cnt[i]>maxn){
            maxn=cnt[i];
            _cnt=1;
            pos=i;
        }
        else if(cnt[i]==maxn) _cnt++;
    }
    if(_cnt>=2) cout<<n<<endl;
    else{
        int ans=0;
        for(int i=1;i<=100;i++){
            for(int j=base-n;j<=base+n;j++) p[j]=-1;
            p[base]=0;
            if(i==pos) continue;
            int now=base;
            for(int j=1;j<=n;j++){
                if(a[j]==pos) now++;
                if(a[j]==i) now--;
                if(p[now]!=-1) ans=max(ans,j-p[now]);
                else p[now]=j;
            }
        }
        cout<<ans<<endl;
    }
}