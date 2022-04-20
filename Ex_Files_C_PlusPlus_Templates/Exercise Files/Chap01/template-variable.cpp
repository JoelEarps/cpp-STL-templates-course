// template-variable.cpp by Bill Weinman <http://bw.org/>
// created 2018-09-08
#include <iostream>
using namespace std;

//template syntax followed by variable at type T
//template variables are c++14


//lets make this a const expression -available at compile time
//strongly type const even thought template available at compile time
//far more reliable than using pre processor const
template<typename T>
constexpr T pi = T(3.1415926535897932385L);

//so lets create a template function for the area of a cirle

template <typename T>
T area_of_circle( const T & r ){
    //using the type of the template of the function to get that for pi as well i.e. whatever template is for the function 
    //is the what pi will be
    return r * r * pi<T>;
}

int main()
{
    //precision of 20 places for float
    cout.precision(20);
    //so double does not have 20 places
    cout << pi<long double> << " " << area_of_circle<long double>(3)<< endl;
    //so change this to long double - which will provide 20 digits of precision
    //specialisation of the variable of the 
    return 0;
}
