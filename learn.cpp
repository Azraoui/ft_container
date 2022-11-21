#include <iostream>
#include <memory>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int> v2;
    v1 = v2;
    vector<int>::iterator it;

    v1.assign(343, 10);
    cout << v1.capacity() << endl;
    // cout << v1.size() << endl;
    cout << "-------------------------" << endl;
    // v1.clear();
    // for(size_t i = 0; i < v1.size(); i++){
    //     cout << v1[i] << endl;
    // }
    cout << v1.max_size() << endl;
    // v1.reserve(4611686018427387903);
    // throw length_error("'n' exceeds maximum supported size");
    v2.assign(v1.end(), v1.begin());
    allocator<int> alloc;

    try
    {
        int *v = alloc.allocate(4611686018427387903);

    }
    catch (std::exception &e)
    {
        throw std::bad_alloc();
    }
    // if (std::distance(v1.end(), v1.begin()) < 0)
	// 	throw std::length_error("negative distance");
    // cout << v1[0] << endl;
    // cout << *it << endl;
    return 0;
}
