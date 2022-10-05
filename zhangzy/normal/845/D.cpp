#include<bits/stdc++.h>
using namespace std;

int n,speed,ans=0,cnt=0,st[233333],top=0;

int main(){
	st[0]=233333;
	scanf("%d",&n);
	for (int x,t;n--;){
		scanf("%d",&t);
		if (t==1){
			scanf("%d",&speed);
		}else if(t==2){
			ans+=cnt;
			cnt=0;
		}else if (t==3){
			scanf("%d",&x);
			st[++top]=x;
		}else if (t==4){
			cnt=0;
		}else if (t==5){
			st[++top]=233333;
		}else if (t==6){
			cnt++;
		}
		while (st[top]<speed){
			ans++;top--;
		}
	}
	cout<<ans;
}