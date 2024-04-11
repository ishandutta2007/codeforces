#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;

struct easy{
    int a,b,c,id;
    bool operator<(const easy &x){
        return a<x.a||a==x.a&&b<x.b||a==x.a&&b==x.b&&c<x.c;
    }
}e[50010];
int q[50010];
int q2[50010];
int main(){
    int n;cin>>n;
    for(int i=1;i<=n;i++){
        cin>>e[i].a>>e[i].b>>e[i].c;e[i].id=i;
    }
    sort(e+1,e+n+1);

    int cnt=1;
    int p2=0;
    for(int i=2;i<=n+1;i++){
        if(i!=n+1&&e[i].a==e[i-1].a)cnt++;
        else{
            int p=0;
            int cnt2=1;
            for(int j=i-cnt+1;j<=i;j++){
                if(j!=i&&e[j].b==e[j-1].b)cnt2++;
                else{
                    for(int k=j-cnt2;k<j-1;k+=2){
                        cout<<e[k].id<<" "<<e[k+1].id<<endl;
                    }
                    if(cnt2%2==1)q[++p]=j-1;
                    cnt2=1;
                }
            }

            for(int k=1;k<p;k+=2){
                cout<<e[q[k]].id<<" "<<e[q[k+1]].id<<endl;
            }
            if(p%2==1)q2[++p2]=q[p];
            p=0;
            cnt=1;
        }
    }
     for(int k=1;k<p2;k+=2){
        cout<<e[q2[k]].id<<" "<<e[q2[k+1]].id<<endl;
    }
}