#include <bits/stdc++.h>
#define ll long long

std::map<int,bool>M[200005];

int main(){


    int n=199990,m=200000;
    printf("%d %d\n",n,m);
    for(int i=1;i<=m-100;++i){
        int s=random(1,n-100),t=random(1,n-100);
        while(s==t||M[s][t]||M[t][s])
            t=random(1,n-100);
        int v=random(0,0x3fffffff);
        printf("%d %d %d\n",s,t,v);
    }
    for(int i=1;i<=100;++i){
        int s=random(n-99,n),t=random(n-99,n);
        while(s==t||M[s][t]||M[t][s])
            t=random(n-99,n);
        int v=random(0,0x3fffffff)|233;
        printf("%d %d %d\n",s,t,v);
    }
	int T=100000;
	printf("%d\n",T);
	for(int i=1;i<=100;++i){
        int x=random(n-99,n),y=random(n-99,n);
        printf("%d %d\n",x,y);
	}
    T-=100;
	while(T--){
        int x=random(1,n),y=random(1,n);
        printf("%d %d\n",x,y);
	}
	return 0;

}
