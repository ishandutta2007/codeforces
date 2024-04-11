#include<iostream>
#include<algorithm>
using namespace std;
int pre[200010];
int sum[200010];
int find(int x){return pre[x]==x?x:pre[x]=find(pre[x]);}
void unin(int x,int y){
    int fx=find(x);
    int fy=find(y);
    pre[fx]=fy;
    sum[fy]+=sum[fx];
}
int main(){
    int t;cin>>t;
    while(t--){
        int n;cin>>n;
        for(int i=1;i<=n;i++)pre[i]=i,sum[i]=1;
        for(int i=1;i<=n;i++){
            int tmp;cin>>tmp;
            unin(i,tmp);
        }
        for(int i=1;i<=n;i++){
            cout<<sum[find(i)]/2<<" ";
        }cout<<endl;
    }
}