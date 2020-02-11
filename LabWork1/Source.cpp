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

    std::cout << "char:\t\t" << sizeof(char) << " bytes" << std::endl;
    cout << "char:" << endl;
    showMinMax<char>();

    std::cout << "short:\t\t" << sizeof(short) << " bytes" << std::endl;
    cout << "short:" << endl;
    showMinMax<short>();

    std::cout << "int:\t\t" << sizeof(int) << " bytes" << std::endl;
    cout << "int:" << endl;
    showMinMax<int>();

    std::cout << "long:\t\t" << sizeof(long) << " bytes" << std::endl;
    cout << "long:" << endl;
    showMinMax<long>();

    std::cout << "long long:\t" << sizeof(long long) << " bytes" << std::endl;
    cout << "long long:" << endl;
    showMinMax<long long>();

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