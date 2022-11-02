#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
#include<set>
using namespace std;

int a[300010];
int ans[100010];
int main(){
    int n;cin>>n;
    int maxn=1,minn=1e9;
    for(int i=1;i<=n;i++)cin>>a[i],a[2*n+i]=a[n+i]=a[i],minn=min(minn,a[i]),maxn=max(maxn,a[i]);
    if(maxn<=2*minn){
        for(int i=1;i<=n;i++)cout<<"-1 ";
        cout<<endl;
    }
    else{
        multiset<int> s;
        int p=0;
        for(int i=1;i<=3*n;i++){
            while(!s.empty()&&*(--s.end())>2*a[i]){
                s.erase(s.find(a[++p]));
                ans[p]=i-p;
            }
            s.insert(a[i]);
        }
        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}