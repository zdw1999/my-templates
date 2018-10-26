/**************************************

	Prog: Class_Hash
	Time: 2017-04-03
	Auther: zdw1999

**************************************/

#ifndef MY_HASH_H

	#define MY_HASH_H

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

	};

#endif

