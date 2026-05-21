#ifndef MAIN_HPP
#define MAIN_HPP
// Vector intro: makeVector, insertVector, deleteVector
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;
void makeVector(vector<int> &);
void insertVector(vector<int> &, int);
int deleteVector(vector<int> &, int);
int randnum(void);
int getInput(void);
void printVector(vector<int>);
void makeVector(vector<int> &number)
{
    // Fill with random integers in [0, 20), then sort
    srand(time(0));
    for (int i = 0; i < (int)number.size(); i++) {
        number[i] = rand() % 20;
    }
    sort(number.begin(), number.end());
}
void insertVector(vector<int> &number, int usernum)
{
    // Walk with iterator; insert before the first element greater than usernum
    for (auto iter = number.begin(); iter != number.end(); iter++) {
        if (*iter > usernum) {
            number.insert(iter, usernum);
            return;
        }
    }
    // usernum is >= every element — append at end
    number.insert(number.end(), usernum);
}
int deleteVector(vector<int> &number, int usernum)
{
    // Erase every occurrence of usernum; return count or -1 if none found
    int count = 0;
    auto iter = number.begin();
    while (iter != number.end()) {
        iter = find(iter, number.end(), usernum);
        if (iter != number.end()) {
            iter = number.erase(iter);  // erase returns iterator to next element
            count++;
        }
    }
    return (count == 0) ? -1 : count;
}
int getInput(void)
{
    int num;
    cout << "Enter your input\n";
    cin >> num;
    return num;
}
int randnum(void)
{
    return rand() % 100;
}
void printVector(vector<int> number)
{
    for (auto iter = number.begin(); iter != number.end(); iter++)
        cout << setw(5) << *iter;
    cout << endl;
}
#endif
