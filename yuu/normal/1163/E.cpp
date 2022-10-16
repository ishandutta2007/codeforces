#include <bits/stdc++.h>
using namespace std;
int n;
int s[200001];
int done[500001];
set <int> all;
void answer(vector <int> s){
    int x=s.size();
    cout<<x<<'\n';
    vector <int> ans;
    all.insert(0);
    int back=0;
    int now=0;
    cout<<now<<' ';
    for(int a=(1<<x)-1; a>0; a--){
        for(int j=0; j<x; j++) if(all.find(back^(1<<j))==all.end()){
            back^=1<<j;
            all.insert(back);
            now^=s[j];
            cout<<now<<' ';
            break;
        }
    }
    exit(0);
}
void test(int x){
    int maxv=(1<<x);
    while(s[n]>=maxv) n--;
    if(n==0) return;
    for(int i=0; i<maxv; i++) done[i]=1e9;
    done[0]=0;
    vector <int> sp;
    for(int i=1; i<=n; i++){
        if(done[s[i]]<i) continue;
        else{
            sp.push_back(s[i]);
            if(sp.size()==x) break;
            for(int j=0; j<maxv; j++) if(done[j]<i) done[j^s[i]]=min(done[j^s[i]], i);
        }
    }
    if(sp.size()==x) answer(sp);
}
int main(){
    cin>>n;
    for(int i=1; i<=n; i++) cin>>s[i];
    sort(s+1, s+n+1);
    for(int x=__lg(s[n]*2); x>0; x--) test(x);
    cout<<"0\n0";
}