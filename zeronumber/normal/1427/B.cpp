#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+11;
const int M=1000000007;
int n,k,_,tot;
char s[maxn];
int main(){
    cin >> _;
    while (_--){
        cin >> n >> k;
        scanf("%s",s+1); tot=0;
        for (int i=1;i<=n;i++) tot+=s[i]=='W';
        if (tot==0){
            printf("%d\n",max(0,k*2-1));
        } else if (tot+k>n){
            printf("%d\n",n*2-1);
        } else {
            vector<int> r; r.clear();
            int score=0,last=-1;
            for (int i=1;i<=n;i++){
                if (s[i]=='W') {
                    score+=1+(s[i-1]=='W');
                    if (last!=-1&&last!=i-1) r.pb(i-last-1);
                    last=i;
                }
            }
            sort(r.begin(),r.end());
            int m=r.size(),p=0;
            score+=k*2;
            while (p<m&&k>=r[p]) score++,k-=r[p],p++;
            printf("%d\n",score);
        }
    }
    return 0;
}