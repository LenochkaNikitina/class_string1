#include <iostream>
using namespace std;

class String {
protected:
    char* _str;
    int _length;

public:
    String(){
    }

    String(const char* str) {
        _length = strlen(str) + 1;
        _str = new char[_length];
        strcpy_s(_str, _length, str);
        
    }

    String(const String& other) {
        _str = new char[other._length+1];
        strcpy_s(this->_str, other._length+1, other._str);
        this->_length = other._length;
    }

    ~String() {
        delete[] _str;
    }

    int Get_length() {
        return _length;
    }

    void Clear() {
        _length = 0;
        _str[0] = '\0';
    }

    String operator+(const String& right) {
        String temp;
        temp._length = this->_length + right._length + 1;
        temp._str = new char[temp._length];

        for (int i = 0; i < this->_length; i++) {
            temp._str[i] = right._str[i];
        }

        int ind;
        for (int i = 0; i < right._length; i++) {
            ind = i + this->_length - 1;
            temp._str[ind] = right._str[i];
        }

        return temp;
    }

    bool operator==(const String& right) {
        if (this->_length != right._length)
            return false;

        for (int i = 0; i < this->_length; i++) {
            if (this->_str[i] != right._str[i])
                return false;
        }

        return true;
    }

    void print() {
        cout << _str << endl;
    }
};

class Bit_string : public String{
   
public:
    Bit_string() : String(){
       
    }

    Bit_string(const char* str) : String(str){
        for (int i = 0; i < _length-1; i++) {
            if (_str[i] != '1' && _str[i] != '0') {
                _str[0] = '\0';
                _length = 0;
                break;
            }
                
        }
    }

    Bit_string(Bit_string& other) : String(other){}

    ~Bit_string() {}

    void Additional_code() {
        for (int i = 0; i < _length - 1; i++) {
            if (_str[i] == '0')
                _str[i] = '1';
            else
                _str[i] = '0';
        }

        for (int i = _length - 2; i >= 0; i--) {
            if (_str[i] == '0') {
                _str[i] = '1';
                break;
            }
            else {
                _str[i] = '0';
            }       
        }
    }
    
    Bit_string operator+(const Bit_string& right ) {
        Bit_string temp;
        temp._length = this->_length + right._length + 1;
        temp._str = new char[temp._length];

        for (int i = 0; i < this->_length; i++) {
            temp._str[i] = right._str[i];
        }

        int ind;
        for (int i = 0; i < right._length; i++) {
            ind = i + this->_length - 1;
            temp._str[ind] = right._str[i];
        }

        return temp;
    }
    
    bool operator==(const Bit_string& right) {
        if (this->_length != right._length)
            return false;

        for (int i = 0; i < this->_length; i++) {
            if (this->_str[i] != right._str[i])
                return false;
        }

        return true;
    }
};

int main() {
    setlocale(0, "rus");

    String str("Hello");
    cout << "Первая строка : " << endl;
    str.print();

    String str1(str);
    cout << "Копия строки: " << endl;
    str1.print();
    
    if (str == str1)
        cout << "Строки равны" << endl;
    else
        cout << "Строки не равны" << endl;

    cout << "Длина первой строки: " << str.Get_length() << endl
        << "Длина второй строки: " << str1.Get_length() << endl;

    String str3 = str + str1;
    cout << "Конкатенация: " << endl;
    str3.print();

    str1.Clear();
    cout << "Метод Clear" << endl;
    str1.print();

    if (str == str1)
        cout << "Строки равны" << endl;
    else
        cout << "Строки не равны" << endl;

    Bit_string bit_s("0010101");
    cout << "Битовая строка:" << endl;
    bit_s.print();

    Bit_string bit_s1(bit_s);
    cout << "Копия битовой строки:" << endl;
    bit_s1.print();

    Bit_string bit_s2 = ("110110010");
    bit_s2.Additional_code();
    cout << "Битовая строка в дополнительном коде:" << endl;
    bit_s2.print();

    Bit_string bit_s3 = bit_s1 + bit_s2;

    if (bit_s == bit_s1)
        cout << "Строки равны" << endl;
    else
        cout << "Строки не равны" << endl;

    return 0;
}

