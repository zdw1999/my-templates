#include <bits/stdc++.h>
using namespace std;

void make_data(int n,int l,int r){
	printf("%d\n",n);
	while(n--)
		printf("%d\n",(int)random(l,r));
}

int main(){
	if(now_data_num<=4){
		if(now_data_num==1)make_data(1000,0,0);
		if(now_data_num==2)make_data(1000,0,999);
		if(now_data_num==3)make_data(1000,999,999);
		if(now_data_num==4)make_data(1000,233,555);
	} else {
		if(now_data_num==5)make_data(100000,0,0);
		if(now_data_num==6)make_data(100000,0,99999);
		if(now_data_num==7)make_data(100000,99999,99999);
		if(now_data_num==8)make_data(100000,23333,71537);
		if(now_data_num>8)make_data(100000,random(0,20000),random(70000,99999));
	}
}
