#include<iostream>
#include<conio.h>
#include <memory>

using namespace std;

class OwnedString {

public :
	char* str;
	int len;


	OwnedString ()
	{

		this->str=0;
		this->len;
	} ;

	//Deep copy of char*

	OwnedString (char* newstr,int length)
	{

		this->len=length;
		this->str = new char[length];
		int i=0;
		while( i<length)
		{
			*(this->str+i)=newstr[i];
			i++;
		}
	//delete[] newstr;
	};


	//Shallow copy
	OwnedString ( OwnedString& newstr)
	{
		this->str=newstr.str;
		this->len=newstr.len;
		newstr.~OwnedString();

	};


	~OwnedString()
	{
	//	delete[] this;
	};



	//Deep Copy of OwnedString
	void equals ( OwnedString& newstr)
	{

		this->str = new char[newstr.len];
		this->len = newstr.len;
		OwnedString(newstr.str,newstr.len);
		newstr.~OwnedString();
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
		//	delete[] this->str;
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

