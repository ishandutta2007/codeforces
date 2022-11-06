#include<stdio.h>
#include<stack>
std::stack<int>a;
char c[10000002];
int t,n;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",c+1);
		for(n=1;c[n];n++);
		for(int i=3;c[i]&&i<n;i++){
			if(c[i-2]=='o'&&c[i-1]=='n'&&c[i]=='e')a.push(i-1);
			else if(c[i-2]=='t'&&c[i-1]=='w'&&c[i]=='o'){
				if(c[i+1]=='n'&&c[i+2]=='e')a.push(i),i+=3;
				else a.push(i-1);
			}
		}printf("%d\n",a.size());
		while(!a.empty())printf("%d ",a.top()),a.pop();puts("");
	}
}