#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
using namespace __gnu_pbds;
using namespace std;


int main(){

	//tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>M;
	int T=6;
	int n=now_data_num<6?1e3:1e5,Q=n,QQ=min(10000,Q);
	printf("%d\n",T);
	while(T--){
		printf("%d %d\n",n,Q);
		for(int w=1,L=n/2,R=n/2;w<=Q;++w){
			int l=random(1,n),r=random(l,n);
			if(T==1)l=r=w;
			if(T==2)l=w&1?L--:L,r=w&1?R:R++;
			if(l<=0)l=1; if(r>n)r=n;
			int c=random(1,1e6);
			printf("%d %d %d\n",l,r,c);
		}
		printf("%d\n",QQ);
		for(int i=1;i<=QQ;++i)
			printf(i==QQ?"%d\n":"%d ",(int)random(1,n));
	}
}
