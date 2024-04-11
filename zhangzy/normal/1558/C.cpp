#include<bits/stdc++.h>
using namespace std;

int n, a[2222];
vector<int>ans;

void fuck(){
    cin>>n;
    for (int i=1;i<=n;++i) cin>>a[i];
    int fl=1;
    for (int i=1;i<=n;++i){
        if (i%2!=a[i]%2) fl=0;
    }
    if (!fl){
        puts("-1"); return;
    }
    ans.clear();
    while (n>1){
        int p1=0, p2=0;
        for (int i=1;i<=n;++i){
            if (a[i]==n) p1=i;
            if (a[i]==n-1) p2=i;
        }
        if (p1<p2){
            ans.push_back(p1);
            ans.push_back(p2-1);
            ans.push_back(p2+1);
            ans.push_back(3);
            ans.push_back(n);
        }else{
            ans.push_back(p1);
            ans.push_back(1+p1-p2-1);
            ans.push_back(1+p1-p2+1);
            ans.push_back(3);
            ans.push_back(n);
        }
        for (int i=ans.size()-5;i<ans.size();++i){
            reverse(a+1,a+ans[i]+1);
        }
        n-=2;
    }
    cout<<ans.size()<<endl;
    for (auto o:ans) printf("%d ",o);
    puts("");
}

int main(){
    int T;
    for (cin>>T;T--;){
        fuck();
    }
}