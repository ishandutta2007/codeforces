#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <map>
#include <string>
#include <vector>
#define mod 1000000007
#define mp make_pair
#define pii pair<int,int>
#define For(i,a,n)  for(int i=(a);i<=(n);i++)
#define Forn(i,a,n) for(int i=(a);i>=(n);i--)
#define REP(i,n)    for(int i=(1);i<=(n);i++)
using namespace std;
typedef long long LL;
typedef double db;
char s[200005],t[200005];
int n,m,L[200005],R[200005];
int cha[27][200005];

int main(){
    scanf("%s",s+1);
    scanf("%s",t+1);
    n=strlen(s+1);
    m=strlen(t+1);
    int pi=1;
    For(i,1,m){
        while(s[pi]!=t[i] && pi<=n) ++pi;
        if(pi>n){
            puts("No");
            return 0;
        }
        L[i]=pi;
        ++pi;
    }
    pi=n;
    Forn(i,m,1){
        while(s[pi]!=t[i] && pi>=1) --pi;
        if(pi<=0){
            puts("No");
            return 0;
        }
        R[i]=pi;
        --pi;
    }
    For(i,1,m){
        cha[t[i]-'a'][L[i]]++;
        cha[t[i]-'a'][R[i]+1]--;
    }
    For(i,0,25) For(j,1,n) cha[i][j]+=cha[i][j-1];
    For(i,1,n){
        int z=cha[s[i]-'a'][i];
        if(!z){
            puts("No");
            return 0;
        }
    }
    puts("Yes");
    return 0;
}