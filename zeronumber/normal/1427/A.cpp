#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1e6+11;
const int M=1000000007;
int a[maxn],n,_;
int main(){
    cin >> _;
    while (_--){
        cin >> n;
        int s=0;
        for (int i=1;i<=n;i++){
            cin >> a[i];
            s+=a[i];
        }
        if (s==0){puts("NO");}
        else if (s>0){
            puts("YES");
            sort(a+1,a+1+n);
            for (int i=n;i;i--) printf("%d ",a[i]);puts("");
        } else {
            puts("YES");
            sort(a+1,a+1+n);
            for (int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
        }
    }
}