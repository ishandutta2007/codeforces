#include<bits/stdc++.h>
using namespace std;
int n,now,sz;
char s[201000];
vector<int>v;

bool doit(){
    int pos=0,w,to;
    for (int i=1;i;i++){
        if (i>n) return 1;
        if (s[i]!='*') continue;
        while (pos<sz&&abs(v[pos]-i)>now) pos++;
        if (pos>=sz) return 0;
        w=v[pos];
        if (i>=w) to=w+now;
        else to=max(i+now-(w-i),i+(now+w-i)/2);
        i=to;
        pos++;
    }
}

int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for (int i=1;i<=n;i++){
        if (s[i]=='P'){
            v.push_back(i);
        }
    }
    sz=v.size();
    int l=0,r=200000,mid,ans;
    while (l<=r){
        now=mid=(l+r)>>1;
        if (doit()){
            r=(ans=mid)-1;
        }else{
            l=mid+1;
        }
    }
    cout<<ans;
}