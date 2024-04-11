#include<bits/stdc++.h>
using namespace std;
int T,s[25],n,ans;

int main(){
    cin >> T;
    while (T--){
        cin >> n;
        for (int i=1;i<=7;i++) cin >> s[i];
        for (int i=1;i<=7;i++) s[i+7]=s[i];
        for (int i=1;i<=14;i++) s[i]+=s[i-1];
        int p=(n-1)/s[7];
        ans=p*7; n-=p*s[7];
        int mn=7;
        for (int i=0;i<=7;i++)
        for (int j=i+1;j<=14;j++)
            if (s[j]-s[i]>=n) mn=min(mn,j-i);
        printf("%d\n",ans+mn);
    }
    return 0;
}