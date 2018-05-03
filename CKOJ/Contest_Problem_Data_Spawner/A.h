#include <bits/stdc++.h>

namespace Solve_A{
	//empty
}

int main(){
	char p[5005];
	char *jp[5005];
	
	scanf("%s",p); getchar();
	
	//init
	for(char *i=p;*i;++i)
		if(*i=='}')
			for(char *j=i;j-->p;)
				if(*j='{'){
					*j='[';
					*i=']';
					jp[j-p]=i+1;
					jp[i-p]=j+1;
					break;
				}
	//RunProgram(p,jp);
	
	int buf[100005],*ptr=buf;
	char *pptr=p;
	memset(buf,0,sizeof(buf));
	
	while(*pptr){
		if(*pptr=='['&&!*ptr){pptr=jp[pptr-p];continue;}
		if(*pptr==']'&&*ptr){pptr=jp[pptr-p];continue;}
		if(*pptr=='?')*ptr=getchar();
		if(*pptr=='<')--ptr;
		if(*pptr=='>')++ptr;
		if(*pptr=='-')--*ptr;
		if(*pptr=='+')++*ptr;
		if(*pptr==':')putchar(*ptr);
		++pptr;
	}
	
	return 0;
}
