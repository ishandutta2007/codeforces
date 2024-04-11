#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<algorithm>
using namespace std;
#define ll long long
#define int ll

int a[200010];
int ans[200010],p;
signed main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    set<int> s1,s2;

    int flg=0;
    for(int i=1;i<=n;i++){
        if(s1.empty()&&!s2.empty()){
            ans[++p]=i-1;
            s2.clear();
        }

        if(a[i]>0){
            if(s2.find(a[i])!=s2.end()){
                flg=1;
                break;
            }
            else{
                s1.insert(a[i]);
                s2.insert(a[i]);
            }
        }
        else{
            if(s1.find(-a[i])!=s1.end()){
                s1.erase(-a[i]);
            }
            else{
                flg=1;
                break;
            }
        }
    }
    if(!s1.empty())flg=1;
    if(flg)cout<<-1<<endl;
    else{
        cout<<p+1<<endl;
        for(int i=1;i<=p;i++){
            cout<<ans[i]-ans[i-1]<<" ";
        }
        cout<<n-ans[p]<<endl;
    }
}