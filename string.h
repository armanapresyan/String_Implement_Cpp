#include <iostream>

class String{
	public:
		String();
		~String();
		String (const char*);
		String(const String& rhs);
		String(const std::string& str);
		String& operator=(const String& rhs);
		String& operator+=(const char * ch);
		String& operator+=(const String& rhs);
	        friend std::ostream& operator<<(std::ostream& os, const String& str);
	        friend std::istream& operator>>(std::istream& is, String& str);	
	public:
		int size();
		void push_back(const char* st);
		void pop_back();
		void clear();
		char front();
		char back();
		void insert(int position, const char* st);
		void print();

	private:
		int m_size; 
		int m_capacity;
		char* m_ptr;
		void m_resize(){
			m_capacity *= 2;
			char * tmp = new char[m_capacity];
			for(int i = 0; i < m_size; ++i){
				tmp[i] = m_ptr[i];
			}
			delete[] m_ptr;
			m_ptr = tmp;
			tmp = nullptr;
		}

};


