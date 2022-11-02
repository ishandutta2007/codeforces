#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int N=2005;
char s[N],t[N];
int n,tong[N];
void chu(int x){
	//cout<<(s+1)<<" "<<x<<" ";
	reverse(&s[1],&s[n+1]);
	reverse(&s[x+1],&s[n+1]);
   //cout<<(s+1)<<endl;
}
int main(){
   cin>>n;
   scanf("%s%s",s+1,t+1);
   for(int i=n;i;i--){
		tong[s[i]]++; tong[t[i]]--;
		reverse(&t[1],&t[i]);
   }
   for(int i='a';i<='z';i++)if(tong[i]){
   		puts("-1"); return 0;
   }
	cout<<n*3<<endl;
   for(int i=1;i<=n;i++){
		int pos=0;
		for(int j=i;j<=n;j++)if(s[j]==t[i]){
			pos=j; break;
		}
		chu(n-pos); chu(n-(i-1)-(n-pos)); chu(i-1);
		cout<<n-pos<<" "<<n-(i-1)-(n-pos)<<" "<<i-1<<" ";
		//cout<<(s+1)<<" "<<(t+1)<<" "<<pos<<endl;
   }
   //cout<<(s+1)<<endl;
}
/*
AB CDE
DAB CE

E ABCD

DCEAB

BAD CE
bcaabb
bbabca
acbabb
bbacba
*/