#include<iostream>
#include<conio.h>
#include <memory>

using namespace std;




class RefCountString {

public :
	char* str;
	int len;
	int ref_count;

	RefCountString ()
	{

		this->str=0;
		this-> len;
		this->ref_count=1;
	} ;

	//Deep copy of char*

	RefCountString (char* newstr,int length)
	{

		this->len=length;
		this->str = new char[length];
		int i=0;
		while( i<length)
		{
			*(this->str+i)=newstr[i];
			i++;
		}
		this->ref_count=this->ref_count+1;
		ref_count++;

	};


	//Shallow copy
	RefCountString ( RefCountString& newstr)
	{
		this->str=newstr.str;
		this->len=newstr.len;
		this->ref_count=this->ref_count+newstr.ref_count;
		this->ref_count++;

	};


	~RefCountString()
	{
		delete[] this;
		if(this->ref_count==0)
		{
			delete[] this;
		}
	};



	//Deep Copy of OwnedString
	void equals ( RefCountString& newstr)
	{

		this->str = new char[newstr.len];
		this->len = newstr.len;
		RefCountString(newstr.str,newstr.len);
		this->ref_count=this->ref_count+newstr.ref_count;
		this->ref_count++;
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

