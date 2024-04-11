#include<bits/stdc++.h>
using namespace std;
#define re register int
#define Fr(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline int
typedef long long ll;
I read(int &res){
	re g=1;register char ch=getchar();res=0;
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
ch=getchar();
	}
	while(isdigit(ch)){
	res=(res<<3)+(res<<1)+(ch^48);;
	ch=getchar();
	}
	res*=g;
}
char c[101000];
int n,m,v[20];
int main(){
    read(n);
    scanf("%s",c+1);
    Fr(i,1,n){
        if(c[i]=='L'){
            Fr(j,1,10){
                if(!v[j]){
                    v[j]=1;
                    break;
                }
            }
        }
        else if(c[i]=='R'){
            FOR(j,10,1){
                if(!v[j]){
                    v[j]=1;
                    break;
                }
            }
        }
        else{
            m=c[i]-'0'+1;
            v[m]=0;
        }
    }
    Fr(i,1,10){
        cout<<v[i];
    }
	return 0;
}