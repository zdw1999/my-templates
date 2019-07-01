/**************************************

	Prog: Class_Hash
	Time: 2017-04-03
	Auther: zdw1999

**************************************/

#ifndef MY_HASH_H

	#define MY_HASH_H
	#include <algorithm>

	namespace zdw{

		template<class __A,class __B>
		class Hash{
		private:
			static const int size=2000000;
			__B *hash; __A *O; int sz;
		public:
			Hash(int hash_size=size){ sz=hash_size;
				hash=(__B *)malloc(sizeof(__B)*sz);
				O=(__A *)malloc(sizeof(__A)*sz);
				memset(O,0xff,sizeof(__A)*sz);
			}~Hash(){free(O);free(hash);}
			__B &operator [](const __A &_O){
				int loc=_O%sz;
				while(~O[loc]&&O[loc]!=_O){
					++loc;
					if(loc>sz)loc=0;
				}if(!~O[loc])O[loc]=_O;
				return hash[loc];
			}
			void clear(){memset(O,0xff,sizeof(__A)*sz);}
		};

		struct StringDoubleHashResult{
			int32_t *H1,*H2,len;
			StringDoubleHashResult(int32_t sz=0){
				len=sz;
				if(len<=0){
					H1=H2=0;
					return;
				}
				H1=(int32_t *)malloc(sizeof(int32_t)*sz);
				H2=(int32_t *)malloc(sizeof(int32_t)*sz);
			}
			~StringDoubleHashResult(){}
			void clear(){free(H1);free(H2);len=0;H1=H2=0;}
		};

		class StringDoubleHash{
		private:
			int32_t sz,HA1,HA2;
			long long B,C;
			int32_t *H1,*H2;
		public:
			StringDoubleHash(int32_t SZ=1e6+5,int32_t ha1=1e9+7,int32_t ha2=1e9+9,int32_t b=23333,int32_t c=893){
				sz=SZ; HA1=ha1; HA2=ha2; B=b; C=c;
				H1=(int32_t *)malloc(sizeof(int32_t)*sz);
				H2=(int32_t *)malloc(sizeof(int32_t)*sz);
				init_hash_val();
			}
			~StringDoubleHash(){free(H1);free(H2);}
			void init_hash_val(){
				H1[0]=H2[0]=1;
				for(int32_t i=1;i<sz;++i){
					H1[i]=(H1[i-1]*B)%HA1;
					H2[i]=(H2[i-1]*B)%HA2;
				}
			}
			template <class _Tp>
			StringDoubleHashResult culc_hash(const _Tp &s,int32_t len){
				StringDoubleHashResult R(len);
				if(len<=0)return R;
				R.H1[0]=R.H2[0]=s[0]+C;
				for(int32_t i=1;i<len;++i){
					R.H1[i]=(R.H1[i-1]*B+s[i]+C)%HA1;
					R.H2[i]=(R.H2[i-1]*B+s[i]+C)%HA2;
				}
				return R;
			}
			ll gethash(const StringDoubleHashResult &R, int32_t l,int32_t r){
				if(l>r)std::swap(l,r);
				if(l<0||r>=R.len||r-l+1>=sz)return -1;//fail
				ll v1=l>0?R.H1[l-1]*(long long)H1[r-l+1]%HA1:0;
				ll v2=l>0?R.H2[l-1]*(long long)H2[r-l+1]%HA2:0;
				v1=(R.H1[r]-v1+HA1)%HA1; v2=(R.H2[r]-v2+HA2)%HA2;
				return v1<<32|v2;
			}
		};

	};

#endif

