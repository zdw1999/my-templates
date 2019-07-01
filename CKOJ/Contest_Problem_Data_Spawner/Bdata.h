#include <bits/stdc++.h>
#define ll long long
using namespace std;

char s[105];

void make_string(char *s,int len){
	for(int i=0;i<len;++i)
		s[i]='a'+random(0,25);
	s[len]=0;
}

int main(){
	int n=100;
	printf("%d\n",n);
	make_string(s,100);
	while(n--){
		if(random(1,100)>93)make_string(s,100);
		printf("%s\n",s);
	}
	return 0;
}
