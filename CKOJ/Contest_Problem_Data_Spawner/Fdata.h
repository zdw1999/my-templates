#include <bits/stdc++.h>
#define ll long long
int main(){

	int n=now_data_num<4?3000:200000,Q=n;
	printf("%d %d\n",n,Q);
	for(int i=1;i<=n;++i)putchar('0'+(rand()&1)); puts("");
	for(int i=1;i<=Q/6;++i)printf("1 %d\n",(int)random(1,15));
	for(int i=1;i<=Q/6;++i)printf("2 %d\n",(int)random(2,15));
	for(int i=1;i<=Q*2/3;++i)printf("%d %d\n",(int)random(1,2),(int)random(1,n));
	return 0;
}
