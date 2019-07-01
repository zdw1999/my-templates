#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int nd=now_data_num;
	if(nd<=8){
		if(nd==1)printf("1 0\n");
		if(nd==2)printf("2 0\n");
		if(nd==3)printf("2 1\n");
		if(nd==4)printf("2 2\n");
		if(nd==5)printf("2 3\n");
		if(nd==6)printf("3 8\n");
		if(nd>6){
			ll n=random(1,100);
			ll x=random(0,n*n-1);
			printf("%lld %lld\n",n,x);
		}
	}else if(nd<=14){
		ll n=random(50000,100000);
		ll x=random(0,n*n-1);
		printf("%lld %lld\n",n,x);
	}else if(nd<=20){
		ll n=random(5e8,1e9);
		ll x=random(0,n*n-1);
		printf("%lld %lld\n",n,x);
	}
	return 0;

}
