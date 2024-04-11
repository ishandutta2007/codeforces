/*ndcoutinho*/
#include <bits/stdc++.h>
using namespace std;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define NMAX 200005
#define pb push_back
typedef long long ll;
ll n,res;
char s[NMAX];
vector <int> pm;
vector <int> sao;
ll numsao;
void enter(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s[i];
        if(s[i]=='P') pm.pb(i);
        if(s[i]=='*') sao.pb(i);
    }
    numsao=sao.size();
}
bool thoaman(ll u,ll val){
    return u<=val;
}
bool check(ll val){
    int start=0; // con sao dau tien
    ll distance=0;
    for(int i=0;i<pm.size();i++){
        int pos=pm[i];
        int now=start; // dung tai con start
      //  int start=0;
        if(thoaman(abs(pos-sao[now]),val)){
          //  cout<<pos<<" "<<now<<" ";
         //   exit(0);
            while(numsao-1>start){
        //        cout<<sao[start]<<" "<<sao[start+1]<<'\n';
                distance=abs(pos-sao[now]);
                if(distance>abs(pos-sao[start+1])) distance=abs(pos-sao[start+1]);
                distance+=abs(sao[start+1]-sao[now]);
              //  if(distance>abs(pos-sao[start+1])) distance=abs(pos-sao[start+1]);
                if(thoaman(distance,val)) start++;
                else goto line0;
            }
            line0:;
            if(start<numsao) start++;
        }
    }
    if(start==numsao) return true;
    return false;
}
void solve(){
    ll l=0,r=2*n;
    while(l<=r){
        ll m=(l+r)>>1;
   //     cout<<m<<" ";
        if(check(m)){
            res=m;
            r=m-1;
        }
        else l=m+1;
    }
    writeln(res);
}
int main(){
    //freopen("1.inp","r",stdin);
    enter();
    solve();
}