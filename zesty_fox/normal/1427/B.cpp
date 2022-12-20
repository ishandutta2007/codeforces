#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int N=100010;
int T,n,k,vis[N],ti;
char s[N];
vector<int> v;
int main(){
    cin>>T;
    while(T--){
        int ans=0;v.clear();
        scanf("%d%d%s",&n,&k,s+1);
        int l=0;s[0]=s[n+1]='L';
        for(int i=1;i<=n;i++){
            if(s[i]=='L'&&s[i-1]=='W') l=i;
            if(s[i]=='L'&&s[i+1]=='W'&&l!=0) v.push_back(i-l+1);
            if(s[i]=='W') ans+=(s[i-1]=='W'?2:1);
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++){
            int x=v[i];
            if(k>=x) ans+=(2*x+1),k-=x;
            else{
                ans+=2*k;
                k=0;
                break;
            }
        }
        if(k){
            int len1=0,len2=0;
            for(len1=1;s[len1]=='L'&&len1<=n;len1++);
            --len1;
            if(len1<n){
                for(len2=n;len2>=1&&s[len2]=='L';len2--);
                ++len2;len2=n-len2+1;
            }
            else{
                ans+=min(n,k)*2-1;
                goto end;
            }
            if(len1){
                ans+=2*min(k,len1),k-=min(k,len1);
            }
            if(len2){
                ans+=2*min(k,len2),k-=min(k,len2);
            }
        }
        end:
        printf("%d\n",ans);
    }
    return 0;
}