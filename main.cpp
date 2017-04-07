#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <utility>

// 1. http://practice.geeksforgeeks.org/problems/first-non-repeating-character-in-a-stream/0
// 
// Input:
// The first line of input contains an integer T denoting the no of test cases. Then T test cases follow.
// Each test case contains an integer N denoting the size of the stream. Then in the next line are x characters which are inserted to the stream.
// 
// Output:
// For each test case in a new line print the first non repeating elements separated by spaces present in the stream at every instinct when a
// character is added to the stream, if no such element is present print -1.
// 
// Constraints:
// 1<=T<=200
// 1<=N<=500
// 
// Example:
// Input:
// 2
// 4
// a a b c
// 3
// a a c 
// Output:
// a -1 b b
// a -1 c

struct Problem
{
    std::vector<char> C;

    void input()
    {
        int N = 0;
        int c = 0;
        std::cin >> N;

        ++N;
        while(--N && std::cin >> c)
        {
            C.push_back(c);
        }
    }

    void solve()
    {
        std::vector< std::pair<int, bool> > m(255, std::make_pair(0, false) );
        std::vector<char>::size_type vec_size = C.size();
        
        for(int j = 0; j < vec_size; ++j)
        {
            ++m[ C[j] ].first;
        }
        
        for(int j = 0; j < vec_size && m[C[j]].first >= 1; ++j)
        {
            std::cout << m[ C[j] ].second ? -1 : C[j]
            if(j != vec_size - 1)
                std::cout << ' ';
        }
        std::cout << std::endl;
    }
};


int main()
{
    int T = 0;
    std::cin >> T;
    std::vector<Problem> testCases(T);
    for(int i = 0; i < T; ++i)
    {
        testCases[i].input();
    }

    for(int i = 0; i < T; ++i)
    {
        testCases[i].solve();
    }

    return 0;
}
