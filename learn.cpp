#include <iostream>
#include <memory>
#include <vector>
#include <map>
#include <stack>

using namespace std;

int main()
{
    // vector<int> v1;
    // vector<int> v2;
    // v1 = v2;
    // // vector<int>::iterator it;

    // v1.assign(343, 10);
    // cout << v1.capacity() << endl;
    // // cout << v1.size() << endl;
    // cout << "-------------------------" << endl;
    // // v1.clear();
    // // for(size_t i = 0; i < v1.size(); i++){
    // //     cout << v1[i] << endl;
    // // }
    // cout << v1.max_size() << endl;
    // v1.reserve(4611686018427387903);
    // throw length_error("'n' exceeds maximum supported size");
    // v2.assign(v1.end(), v1.begin());

    vector<string> t;
    vector<string> t2;
    // cout << t.begin().base() << endl;
    t.push_back("kdjfkdjf");
    t.push_back("kdjfkdjf");
    t.push_back("kdjfkdjf");
    t.push_back("kdjfkdjf");
    t.push_back("kdjfkdjf");
    t.push_back("kdjfkdjf");
    t = t2;
    cout << "----------------------------" << endl;
    cout << t.size() << endl;
    cout << t.capacity() << endl;
    t.erase(t.end(), t.begin());
    cout << "----------------------------" << endl;
    cout << t.size() << endl;
    cout << t.capacity() << endl;
    t.max_size();
    map<char*, string>::iterator it;
    map<char*, string> map;
    it = map.begin();
    char *s = "a";
    map.insert(make_pair(s, "abdellah"));
    cout << map[s] << std::endl;
    cout << *it->first << std::endl;
    // cout << t.begin().base() << endl;

    // vector<string>::iterator it;
    // it = t.erase(t.begin());
    // cout << it.base() << endl;
    // cout << t.begin().base() << endl;
    // if (std::distance(v1.end(), v1.begin()) < 0)
	// 	throw std::length_error("negative distance");
    // cout << v1[0] << endl;
    // cout << *it << endl;
    return 0;
}
