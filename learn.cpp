#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1;
    vector<int>::iterator it;

    it = v1.begin();
    v1 = vector<int>();
    // cout << *it << endl;
    return 0;
}
