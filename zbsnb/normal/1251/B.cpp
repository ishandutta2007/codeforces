#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define ll long long

char s[1010];

int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        int flg=0;
        int cnt=0;
        for(int i=1;i<=n;i++){
            cin>>s;
            int len=strlen(s);
            if(len%2)flg=1;
            for(int i=0;i<len;i++){
                if(s[i]=='1')cnt++;
            }
        }
        if(cnt%2&&!flg)cout<<n-1<<endl;
        else cout<<n<<endl;

    }
}