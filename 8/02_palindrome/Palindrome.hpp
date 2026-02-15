#pragma once

#include <iostream>
#include <algorithm>
#include <string>
#include <iterator>

using namespace std;

bool Palindrome(const string &str) {
    return equal(cbegin(str), cend(str), crbegin(str));
}
