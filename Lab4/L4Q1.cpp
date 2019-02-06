//  L4Q1
//  author: Andrew Bishop

#include <iostream>
#include <string>
using namespace std;

bool isValid(const string& cardNumber);

int sumOfDoubleEvenPlace(const string& cardNumber);

int getDigit(int number);

int sumOfOddPlace(const string& cardNumber);

bool startsWith(const string& cardNumber, const string& substr);

bool hasValidPrefix(const string& cardNumber);

int main() {
    
    string card;
    cout << "Enter a credit card number to check its validity: ";
    cin >> card;
    
    if (isValid(card)) {
        cout << "Credit card is valid." << endl;
    } else {
        cout << "Credit card is invalid." << endl;
    }
}

// iterate through even nums from right to left, multiplying by two and summing them
// if equal to or greater than 10, getDigit() will add the two digits
int sumOfDoubleEvenPlace(const string& cardNumber) {
    int sum = 0;
    int currNum, i;
    if (cardNumber.length() > 2) {
        int firstIndex = static_cast<int>(cardNumber.length()) - 2;
        for (i=firstIndex; i>=0; i-=2) {
            // subtracting '0' to convert char to correct integer
            currNum = getDigit((cardNumber[i] - '0') * 2);
            sum += currNum;
        }
    }
    return sum;
}

// return number if less than 10, otherwise add the digits
int getDigit(int number) {
    if (number >= 10) {
        int firstNum = number % 10;
        int secondNum = number / 10;
        return firstNum + secondNum;
    }
    return number;
}

// iterate through odd nums from right to left, summing them
int sumOfOddPlace(const string& cardNumber) {
    int sum = 0;
    int currNum, i;
    if (cardNumber.length() > 2) {
        int firstIndex = static_cast<int>(cardNumber.length()) - 1;
        for (i=firstIndex; i>=0; i-=2) {
            // subtract '0' to convert char to correct integer
            currNum = cardNumber[i] - '0';
            sum += currNum;
        }
    }
    return sum;
}

// return true if card num is valid
bool isValid(const string& cardNumber) {
    if (hasValidPrefix(cardNumber)) {
        if ((sumOfDoubleEvenPlace(cardNumber) + sumOfOddPlace(cardNumber)) % 10 == 0) {
            return true;
        }
        return false;
    }
    return false;
}

// test if cardNumber starts with (4, 5, 37, 6)
bool hasValidPrefix(const string& cardNumber) {
    if (startsWith(cardNumber, "4") ||
        startsWith(cardNumber, "5") ||
        startsWith(cardNumber, "37") ||
        startsWith(cardNumber, "6"))
    {
        return true;
    }
    return false;
        
}

// return true if substr is the prefix for cardNumber
bool startsWith(const string& cardNumber, const string& prefix) {
    if (cardNumber.substr(0, prefix.length()) == prefix) {
        return true;
    }
    return false;
}

