// Frank carpet clining service ====== Ac to course========

#include <iostream>

int main() {
    int smallRoom {}, largeRoom {};
    double cost {};
    const double smallRoomPrice {25}, largeRoomPrice {35}, saleTaxRate {0.06};
    const int estimateExpiry {30};  

    std::cout << "Hello, Welcome to Frank's Carpet Cleaning Service\n\n";
    std::cout << "How many small rooms would you like cleaned?  ";
    std::cin >> smallRoom;
    std::cout << "How many large rooms would you like cleaned?  ";
    std::cin >> largeRoom;

    cost = (smallRoom * smallRoomPrice) + (largeRoom * largeRoomPrice);

    std::cout << "\n\nEstimate for carpet cleaning service";
    std::cout << "\nNumber of small room: " << smallRoom;
    std::cout << "\nNumber of large room: " << largeRoom;
    std::cout << "\nPrice per small room: $" <<  smallRoomPrice;
    std::cout << "\nPrice per large room: $" <<  largeRoomPrice;
    std::cout << "\ncost : $" << cost;
    std::cout << "\ntax: $" << cost * saleTaxRate;
    std::cout << "\n============================================";
    std::cout << "\nTotal estimate: $" << cost + (cost * saleTaxRate);
    std::cout << "\nThis estimate is valid for " << estimateExpiry << " days"<< std::endl;

    return 0;
}