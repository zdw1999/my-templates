/***************************************

	File_Name: My_console.h
	Date: 2017/11/04
	Auther: zdw1999

***************************************/

#include <conio.h>
#include <windows.h>

#ifndef _MY_CONSOLE_H_
#define _MY_CONSOLE_H_

	typedef COORD CONLOC;

	namespace zdw{
		inline CONLOC getconloc(){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			CONLOC conloc;
			CONSOLE_SCREEN_BUFFER_INFO csbi;
			
			GetConsoleScreenBufferInfo(hout,&csbi);
			conloc.X=csbi.dwCursorPosition.X;
			conloc.Y=csbi.dwCursorPosition.Y;
			
			return conloc;
		}
		inline void setconloc(const CONLOC &conloc){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hout,conloc);
		}
		inline void setconlocx(const int &X){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			CONLOC conloc=getconloc(); conloc.X=X;
			SetConsoleCursorPosition(hout,conloc);
		}
		inline void setconlocy(const int &Y){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			CONLOC conloc=getconloc(); conloc.Y=Y;
			SetConsoleCursorPosition(hout,conloc);
		}
		inline void setconcolor(const int &color){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hout,color);
		}
		inline void setcursor(const bool &show){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			CONSOLE_CURSOR_INFO cursor_info = {1, show}; 
			SetConsoleCursorInfo(hout, &cursor_info);
		}
		inline void conprint(const CONLOC &conloc,const char *s,const int &color){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hout,color);
			SetConsoleCursorPosition(hout,conloc);
			printf("%s",s);
			#ifndef NO_RECOVER_COLOR
				//recover console color to origin
				SetConsoleTextAttribute(hout,0x0f);
			#endif
		}
		inline void conprint(const CONLOC &conloc,const char *s){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hout,conloc);
			printf("%s",s);
		}
		inline void conputchar(const CONLOC &conloc,const char &c,const int &color){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleTextAttribute(hout,color);
			SetConsoleCursorPosition(hout,conloc);
			putchar(c);
			#ifndef NO_RECOVER_COLOR
				//recover console color to origin
				SetConsoleTextAttribute(hout,0x0f);
			#endif
		}
		inline void conputchar(const CONLOC &conloc,const char &c){
			HANDLE hout=GetStdHandle(STD_OUTPUT_HANDLE);
			SetConsoleCursorPosition(hout,conloc);
			putchar(c);
		}
		inline void setconsize(const int &H,const int &W){
			char buf[32];
			sprintf(buf,"mode con cols=%d lines=%d",W,H);
			system(buf);
		}
	};

#endif
