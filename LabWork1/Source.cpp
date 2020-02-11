#include <iostream>
#include <limits>

//Work has been completed by Kapinos Daneel


using namespace std;

//output function
template<typename T>
void showMinMax() {
    cout << "min: " << numeric_limits<T>::min() << endl;
    cout << "max: " << numeric_limits<T>::max() << endl;
    cout << endl;
}

int main()
{
    std::cout << "bool:\t\t" << sizeof(bool) << " bytes" << std::endl;
    cout << "bool:" << endl;
    showMinMax<bool>();

    std::cout << "signed char:\t\t" << sizeof(signed char) << " bytes" << std::endl;
    cout << "signed char:" << endl;
    showMinMax<signed char>();

    std::cout << "unsigned char:\t\t" << sizeof(unsigned char) << " bytes" << std::endl;
    cout << "unsigned char:" << endl;
    showMinMax<unsigned char>();

    std::cout << "char:\t\t" << sizeof(char) << " bytes" << std::endl;
    cout << "char:" << endl;
    showMinMax<char>();

    std::cout << "short:\t\t" << sizeof(short) << " bytes" << std::endl;
    cout << "short:" << endl;
    showMinMax<short>();

    std::cout << "short int:\t\t" << sizeof(short int) << " bytes" << std::endl;
    cout << "short int:" << endl;
    showMinMax<short int>();

    std::cout << "signed short:\t\t" << sizeof(signed short) << " bytes" << std::endl;
    cout << "signed short:" << endl;
    showMinMax<signed short>();

    std::cout << "signed short int:\t\t" << sizeof(signed short int) << " bytes" << std::endl;
    cout << "signed short int:" << endl;
    showMinMax<signed short int>();

    std::cout << "unsigned short:\t\t" << sizeof(unsigned short) << " bytes" << std::endl;
    cout << "unsigned short:" << endl;
    showMinMax<unsigned short>();

    std::cout << "unsigned short int:\t\t" << sizeof(unsigned short int) << " bytes" << std::endl;
    cout << "unsigned short int:" << endl;
    showMinMax<unsigned short int>();

    std::cout << "int:\t\t" << sizeof(int) << " bytes" << std::endl;
    cout << "int:" << endl;
    showMinMax<int>();

    std::cout << "signed:\t\t" << sizeof(signed) << " bytes" << std::endl;
    cout << "signed:" << endl;
    showMinMax<signed>();

    std::cout << "signed int:\t\t" << sizeof(signed int) << " bytes" << std::endl;
    cout << "signed int:" << endl;
    showMinMax<signed int>();

    std::cout << "unsigned:\t\t" << sizeof(unsigned) << " bytes" << std::endl;
    cout << "unsigned:" << endl;
    showMinMax<unsigned>();

    std::cout << "unsigned int:\t\t" << sizeof(unsigned int) << " bytes" << std::endl;
    cout << "unsigned int:" << endl;
    showMinMax<unsigned int>();

    std::cout << "long:\t\t" << sizeof(long) << " bytes" << std::endl;
    cout << "long:" << endl;
    showMinMax<long>();

    std::cout << "long int:\t\t" << sizeof(long int) << " bytes" << std::endl;
    cout << "long int:" << endl;
    showMinMax<long int>();

    std::cout << "signed long:\t\t" << sizeof(signed long) << " bytes" << std::endl;
    cout << "signed long:" << endl;
    showMinMax<signed long>();

    std::cout << "signed long int:\t\t" << sizeof(signed long int) << " bytes" << std::endl;
    cout << "signed long int:" << endl;
    showMinMax<signed long int>();

    std::cout << "unsigned long:\t\t" << sizeof(unsigned long) << " bytes" << std::endl;
    cout << "unsigned long:" << endl;
    showMinMax<unsigned long>();

    std::cout << "unsigned long int:\t\t" << sizeof(unsigned long int) << " bytes" << std::endl;
    cout << "unsigned long int:" << endl;
    showMinMax<unsigned long int>();

    std::cout << "long long:\t" << sizeof(long long) << " bytes" << std::endl;
    cout << "long long:" << endl;
    showMinMax<long long>();

    std::cout << "long long int:\t\t" << sizeof(long long int) << " bytes" << std::endl;
    cout << "long long int:" << endl;
    showMinMax<long long int>();

    std::cout << "signed long long:\t\t" << sizeof(signed long long) << " bytes" << std::endl;
    cout << "signed long long:" << endl;
    showMinMax<signed long long>();

    std::cout << "signed long long int:\t\t" << sizeof(signed long long int) << " bytes" << std::endl;
    cout << "signed long long int:" << endl;
    showMinMax<signed long long int>();

    std::cout << "unsigned long long:\t\t" << sizeof(unsigned long long) << " bytes" << std::endl;
    cout << "unsigned long long:" << endl;
    showMinMax<unsigned long long>();

    std::cout << "unsigned long long int:\t\t" << sizeof(unsigned long long int) << " bytes" << std::endl;
    cout << "unsigned long long int:" << endl;
    showMinMax<unsigned long long int>();

    std::cout << "float:\t\t" << sizeof(float) << " bytes" << std::endl;
    cout << "float:" << endl;
    showMinMax<float>();

    std::cout << "double:\t\t" << sizeof(double) << " bytes" << std::endl;
    cout << "double:" << endl;
    showMinMax<double>();

    std::cout << "long double:\t" << sizeof(long double) << " bytes" << std::endl;
    cout << "long double:" << endl;
    showMinMax<long double>();
    
    return 0;
}