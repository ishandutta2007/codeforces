#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int T,n;
char s[100010];
int main(){
    cin>>T;
    while(T--){
        scanf("%d%s",&n,s+1);
        int last=s[1],cnt[2]={0};
        for(int i=2;i<=n;i++){
            if(s[i]==last) continue;
            else cnt[last-'0']++,last=s[i];
        }
        cnt[last-'0']++;
        printf("%d\n",n/2-min(cnt[1],cnt[0]));
    }
    return 0;
}