#include<bits/stdc++.h>
using namespace std;
int n,cnt,ans;
string s;
int main(){
    scanf("%d\n",&n);
    getline(cin,s);
    s+=' ';
    ans=cnt=0;
    for (int i=0;i<=n;i++){
        if (s[i]==' '){
            ans=max(ans,cnt);
            cnt=0;
        }else{
            if (s[i]>='A'&&s[i]<='Z'){
                cnt++;
            }
        }
    }
    printf("%d",ans);
}