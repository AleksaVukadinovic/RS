#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

void Numbers() {
    vector<int> xs;

    // sentinel - fake end boundary for something like std input
    copy(istream_iterator<int>(cin), istream_iterator<int>(), back_inserter(xs));
    sort(begin(xs), end(xs));
    copy(cbegin(xs), cend(xs), ostream_iterator<int>(cout, " "));
    copy(crbegin(xs), crend(xs), ostream_iterator<int>(cout, " "));

    cout << endl;
}
