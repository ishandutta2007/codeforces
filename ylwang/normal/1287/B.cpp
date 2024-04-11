#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
    char c=getchar();bool f=0;x=0;
    while(!isdigit(c)) f|=c=='-',c=getchar();
    while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
    if(f) x=-x;return x;
}
template<class t> inline void write(t x){
    if(x<0) putchar('-'),write(-x);
    else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int N=100005;
int n,m;
string s[N];
long long ans;
map<string,int> mp;

signed main(){
    read(n);read(m);
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            string aim=""; //
            for(int k=0;k<m;k++){
                if(s[i][k]==s[j][k]) aim+=s[i][k]; //
                else{
                    if(s[i][k]!='S'&&s[j][k]!='S') aim+='S'; //
                    if(s[i][k]!='E'&&s[j][k]!='E') aim+='E';
                    if(s[i][k]!='T'&&s[j][k]!='T') aim+='T';
                }
            }
            ans+=mp[aim]; //
        }
        mp[s[i]]++; //
    }
    write(ans);
}