#include<bits/stdc++.h>
using namespace std;
int T,n,m,A[4];
vector<int> Ans;
void solve(){
    // printf("%d %d %d %d\n",A[0],A[1],A[2],A[3]);
    int x=__gcd(__gcd(A[0],A[1]),__gcd(A[2],A[3]));
    for(int i=1;i*i<=x;i++){
        if(x%i!=0) continue;
        Ans.push_back(i);
        Ans.push_back(x/i);
    }
}
int main(){
    scanf("%d",&T);
    while(T--){Ans.clear();
        scanf("%d %d",&n,&m);
        for(int i=0;i<(1<<4);i++){
            A[0]=A[2]=n-2;
            A[1]=A[3]=m-2;
            for(int j=0;j<4;j++){
                if((i>>j)&1) A[j]++;
                else A[(j+1)%4]++;
            }
            solve();
        }sort(Ans.begin(),Ans.end());
        Ans.erase(unique(Ans.begin(),Ans.end()),Ans.end());
        printf("%d ",(int)Ans.size());
        for(auto x:Ans) printf("%d ",x);
        puts("");
    }
    return 0;
}