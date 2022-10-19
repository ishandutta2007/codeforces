#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define PII pair<int,int>
#define fr(i,a,b) for(int i=a;i<=b;i++)
#define fo(i,a,b) for(int i=a;i>=b;i--)
//#pragma GCC optimize(2)
/*inline int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {
        if(ch == '-') f = -1;
        ch = getchar();
    } while('0' <= ch && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    } return x * f;
}*/
int t,n,k;
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&k);//
        int sum=0,l,r;//sum
        fo(i,n-1,1){//l
            sum+=n-i;//n-ilr
            if(sum>=k) {//kli
                sum-=n-i;//t
                l=i;//l
                r=n-(k-sum)+1;//r
                break;//
            }
        }
        fr(i,1,n){//
            if(i==l||i==r) printf("b");
            else printf("a");
        }
        cout<<endl;
    }
    return 0;
}