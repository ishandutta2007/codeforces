#include <stdio.h>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;
int head[501];
int last[501];
int f[501];
vector <pair<char, int> > s[501];
int a[501];
int b[501];
int n, k;
bool check(int l, int r, int ch){
    if(l==r) return 1;
    deque <int> dq;
    for(int i=l; i<=r; i++){
        dq.push_back(a[i]);
    }
    int amax=*max_element(a+l, a+r+1);
    int amin=*min_element(a+l, a+r+1);
    if(amax==amin) return 0;
    int x=r-l;
    int cp;
    for(int i=0; i<=x; i++){
        if(dq[i]==amax){
            if(i>0)
                if(dq[i-1]<dq[i]){
                    cp=i-1;
                    s[ch].push_back(make_pair('L', i+1));
                    dq.pop_front();
                    break;
                }
            if(i<x)
                if(dq[i+1]<dq[i]){
                    cp=i;
                    s[ch].push_back(make_pair('R', i+1));
                    dq.pop_back();
                    break;
                }
        }
    }
    while(dq.size()>1){
        if(cp<dq.size()-1){
            s[ch].push_back(make_pair('R', cp+1));
            dq.pop_back();
        }
        else{
            s[ch].push_back(make_pair('L', dq.size()));
            dq.pop_back();
        }
    }
    return 1;
}
int main(){
    //freopen("C.INP", "r", stdin);
    scanf("%i", &n);
    for(int i=1; i<=n; i++)
        scanf("%i", &a[i]);
    scanf("%i", &k);
    for(int i=1; i<=k; i++)
        scanf("%i", &b[i]);
    int cur=0;
    int j=1;
    head[1]=1;
    for(int i=1; i<=n; i++){
        cur+=a[i];
        if(j>k){
            printf("NO");
            return 0;
        }
        else if(cur==b[j]){
            last[j]=i;
            head[j+1]=i+1;
            j++;
            cur=0;
        }
        else if(cur>b[j]||i==n&&cur<b[j]){
            printf("NO");
            return 0;
        }
    }
    if(j<=k){
            printf("NO");
            return 0;
        }
    for(int i=1; i<=k; i++){
        if(!check(head[i], last[i], i)){
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    for(int i=1; i<=k; i++){
        for(int j=0; j<s[i].size(); j++)
            printf("%d %c\n", i-1+s[i][j].second, s[i][j].first);
    }
}