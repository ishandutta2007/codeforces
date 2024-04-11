#include<iostream>
#include<algorithm>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
#define ll long long
// #define int long long

char s[1000010];
int a[1000010];
int b[1000010];

signed main(){
    int t;cin>>t;
    while(t--){
        cin>>s;
        int n=strlen(s);
        int f1=0,f2=0,cnt=0;
        for(int i=0;i<n;i++){
            cnt+=s[i]-48;
            if(s[i]=='0'){
                f1++;
            }
            if((s[i]-48)%2==0&&s[i]!='0'){
                f2=1;
            }
        }
        // cout<<f1<<" "<<f2<<" "<<cnt<<endl;
        if((f1>=2||f1==1&&f2)&&(cnt%3==0))cout<<"red"<<endl;
        else cout<<"cyan"<<endl;
    }
}