#include<bits/stdc++.h>
#define pb push_back
#define F first
#define S second
using namespace std;
typedef pair<int,int>pi;
typedef long long ll;
const int M=998244353;
const int maxn=1e6+12;
int last[maxn],n,a[maxn];
char s[2];
int main(){
    cin >> n;
    for (int i=1;i<=n*2;i++){
        cin >> s;
        if (s[0]=='-') scanf("%d",&a[i]);
    }
    int sum=0;
    for (int i=1;i<=n*2;i++){
        if (!a[i]) last[sum]=i,sum++;
        else {
            --sum; if (sum<0){puts("NO");return 0;}
            a[last[sum]]=-a[i];
        }
    }
    priority_queue <int> q;
    for (int i=1;i<=2*n;i++){
        if (a[i]<0) q.push(a[i]);
        else {
            int x=-q.top(); q.pop();
            if (a[i]!=x){puts("NO");return 0;}
        }
    }
    puts("YES");
    for (int i=1;i<=2*n;i++) if (a[i]<0) printf("%d ",-a[i]);
    puts("");
    return 0;
}