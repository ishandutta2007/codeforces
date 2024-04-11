#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n, m ,k, ans=0;
int c[200001], l, r;
int s[200001];
vector <int> v[200001];
int fset(int u){
    if(s[u]<0) return u;
    return s[u]=fset(s[u]);
}
int uni(int u, int v){
    int s1=fset(u), s2=fset(v);
    if(s1!=s2){
        if(s[s1]>s[s2])
            swap(s1, s2);
        s[s1]+=s[s2];
        s[s2]=s1;
    }
}
int main(){
    scanf("%i%i%i", &n, &m, &k);
    for(int i=1; i<=n; i++){
        scanf("%i", &c[i]);
        s[i]=-1;
    }
    for(int i=1; i<=m; i++){
        scanf("%i%i", &l, &r);
        uni(l, r);
    }
    for(int i=1; i<=n; i++)
        v[fset(i)].push_back(c[i]);
    for(int i=1; i<=n; i++)
        if(v[i].size()>1){
            sort(v[i].begin(), v[i].end());
            int cnt=1, maxcnt=0;
            for(int j=1; j<v[i].size(); j++){
                if(v[i][j]==v[i][j-1])
                    cnt++;
                else{
                    maxcnt=max(maxcnt, cnt);
                    cnt=1;
                }
            }
            maxcnt=max(maxcnt, cnt);
            ans+=v[i].size()-maxcnt;
        }
    printf("%d\n", ans);
}