 #include<bits/stdc++.h>
 using namespace std;
 int main(){
 	int ans=1;
 	int a,b,c;
 	scanf("%d%d%d",&a,&b,&c);
 	ans=a;
 	ans=min(ans,b-1);
 	ans=min(ans,c-2);
 	printf("%d",ans*3+3);
 }