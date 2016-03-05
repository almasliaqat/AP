#include<iostream>
#include<conio.h>
#include <memory>

using namespace std;




class RefLinkString {

public :
	char* str;
	int len;

	RefLinkString* next;
	RefLinkString* last;

	RefLinkString ()
	{

		this->str=0;
		this-> len;

		this->next=NULL;
		this->last=NULL;
	} ;

	//Deep copy of char*

	RefLinkString (char* newstr,int length)
	{

		this->len=length;
		this->str = new char[length];
		int i=0;
		while( i<length)
		{
			*(this->str+i)=newstr[i];
			i++;
		}


	};


	//Shallow copy
	RefLinkString ( RefLinkString& newstr)
	{
		this->str=newstr.str;
		this->len=newstr.len;
		this->next=&newstr;
		this->last=NULL;
		newstr.last=this;

	};


	~RefLinkString()
	{
		delete[] this;
		if((this->last==NULL) && (this->next==NULL) )
		{
			delete[] this;
		}
		else
		{
			this->next->last=this->last;
			this->last->next=this->next;
		}
	};



	//Deep Copy of OwnedString
	void equals ( RefLinkString& newstr)
	{

		this->str = new char[newstr.len];
		this->len = newstr.len;
		RefLinkString(newstr.str,newstr.len);

	};


	void revSmartCopy(char* newString) {
		int it = 0;
		while (it < this->len) {
			newString[it] = this->str[it];
			it++;
		}
	};

	void reserve(int n) {
		if (this->len < n) {
			int newlength = n; //max(_length*2,n);
			char* newbuf = new char[newlength];
			//copy contents of the stored string in the new buffer
			this->revSmartCopy(newbuf);

			//return stuff from the new buffer to the stored buffer
				delete[] this->str;
			this->str = newbuf;
			this->len = newlength;
		}
	};


	char charAt (int index) 
	{
		if (index < this->len) {
			return this->str[index];
		} else {
			cout<<" IndexOutOfBoundException() ";
		}

	};


	void append(char c) {
		this->str[this->len] = c;
		this->len++;
	}


} ;

