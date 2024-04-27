#include <iostream>
#include <string>

class Numbers {
private:
    mutable int number; // Make number mutable

    static const std::string lessThan20[20];
    static const std::string tens[10];
    static const std::string hundred;
    static const std::string thousand;

public:
    Numbers(int num) : number(num) {}

    void print() const {
        int num = number; // Create a non-const copy to modify
        if (num == 0) {
            std::cout << lessThan20[num];
            return;
        }

        std::string result;

        if (num >= 1000) {
            result += lessThan20[num / 1000] + " " + thousand + " ";
            num %= 1000;
        }

        if (num >= 100) {
            result += lessThan20[num / 100] + " " + hundred + " ";
            num %= 100;
        }

        if (num >= 20) {
            result += tens[num / 10 - 2] + " ";
            num %= 10;
        }

        if (num > 0) {
            if (!result.empty()) {
                result += "and "; // Add "and" if there are more than one part
            }
            result += lessThan20[num];
        }

        std::cout << result;
    }
};

const std::string Numbers::lessThan20[20] = {"zero", "one", "two", "three", "four", "five",
                                             "six", "seven", "eight", "nine", "ten", "eleven",
                                             "twelve", "thirteen", "fourteen", "fifteen",
                                             "sixteen", "seventeen", "eighteen", "nineteen"};

const std::string Numbers::tens[10] = {"twenty", "thirty", "forty", "fifty", "sixty",
                                        "seventy", "eighty", "ninety"};

const std::string Numbers::hundred = "hundred";
const std::string Numbers::thousand = "thousand";

int main() {
    int number;
    std::cout << "Enter a number between 0 and 9999: ";
    std::cin >> number;

    if (number < 0 || number > 9999) {
        std::cerr << "Invalid input! Please enter a number between 0 and 9999." << std::endl;
        return 1;
    }

    Numbers num(number);
    std::cout << "English description: ";
    num.print();
    std::cout << std::endl;

    return 0;
}
