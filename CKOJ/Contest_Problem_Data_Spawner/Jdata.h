#include <bits/stdc++.h>
#define ll long long

int main(){

	int T=200;
	printf("%d\n",T);
	printf("1 1 1 1 1\n");
	printf("500000 500000 1 1 1\n");
	printf("1 1 200 200 200\n");
	printf("500000 500000 200 200 200\n");
	printf("500000 1 200 200 200\n");
	T-=5;
	for(std::cin>>T;T--;)
		printf("%llu %llu %llu %llu %llu\n",random(1,500000),random(1,500000),random(1,200),random(1,200),random(1,200));

	return 0;
}
