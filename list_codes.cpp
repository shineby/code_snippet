// https://en.cppreference.com/w/cpp/container/list

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

using namespace std;

void print(const list<string> &data)
{
    for (auto t : data)
    {
        cout << t << ",";
    }
    cout << endl;
}

int main()
{
    // constructor
    list<string> cache1(1,"b");
    list<string> cache2 = {"B"};
    print(cache1);
    print(cache2);    

    // 1) push_back, push_front
    cache1.push_back("d");
    cache1.push_back("d");
    cache1.push_front("a");
    cache1.push_front("a");
    print(cache1); //a,a,b,d,d

    // 2) back, front
    // show first and last element
    cout << "back of cache1 : " << cache1.back() << endl;  // a
    cout << "front of cache1 : " <<  cache1.front() << endl; // d

    // 3) pop_back, pop_front
    cache1.pop_back();
    cache1.pop_front();
    print(cache1); // a,b,d

    // !!! find, remove, copy, trnsform !!! ============================
    // 4) find, find_if, insert
    // insert "c2" in front of "d"
    auto it = find(cache1.begin(), cache2.end(), "d");
    if (it != cache1.end())
        cache1.insert(it,"c2");
    print(cache1);
    // insert "c2" in front of "d"
    it = find_if(cache1.begin(), cache1.end(), [](string a){ return a == "c2";});
    if (it != cache1.end())
        cache1.insert(it,"c1");
    print(cache1);

    // remove, remove_if
    // remove c1, c2
    cache1.remove("c1");
    remove_if(cache1.begin(), cache1.end(), [](string a){return a == "c2";});
    print(cache1);

    cout << "cache size : " << cache1.size() << endl;
    return 0;
}

