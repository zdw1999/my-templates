#include <bits/stdc++.h>
#define ll long long

char w[]="{[(";
char w2[]="}])";
char s[100005]; int t=0;

void make_ok(int n,int z){
	n-=(n&-n);
	t=0;
	for(int i=1,c=0;c<n/2;++i){
		int x=random(1,100);
		if(!t)x=0;
		if(x>90){
			int p=min(t,(int)random(1,z));//num
			while(p--)putchar(s[t--]);
		} else {
			int ch=random(0,2);
			putchar(w[ch]);
			s[++t]=w2[ch]; ++c;
		}
	}
	while(t)putchar(s[t--]);
}

void make_random(int n){
	while(n--){
		int z=random(0,2);
		int e=random(0,9);
		putchar(e&1?w[z]:w2[z]);
	}
}

int main(){

	int nd=now_data_num;
	if(nd<=4){
		if(nd&1)make_random(10);
		else make_ok(10,2);
	}else if(nd<=8){
		if(nd&1)make_random(1000);
		else make_ok(1000,10);
	}else if(nd<=12){
		if(nd&1)make_random(100000);
		else make_ok(100000,100);
	}
}
