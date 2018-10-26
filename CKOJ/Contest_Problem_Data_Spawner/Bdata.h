#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int T=1000,a,b,c,d,e,f,x=now_data_num<4?8:100;
	printf("%d\n",T);
	printf("1 0 0 0 1 0\n");
	printf("1 0 0 1 0 0\n");
	printf("1 0 0 0 0 1\n");
	printf("1 1 1 1 1 1\n");
	printf("1 2 3 3 2 1\n");
	for(int i=6;i<=T;++i){
		int a=random(1,x),b=random(1,x-a),c=x-a-b,d=random(1,x),e=random(1,x-d),f=x-d-e;
		printf("%d %d %d %d %d %d\n",a,b,c,d,e,f);
	}
	return 0;
}
