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
#define NMAX 1005
typedef long long ll;
string s;
ll n,dem[NMAX],ans;
void enter(){
    read(n);
    for(int i=1;i<=n;i++){
        cin>>s;
        for(int j=0;j<s.size();j++){
            if(s[j]=='1'){
                dem[j]++;
            }
        }
    }
}
void print(){
    for(int i=0;i<=6;i++){
        ans=max(ans,dem[i]);
    }
    writeln(ans);
}
int main(){
    enter();
    print();
}