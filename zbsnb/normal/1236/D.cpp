#include<iostream>
#include<set>
using namespace std;
#define ll long long
set<int> x[100010],y[100100];
set<int,greater<int> > xr[100010],yr[100100];
int nowa,nowb,nowc,nowd;
ll sum=0;
void dfs(int a,int b,int tag){
    if(tag==1){
        int tmp=min(*x[a].lower_bound(b),nowd)-1;
        nowd=tmp;if(tmp==b)return;
        sum+=tmp-b;dfs(a,tmp,2);
    }
    else if(tag==2){
        int tmp=min(*y[b].lower_bound(a),nowc)-1;
        nowc=tmp;if(tmp==a)return;
        sum+=tmp-a;dfs(tmp,b,3);
    }
    else if(tag==3){
        int tmp=max(*xr[a].lower_bound(b),nowb)+1;
        nowb=tmp;if(tmp==b)return;
        sum+=b-tmp;dfs(a,tmp,4);
    }
    else if(tag==4){
        int tmp=max(*yr[b].lower_bound(a),nowa)+1;
        nowa=tmp;if(tmp==a)return;
        sum+=a-tmp;dfs(tmp,b,1);
    }
}

int main(){
    int n,m,k;cin>>n>>m>>k;
    for(int i=1;i<=k;i++){
        int a,b;cin>>a>>b;
        x[a].insert(b);
        xr[a].insert(b);
        y[b].insert(a);
        yr[b].insert(a);
    }
    for(int i=1;i<=n;i++){
        x[i].insert(m+1);
        xr[i].insert(0);
    }
    for(int j=1;j<=m;j++){
        y[j].insert(n+1);
        yr[j].insert(0);
    }
    nowa=1,nowb=0;
    nowc=n+1,nowd=m+1;
    dfs(1,0,1);
    cout<<((sum+k==1ll*n*m)?"Yes":"No")<<endl;
}