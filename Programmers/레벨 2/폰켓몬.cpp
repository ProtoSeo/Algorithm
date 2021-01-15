#include <vector>
#include <set>
#define MIN(a,b) (a>b)? b:a
using namespace std;

int solution(vector<int> nums)
{
    set<int> s;
    for(int n:nums) s.insert(n);
    return MIN(nums.size()/2,s.size());
}