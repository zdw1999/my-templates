#include <bits/stdc++.h>
char S[100005],*s,z;

int main(){
	cin>>S;
	for(s=S;*s;++s){
		putchar(*s);
		if( *s==')' && isdigit(s[1]) ||
			isdigit(*s) && s[1]=='(' ||
			*s==')' && s[1]=='(' )
			putchar('*');
	}
}
