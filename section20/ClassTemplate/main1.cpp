// Class Templates

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

template <typename T1, typename T2>
class Massage {
private:
    // attribute
    T1 massage;
    T2 value;

public:
    // default constructor
    Massage(T1 massage, T2 value)
        : massage {massage}, value {value} {}

    // destructor
    ~Massage() {}

    // getters
    T1 getMassage() {
        return massage;
    }

    T2 getValue() {
        return value;
    }
};

int main() {
    std::cout << "==================================\n" << std::endl;

    Massage<std::string, int> personMsg1 {"Frank", 48};
    std::cout << personMsg1.getMassage() << " " << personMsg1.getValue() << std::endl;

    std::cout << "==================================\n" << std::endl;

    Massage<std::string, std::string> welcomeMsg {"Hello World!", "Ammy"};
    std::cout << welcomeMsg.getMassage() << " " << welcomeMsg.getValue() << std::endl;

    std::cout << "==================================\n" << std::endl;
    
    Massage<std::string, Massage<std::string, double>> accMsg {"Jhon", {"account balance", 65800.57}};
    std::cout << std::fixed << std::setprecision(3) << accMsg.getMassage() << " " 
                                                    << accMsg.getValue().getMassage() << " " 
                                                    << accMsg.getValue().getValue() << std::endl;

    std::cout << "==================================\n" << std::endl;

    std::vector<Massage<std::string, int>> personVec;

    Massage<std::string, int> personMsg2 {"Ammy", 20};
    Massage<std::string, int> personMsg3 {"Lee ", 30};
    Massage<std::string, int> personMsg4 {"Harshy", 32};

    personVec.push_back(personMsg1);
    personVec.push_back(personMsg2);
    personVec.push_back(personMsg3);
    personVec.push_back(personMsg4);

    for (auto &obj : personVec) {
        std::cout << obj.getMassage() << " " << obj.getValue() << std::endl;
    }

    return 0;
}
