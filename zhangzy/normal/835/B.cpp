#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll k,l,tot,cnt[233],ans;
char s[520233];
int main(){
    scanf("%I64d\n",&k);
    scanf("%s",s);
    l=strlen(s);
    memset(cnt,0,sizeof(cnt));
    for (int i=0;i<l;i++){
        cnt[s[i]-'0']++;
        tot+=s[i]-'0';
    }
    ans=0;
    int p=0;
    for (;tot<k;){
        while (cnt[p]<=0) p++;
        cnt[p]--;
        tot+=9-p;
        ans++;
    }
    cout<<ans;
}