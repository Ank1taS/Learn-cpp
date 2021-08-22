//* section 16 challenge
//* implementation file of IPrintable class 
//* provide functionality so all accounts are printable to an ostream using the overloaded insertion operator

#include "IPrintable.h"

// overloaded extraction operator
std::ostream &operator<<(std::ostream &os, const IPrintable &obj) {
    obj.print(os);

    return os;
}
