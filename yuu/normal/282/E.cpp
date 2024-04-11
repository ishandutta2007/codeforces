#include <bits/stdc++.h>
using namespace std;
int n;
long long a[100002];
long long b[100002];
class trie{
public:
    class node{
    public:
        using pointer=node*;
        pointer g[2];
        node(){
            g[0]=g[1]=nullptr;
        }
    };
    node::pointer root;
    void make(){
        root=new node();
    }
    void add(long long x){
        auto now=root;
        for(int i=44; i>=0; i--){
            int b=(x>>i)&1;
            if(now->g[b]==nullptr) now->g[b]=new node;
            now=now->g[b];
        }
    }
    long long find(long long x){
        auto now=root;
        long long ans=0;
        for(int i=44; i>=0; i--){
            int b=(x>>i)&1;
            if(now->g[1-b]==nullptr) now=now->g[b];
            else{
                ans^=1LL<<i;
                now=now->g[1-b];
            }
        }
        return ans;
    }
} tree;
int main(){
    cin>>n;
    tree.make();
    for(int i=1; i<=n; i++) cin>>a[i];
    for(int i=1; i<=n; i++) b[i]=a[i];
    for(int i=1; i<=n; i++) a[i]^=a[i-1];
    for(int i=n; i>=1; i--) b[i]^=b[i+1];
    long long ans=0;
    tree.add(0);
    for(int i=0; i<=n; i++){
        ans=max(ans, tree.find(b[i+1]));
        tree.add(a[i]);
    }
    cout<<ans<<'\n';
}