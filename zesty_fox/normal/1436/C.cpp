#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MOD=1e9+7;
int n,x,pos,a[1010],flg[1010];
void ef(){
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)/2;
        flg[mid]=(mid>pos)?2:((mid<pos)?1:3);
        if(mid<=pos) l=mid+1;
        else r=mid;
    }
}

int main(){
    scanf("%d%d%d",&n,&x,&pos);
    for(int i=0;i<n;i++) a[i]=i+1;
    ef();ll ans=1,cnt[4]={0};
    for(int i=0;i<=n-1;i++) cnt[flg[i]]++;
    for(int i=0;i<cnt[1];i++){
        flg[i]=1;
        (ans*=(x-i-1))%=MOD;
    }
    for(int i=cnt[1];i<cnt[1]+cnt[2];i++){
        flg[i]=2;
        (ans*=(n-x-(i-cnt[1])))%=MOD;
    }
    for(int i=cnt[1]+cnt[2]+cnt[3];i<n;i++) {
        flg[i]=0;
        (ans*=(n-i))%=MOD;
    }
    cout<<ans<<endl;
    return 0;
}