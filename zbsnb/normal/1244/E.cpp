#include<iostream>
#include<map>
using namespace std;
#define ll long long
int a[100010];
int cnt[100010];

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    int n;ll k;
    cin>>n>>k;
    map<int,int> mp;
    for(int i=1;i<=n;i++){
        int tmp;cin>>tmp;
        mp[tmp]++;
    }
    int p=0;
    for(auto it=mp.begin();it!=mp.end();it++){
        a[++p]=it->first,cnt[p]=it->second;
    }
    int l=1,r=p,cnt1=cnt[1],cnt2=cnt[p];
    int ans=a[p]-a[1];ll sum=0;
    for(int i=1;i<=p-1;i++){
        //cout<<l<<" "<<r<<" "<<cnt1<<" "<<cnt2<<endl;
        if(cnt1<cnt2){
            ll tmp=1ll*(a[l+1]-a[l])*cnt1;
            if(sum+tmp>k){
                ans-=(k-sum)/cnt1;
                break;
            }
            else sum+=tmp,ans-=a[l+1]-a[l],cnt1+=cnt[++l];
        }
        else{
            ll tmp=1ll*(a[r]-a[r-1])*cnt2;
            if(sum+tmp>k){
                ans-=(k-sum)/cnt2;
                break;
            }
            else sum+=tmp,ans-=a[r]-a[r-1],cnt2+=cnt[--r];
        }
    }
    cout<<max(0,ans)<<endl;
}