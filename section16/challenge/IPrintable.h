//* section 16 challenge
//* header file of IPrintable class
//* provide functionality so all accounts are printable to an ostream using the overloaded insertion operator


#ifndef _IPRINTABLE_H_
#define _IPRINTABLE_H_

#include <iostream>

// Interface
class IPrintable {

    // overloaded extraction operator
    friend std::ostream &operator<<(std::ostream &, const IPrintable &);

public:
    virtual void print(std::ostream &) const = 0;       // pure virtual print()
    virtual ~IPrintable() = default;                    // virtual destructor

};

#endif
