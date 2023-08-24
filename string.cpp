#include "string.h"
#include <cstring>
#include <iostream>
#include <string>

String::String(){
	m_size = 0;
	m_capacity = 0;
	m_ptr = new char[m_capacity];
}



String::String(const char * str) {
	m_size = strlen(str);           
	m_capacity = m_size + 1;      
	m_ptr = new char[m_capacity];  
	for (int i = 0; i < m_size; ++i) {
		m_ptr[i] = str[i];           
		m_ptr[m_size] = '\0';  
	}

}


String::String(const std::string& str) {
	m_size = str.size();
	m_capacity = m_size + 1;
	m_ptr = new char[m_capacity];

	for (int i = 0; i < m_size; ++i) {
		m_ptr[i] = str[i];

	}

	m_ptr[m_size] = '\0';

}


String::String(const String& rhs) {
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;
	m_ptr = new char[rhs.m_size];

	for(int i = 0; i < rhs.m_size; ++i){
		m_ptr[i] = rhs.m_ptr[i];
	}
}

String& String::operator=(const String& rhs) {
	if(this != &rhs){
		m_size = rhs.m_size;
		m_capacity = rhs.m_capacity;
		m_ptr = new char[rhs.m_size];

		for(int i = 0; i < rhs.m_size; ++i){
			m_ptr[i] = rhs.m_ptr[i];
		}
	}
	return *this;
}

String& String::operator+=(const char * ch) {
   int size = strlen(ch);
   if(size == 1){
    this->push_back(ch);
   }else{
    for(int i = 0; i < size; ++i){
     this->push_back(ch);
     ch++;
    }
   }
   return *this;      
}

String& String::operator+=(const String& rhs)  {
    int newSize = m_size + rhs.m_size;
    char* tmpData = new char[newSize + 1];

    for (int i = 0; i < m_size; ++i) {
        tmpData[i] = m_ptr[i];
    }
    for (int i = m_size; i < newSize; ++i) {
        tmpData[i] = rhs.m_ptr[i - m_size];
    }
    tmpData[newSize] = '\0';
    delete[] m_ptr;
    m_ptr = tmpData;
    m_size = newSize;

    return *this;
}

std::ostream& operator<<(std::ostream& os, const String& str) {
	os << str.m_ptr;
	return os;
}

std::istream& operator>>(std::istream& is, String& str) {
	is  >> str.m_ptr;
	return is;
}



String::~String() {
	delete[] m_ptr;
}


int String::size() {
	return m_size;
}

void String::push_back(const char* st) {
	if(m_size == m_capacity){
		m_resize();
	}
	m_ptr[m_size] = *(st);
	++m_size;
}

void String::pop_back() {
	--m_size;
}



void String::clear() {
	m_size = 0;
}

void String::insert(int position, const char * st) {
	if(m_size == m_capacity){
		m_resize();
	}
	for(int i = m_size; i > position; i--){
		m_ptr[i] = m_ptr[i - 1];
	}
	m_ptr[position] = *(st);
	++m_size;
}

char String::front() {
	return m_ptr[0];
}


char String::back() {
	int length = strlen(m_ptr);
	if (length > 0) {
		return m_ptr[length - 1];
	}
	return '\0';

}


void String::print() {
	for(int i = 0; i < m_size; ++i){
		std::cout<<m_ptr[i];
	}
}
