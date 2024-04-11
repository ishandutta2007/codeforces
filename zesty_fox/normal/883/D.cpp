#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int N=1000010;
int n,cntb,suf[N];
char str[N];
bool f[N];
inline bool check(int lim){
    memset(f,0,sizeof(bool)*(n+5));
    f[0]=1;
    for(int i=1;i<=n;i++){
        if(!f[i-1]) continue;
        if(str[i]=='.') f[i]=1;
        else if(str[i]=='P') f[min(i+lim,min(suf[i]-1,n))]=f[i]=1;
        else{
            if(suf[i]-i<=lim){
                f[suf[i]]=1;
                if(suf[suf[i]]-i<=lim)
                    f[min(suf[i]+lim,min(suf[suf[suf[i]]]-1,n))]=1;
            }
        }
    }
    return f[n];
}

void work(){
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%d %d\n",cntb,l);
}

int main(){
    scanf("%d%s",&n,str+1);
    int le=1,ri=n;
    while(str[le]!='P'&&le<=n) le++;
    while(str[ri]!='P'&&ri>=1) ri--;
    if(le==ri){
        int cnt1=0,cnt2=0,last1=le,last2=le;
        for(int i=le+1;i<=n;i++){
            if(str[i]=='*') cnt1++,last1=max(last1,i);
        }
        for(int i=le-1;i>=1;i--){
            if(str[i]=='*') cnt2++,last2=min(last2,i);
        }
        if(cnt1>cnt2) printf("%d %d\n",cnt1,last1-le);
        else if(cnt1<cnt2) printf("%d %d\n",cnt2,le-last2);
        else printf("%d %d\n",cnt1,min(le-last2,last1-le));
        return 0;
    }
    suf[n+1]=1e9+7;
    for(int i=n;i>=1;i--){
        if(str[i+1]=='P') suf[i]=i+1;
        else suf[i]=suf[i+1];
        if(str[i]=='*') cntb++;
    }
    work();
    return 0;
}