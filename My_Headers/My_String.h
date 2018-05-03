/**************************************

	Prog: Class_String
	Time: 2016-12-01
	Auther: zdw1999

**************************************/

#ifndef My_String_H
#define My_String_H

namespace zdw{
	class NormalString{
		
	private:
		char __S[256];
		
	public:
		NormalString(){__S[0]=0;}
		NormalString(char *__str){
			__S[0]=0;
			while(__str[__S[0]])
				__S[__S[0]+1]=__str[__S[0]++];
		}
		char &operator [](int _){return _?__S[_]:__S[1];}
		const char &operator [](int _)const{return _?__S[_]:__S[1];}
		int strsiz(){return __S[0];}
		int strsiz()const{return __S[0];}
		
		NormalString &operator +=(const char &__c){
			__S[int(++__S[0])]=__c;
			return *this;
		}
		NormalString &operator +=(char *__s){
			int t=0;
			while(__s[t])__S[int(++__S[0])]=__s[t++];
			return *this;
		}
		NormalString &operator +=(const NormalString &__suc){
			for(int i=1;i<=__suc.strsiz();i++)__S[int(++__S[0])]=__suc[i];
			return *this;
		}
		NormalString &operator -=(int __len){
			while(__S[0]&&__len--)__S[0]--;
			return *this;
		}
	};
	
	
	NormalString operator +(const NormalString &__pre,const NormalString &__suc){
		NormalString __tmp;
		(__tmp+=__pre)+=__suc;
		return __tmp;
	}
	NormalString operator +(const NormalString &__pre,char *__s){
		NormalString __tmp;
		(__tmp+=__pre)+=__s;
		return __tmp;
	}
	NormalString operator +(char *__s,const NormalString &__pre){
		NormalString __tmp;
		(__tmp+=__s)+=__pre;
		return __tmp;
	}
	NormalString operator +(const NormalString &__pre,const char &__c){
		NormalString __tmp;
		(__tmp+=__pre)+=__c;
		return __tmp;
	}
	NormalString operator +(const char &__c,const NormalString &__pre){
		NormalString __tmp;
		(__tmp+=__c)+=__pre;
		return __tmp;
	}
	bool operator ==(const NormalString &__A,const NormalString &__B){
		if(__A.strsiz()!=__B.strsiz())return 0;
		for(int i=1;i<=__A.strsiz();i++)
			if(__A[i]!=__B[i])return 0;
		return 1;
	}
	bool operator <(const NormalString &__A,const NormalString &__B){
		int siz=__A.strsiz()<__B.strsiz()?__A.strsiz():__B.strsiz();
		for(int i=1;i<=siz;i++)
			if(__A[i]!=__B[i])return __A[i]<__B[i];
		return __A.strsiz()<__B.strsiz();
	}
	bool operator >(const NormalString &__A,const NormalString &__B){
		int siz=__A.strsiz()<__B.strsiz()?__A.strsiz():__B.strsiz();
		for(int i=1;i<=siz;i++)
			if(__A[i]!=__B[i])return __A[i]>__B[i];
		return __A.strsiz()>__B.strsiz();
	}
	
	#define DEFAULT_STRING_SIZE 255
	class UncertainString{
		
	private:
		char *__S; int __strlen;
		
	public:
		UncertainString(){__S=new char[DEFAULT_STRING_SIZE];__S--;__strlen=0;}
		UncertainString(int __len){__S=new char[__len];__S--;__strlen=0;}
		UncertainString(char *__str){
			__strlen=0;
			while(__str[__strlen])__strlen++;
			__S=new char[__strlen]; __S--;
			for(int i=0;i<__strlen;i++)
				__S[i+1]=__str[i];
		}
		void clear(){delete[] __S;}
		char &operator [](int _){return _?__S[_]:__S[1];}
		const char &operator [](int _)const{return _?__S[_]:__S[1];}
		int strsiz(){return __strlen;}
		int strsiz()const{return __strlen;}
		
		UncertainString &operator +=(const char &__c){
			__S[++__strlen]=__c;
			return *this;
		}
		UncertainString &operator +=(char *__s){
			int t=0;
			while(__s[t])__S[++__strlen]=__s[t++];
			return *this;
		}
		UncertainString &operator +=(const UncertainString &__suc){
			for(int i=1;i<=__suc.strsiz();i++)__S[++__strlen]=__suc[i];
			return *this;
		}
		UncertainString &operator -=(int __len){
			while(__strlen&&__len--)__strlen--;
			return *this;
		}
	};
	
	UncertainString operator +(const UncertainString &__pre,const UncertainString &__suc){
		UncertainString __tmp;
		(__tmp+=__pre)+=__suc;
		return __tmp;
	}
	UncertainString operator +(const UncertainString &__pre,char *__s){
		UncertainString __tmp;
		(__tmp+=__pre)+=__s;
		return __tmp;
	}
	UncertainString operator +(char *__s,const UncertainString &__pre){
		UncertainString __tmp;
		(__tmp+=__s)+=__pre;
		return __tmp;
	}
	UncertainString operator +(const UncertainString &__pre,const char &__c){
		UncertainString __tmp;
		(__tmp+=__pre)+=__c;
		return __tmp;
	}
	UncertainString operator +(const char &__c,const UncertainString &__pre){
		UncertainString __tmp;
		(__tmp+=__c)+=__pre;
		return __tmp;
	}
	bool operator ==(const UncertainString &__A,const UncertainString &__B){
		if(__A.strsiz()!=__B.strsiz())return 0;
		for(int i=1;i<=__A.strsiz();i++)
			if(__A[i]!=__B[i])return 0;
		return 1;
	}
	bool operator <(const UncertainString &__A,const UncertainString &__B){
		int siz=__A.strsiz()<__B.strsiz()?__A.strsiz():__B.strsiz();
		for(int i=1;i<=siz;i++)
			if(__A[i]!=__B[i])return __A[i]<__B[i];
		return __A.strsiz()<__B.strsiz();
	}
	bool operator >(const UncertainString &__A,const UncertainString &__B){
		int siz=__A.strsiz()<__B.strsiz()?__A.strsiz():__B.strsiz();
		for(int i=1;i<=siz;i++)
			if(__A[i]!=__B[i])return __A[i]>__B[i];
		return __A.strsiz()>__B.strsiz();
	}
	
	int puts(const NormalString &s){
		for(int i=1;i<=s.strsiz();i++)
			putchar(s[i]);
		putchar('\n');
		return s.strsiz()+1;
	}
	
	int puts(const UncertainString &s){
		for(int i=1;i<=s.strsiz();i++)
			putchar(s[i]);
		putchar('\n');
		return s.strsiz()+1;
	};
};

#endif

