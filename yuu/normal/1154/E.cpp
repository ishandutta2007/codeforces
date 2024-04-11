#include <bits/stdc++.h>
using namespace std;
int n, k, a[200002];
#define next Kafuu
#define prev Chino
int next[200002];
int prev[200002];
int pos[200002];
int team[200002];
bool done[200002];
int main(){
    cin>>n>>k;
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) next[i]=i+1;
    for(int i=1; i<=n; i++) prev[i]=i-1;
    for(int i=1; i<=n; i++) pos[a[i]]=i;
    for(int mx=n, t=1; ; t=3-t){
        while(mx&&done[mx]) mx--;
        if(mx==0) break;
        int i=pos[mx];
        done[mx]=1;
        team[i]=t;
        int f=0, s=n+1;
        for(int j=next[i], c=k; (j<=n)&&(c>0); j=next[j], c--){
            s=next[j];
            team[j]=t;
            done[a[j]]=1;
        }
        for(int j=prev[i], c=k; (j<=n)&&(c>0); j=prev[j], c--){
            f=prev[j];
            team[j]=t;
            done[a[j]]=1;
        }
        next[f]=s;
        prev[s]=f;
    }
    for(int i=1; i<=n; i++) cout<<team[i];
}