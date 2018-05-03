#include <bits/stdc++.h>

namespace Solve_B{
	
	int T,ans,x,y;
	
	double abs(double x){return x<0?-x:x;}
	double max(double x,double y){return x>y?x:y;}
	int culc(int x,int y){
		if(x<1||x>10||y<1||y>10)return 0;
		return 5.6-max(abs(x-5.5),abs(y-5.5));
	}
	
	void Solve(){
		for(std::cin>>T,ans=0;T--;)
			scanf("%d%d",&x,&y),ans+=culc(x,y);
		printf("%d\n",ans);
	}
	
}

int main(){
	
	Solve_B::Solve();
	
	return 0;
	
}
