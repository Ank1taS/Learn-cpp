// section challenge 3 - maps

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <set>
#include <map>

// cleanString() - removes periods, commas, semicolons and colon in a string and returns the clean version
std::string cleanString(const std::string &str) {
    std::string resultStr;

    for (auto ch: str) {
        if (ch == '.' || ch == ',' || ch == ':' || ch == ';' || ch == '!' || ch == '?') {
            continue;
        }
        else {
            resultStr += ch;            // concart string
        }
    }

    return resultStr;
}

// display() - part1()   
// to display word and the count from the std::map<std::string, int> 
void display(const std::map<std::string, int> &wordPair) {
        std::cout << std::setw(12) << std::left << "\nWord"
                  << std::setw(7) << std::right << "Count"<< std::endl;
        std::cout << "===================" << std::endl;

        for (auto pair: wordPair) {
            std::cout << std::setw(12) << std::left << pair.first 
                      << std::setw(7)  << std::left << pair.second << std::endl;
        }
}

// Part1 - process the file and builds a map of words and the number of times they occur in the file
void part1() {
    std::map<std::string, int> wordFinal;
    std::string wordExtract;
    std::string line;
    std::ifstream file{"words.txt"};

    // checks file availability
    if (file.is_open()) {
        // read each line from the file
        while (std::getline(file, line)) {
            line = cleanString(line);       // to get cleaner version of the string line

            // extracting words from the string line using istringstream class object iss
            std::istringstream iss(line);

            // storing each extracted word in map one by one
            while (iss >> wordExtract) {
                wordFinal[wordExtract] += 1;
                // wordFinal[wordExtract]++;
                // ++wordFinal[wordExtract];
            }
        }

        file.close();
        display(wordFinal);
    }
    else {
        std::cout << "Error opening input file..." << std::endl; 
    }
}

// display() - part1()   
// to display word and the count from the std::map<std::string, int> 
void display(std::map<std::string, std::set<int>> &wordPair) {
    std::cout << std::setw(12) << std::left << "\nWord"
              << std::setw(7) << std::right << "Count"<< std::endl;

    std::cout << "==============================================\n" << std::endl;

    for (auto pair: wordPair) {
        std::cout << std::setw(12) << std::left << pair.first;
        std::cout << " [ ";

        for (auto value: pair.second) {
            std::cout << value << "  ";
        }
        std::cout << " ]" << std::endl;
    }
}

// Part2() - process the file and builds a map of words and a set of line numbers in which the word appears
void part2() {
    std::map<std::string, std::set<int>> wordPair;
    std::string word;
    std::string line;
    int lineCount {0};
    std::ifstream file {"words.txt"};

    if (file) {
        while (std::getline(file, line)) {
            ++lineCount;

            line = cleanString(line);               // to get cleaner version of the string line

            // extracting words from the string line using istringstream class object iss
            std::istringstream iss(line);

            while (iss >> word) {
                wordPair[word].insert(lineCount);
            }
        }

        file.close();
        display(wordPair);
    }
    else {
        std::cout << "Error opening input file..." << std::endl; 
    }
}

int main() {
    part1();
    part2();

    return 0;
}
