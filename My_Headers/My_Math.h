/****************************************

	Math templates.

	Last_update: 2018-01-24 14:35

*****************************************/

#ifndef MY_MATH_H
#define MY_MATH_H

	#include <cmath>
	#include <My_Std.h>

	#ifndef ll
	# define ll long long
	#endif

	#ifndef ull
	# define ull unsigned long long
	#endif

	namespace zdw{

		inline ll gcd(ll a,ll b){for(ll c;c=b;){b=a%c;a=c;}return a;}
		//inline ll mul(const ll &x,const ll &y,const ll &z){return x*y-(ll)(x/(long double)z*y+1e-3)*z;}//O(1) mul
		inline ull mul(ull a,ull b,const ull &p){ull ret=0;a%=p;do{if(b&1)ret=a+ret-(a<p-ret?0:p);}while((b>>=1)&&(a=(a<<1)-(a<p-a?0:p)));return ret;}
		inline ll pow(ull a,ull b,const ull &p){ll ret=1;do{if(b&1)ret=mul(ret,a,p);a=mul(a,a,p);}while(b>>=1);return ret;}
		inline ll exgcd(const ll &a,const ll &b,ll &x,ll &y){return b?exgcd(b,a%b,y,x)+(y-=a/b*x)-y:(x=1,y=0,a);}//ax-by=1


		#ifndef __NO_PRIME_LIST__

			#ifndef PRIME_LIST_LIMIT
			# define PRIME_LIST_LIMIT 4000
			#endif

			#if PRIME_LIST_LIMIT>10000000
			# undef PRIME_LIST_LIMIT
			# define PRIME_LIST_LIMIT 10000000
			#endif

			class __prime_list{
			private:
				bool *isp;
			public:
				inline __prime_list(int t=PRIME_LIST_LIMIT+1){
					isp=(bool *)malloc(t*sizeof(bool));
					memset(isp,1,t*sizeof(bool));
					isp[0]=isp[1]=0; int tmp=sqrt(t);
					rep(i,2,tmp)if(isp[i])
						dep(j,t/i,1)isp[i*j]=0;
				}
				inline const bool &operator [](const int &x){return isp[x];}
			}__Prime_List;

		#endif

		#define CHECK_TIMES 20
		bool isp(const ll &n){
		#ifndef __NO_PRIME_LIST__
			if(n<PRIME_LIST_LIMIT)return __Prime_List[n];
			// n > PRIME_LIST_LIMIT using Miller Robin
		#endif
			if(n<2||!(n&1))return n==2;
			ll a,x=1,y,u=n-1,tt; int t=0,i=CHECK_TIMES+1,j;
			while(!(u&1))++t,u>>=1;
			while(j=t+1,x==1&&--i){
				a=random(2,n-1); tt=pow(a,u,n);
				while(x=tt,--j)if((tt=mul(x,x,n))==1&&x!=1&&x!=n-1)return 0;
				if(x!=1)return 0;
			} return 1;
		}
		#undef CHECK_TIMES

		void factorize(const ll &n,ll *ans,int &tot){
			if(isp(n)){ans[tot++]=n;return;}
			ll x,y,z,d; int i,j;
			while(y=x=((ll)rand()*rand()%(n-1)+1),i=j=2)do{
				x=(mul(x,x,n)+1)%n;
				z=abs(x-y); d=gcd(z,n);
				if(d>1&&d<n){factorize(d,ans,tot);factorize(n/d,ans,tot);return;}
				if(x==y) break; if(i==j)y=x,j<<=1;
			}while(++i);
		}

		int eular(const ll &n,ll *ans){//primes that < n
			bool *isp=(bool *)malloc(n*sizeof(bool));
			memset(isp,1,n*sizeof(bool));
			int tot=isp[0]=isp[1]=0;
			rep(i,2,n){
				if(isp[i])ans[tot++]=i;
				rep(j,0,tot)if((ll)i*ans[j]<n){
					isp[i*ans[j]]=0;
					if(i%ans[j]==0)break;
				}
			} free(isp); return tot;
		}

	};

#endif




