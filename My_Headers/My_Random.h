#ifndef MY_RANDOM_H
#define MY_RANDOM_H

	namespace zdw{

		/******************************************

			Don't use this(__random) namespace.

		******************************************/

		namespace __random{

			const unsigned a=1664525;
			const unsigned c=1013904223;

			unsigned random_seed=2333,random_seed2=23333;
			unsigned Random(unsigned &x){return x=a*x+c;}
			unsigned Random(){return Random(random_seed);}
			unsigned Random2(){return Random(random_seed2);}

		};

		void set_rand_seed(const unsigned &x){__random::random_seed=x;}
		void set_rand_seed2(const unsigned &x){__random::random_seed2=x;}
		unsigned random(){return __random::Random();}
		//unsigned random(const unsigned &l,const unsigned &r){return __random::Random()%(r-l+1)+l;}
		//unsigned random(const int &l,const int &r){return random((unsigned)l,(unsigned)r;}
		unsigned long long random(const unsigned long long &l,const unsigned long long &r){return ((unsigned long long)__random::Random()<<32|(unsigned long long)__random::Random2())%(r-l+1)+l;}

	};

#endif
