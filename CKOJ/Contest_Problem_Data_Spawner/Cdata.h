#include <bits/stdc++.h>
#define ll long long

int main(){

	int T=10000; ll x1,x2,y1,y2;
	ll xx=now_data_num<6?10:1e18;
	//errmsg("%lld\n",xx);
	printf("%d\n",T);
	printf("1 1 0 0\n");
	printf("2 2 -2 0\n");
	for(int i=3;i<=T;++i){
		x1=random(0,xx); y1=random(0,xx);
		x2=random(0,xx); y2=random(0,xx);
		if(random()&1)x1*=-1;
		if(random()&1)y1*=-1;
		if(random()&1)x2*=-1;
		if(random()&1)y2*=-1;
		printf("%lld %lld %lld %lld\n",x1,y1,x2,y2);
	}
	return 0;

}
