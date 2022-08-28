#ifndef VSTRING_H_INCLUDED
#define VSTRING_H_INCLUDED

#ifdef __cplusplus

#include <stdlib.h>
#include <string.h>

void * operator new(size_t size) {
	return malloc(size);
}
void * operator new [](size_t size) {
	return malloc(size);
}
void operator delete(void * ptr) {
	free(ptr);
}
void operator delete[](void * ptr) {
	free(ptr);
}

//Types lenght
#define LONG_LONG_LENGHT 20
#define INT_LENGHT 10
#define SHORT_LENGHT 5
#define CHAR_LENGHT 3

class vstring {
protected:
	char* value;
public:
	//Constructors
	vstring(const char* input) {
		this->value = (char*)input;
	}
	vstring(char* input) {
		this->value = input;
	}
	vstring() {
		this->value = (char*)"";
	}
	//Destructor
	~vstring() {};

	//Operators
	operator char* () const {
		return this->value;
	}

	// "="
	void operator = (const char * input) {
		this->value = (char * ) input;
	}
	void operator = (char * input) {
		this->value = input;
	}
	void operator = (int32_t input) {
		char* buff = new char[INT_LENGHT];
		buff = (char*)"";
		itoa(input, buff, INT_LENGHT);
		this->value = buff;
		delete[] buff;
	}
	void operator = (uint32_t input) {
		char* buff = new char[INT_LENGHT];
		buff = (char*)"";
		itoa(input, buff, INT_LENGHT);
		this->value = buff;
		delete[] buff;
	}
	void operator = (int64_t input) {
		char * buff = new char[LONG_LONG_LENGHT];
		buff = (char*)"";
		ltoa(input, buff, LONG_LONG_LENGHT);
		this->value = buff;
		delete[] buff;
	}
	void operator = (uint64_t input) {
		char * buff = new char[LONG_LONG_LENGHT];
		buff = (char*)"";
		ltoa(input, buff, LONG_LONG_LENGHT);
		this->value = buff;
		delete[] buff;
	}
	void operator = (int16_t input) {
		char * buff = new char[SHORT_LENGHT];
		buff = (char*)"";
		ltoa(input, buff, SHORT_LENGHT);
		this->value = buff;
		delete[] buff;
	}
	void operator = (uint16_t input) {
		char * buff = new char[SHORT_LENGHT];
		buff = (char*)"";
		ltoa(input, buff, SHORT_LENGHT);
		this->value = buff;
		delete[] buff;
	}
	// "+"
	char* operator + (const char * input) {
		char * buff = new char[strlen(input) + strlen(value) + 1];
		strcpy(buff, value);
		strcat(buff, input);
		return buff;
		delete[] buff;
	}
	char* operator + (char * input) {
		char * buff = new char[strlen(input) + strlen(value) + 1];
		strcpy(buff, value);
		strcat(buff, input);
		return buff;
		delete[] buff;
	}
	char* operator + (int input) {
		char * buff = new char[20 + strlen(value) + 1];
		char * buff2 = new char[20];
		strcpy(buff, value);
		strcat(buff, itoa(input, buff2, 10));
		delete[] buff2;
		return buff;
		delete[] buff;
	}
	char* operator + (int input) {
		char * buff = new char[20 + strlen(value) + 1];
		char * buff2 = new char[20];
		strcpy(buff, value);
		strcat(buff, itoa(input, buff2, 10));
		delete[] buff2;
		return buff;
		delete[] buff;
	}

	// "+="
	void operator += (const char * input) {
		char * buff = new char[strlen(input) + strlen(value) + 1];
		strcpy(buff, value);
		strcat(buff, input);
		this -> value = buff;
		delete[] buff;
	}

	//Funcs
	int size() {
		return strlen(this -> value);
	}
	int lenght() {
		return strlen(this -> value);
	}
};

#endif

#endif // VSTRING_H_INCLUDED
