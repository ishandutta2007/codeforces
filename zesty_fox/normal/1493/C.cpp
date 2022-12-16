#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
           if(ch=='-') f=-1;
           ch=getchar();
        }
    while(ch>='0'&&ch<='9'){
           x=(x<<1)+(x<<3)+(ch^48);
           ch=getchar();
        }
    return x*f;
}
 
#define rdi read<int>
#define rdl read<ll>
 
const int N=100010;
int T,n,k;
char s[N];
int main(){
    T=rdi();
    while(T--){
        n=rdi(),k=rdi(),scanf("%s",s+1);
        if(n%k){
            puts("-1");
            continue;
        }
        int cnt[30]={0};
        for(int i=1;i<=n;i++) cnt[s[i]-'a']++;
        bool flg=1;
        for(int j=0;j<26;j++) flg&=((cnt[j]%k)==0);
        if(flg){
            printf("%s\n",s+1);
            continue;
        }
        for(int i=n;i>=1;i--){
            int cur=s[i]-'a',success=0;
            for(int j=cur+1;j<=26;j++){
                cnt[cur]--;cnt[j]++;s[i]=j+'a';
                int kkk=0;
                for(int j=0;j<26;j++){
                    if(cnt[j]%k) kkk+=(k-cnt[j]%k)%k;
                }
                if(kkk<=n-i&&(n-i-kkk)%k==0){
                    int pos=i;
                    for(int o=1;o<=(n-i-kkk)-(n-i-kkk)%k;o++) s[++pos]='a';
                    for(int o=0;o<26;o++){
                        if(cnt[o]%k){
                            for(int p=1;p<=(k-cnt[o]%k);p++) s[++pos]=o+'a';
                        }
                    }
                    success=1;
                    goto ed;
                }
                cnt[cur]++,cnt[j]--;s[i]=cur+'a';
            }
            cnt[s[i]-'a']--;
        }
//        char cur=s[0]+1;
  //      for(int i=1;i<=k;i++) s[i]=
ed:
        printf("%s\n",s+1);
    }
    return 0;
}