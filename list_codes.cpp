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
    print(cache1);
    

    // 1) push_back, push_front
    cache1.push_back("d");
    cache1.push_back("d");
    cache1.push_front("aba");
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
    // =================================================================
    // 4) find, find_if, insert
    // insert "c2" in front of "d"
    auto it = find(cache1.begin(), cache1.end(), "d");
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
    //cache1.remove("c1");
    //cache1.remove_if([](string a){ return a == "c1";});
    it = remove_if(cache1.begin(), cache1.end(), [](string a){return a == "c1";});    
    cache1.erase(it, cache1.end());
    print(cache1);
    it = remove_if(cache1.begin(), cache1.end(), [](string a){return a == "c2";});
    cache1.erase(it, cache1.end());    
    print(cache1);

    //copy, copy_if
    list<string> cache2(cache1.size(),""); 
    // 복사하는 대상과 복사하려는 목적 대상의 크기가 같아야한다!!
    copy(cache1.begin(), cache1.end(), cache2.begin());
    print(cache2);

    //transform
    string idata = cache1.front();
    cout <<  idata.length() << endl;
    string odata(idata.length(), ' ');
    transform(idata.begin(), idata.end(), odata.begin(), ::toupper );
    cout << odata << endl;


    return 0;

}

