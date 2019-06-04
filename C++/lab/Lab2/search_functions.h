#ifndef SEARCH_FUNCTIONS
#define SEARCH_FUNCTIONS
using namespace std;

// bool boolIndex(string data, string query);
// int searchRecursive(vector<string> &data, string query)
int searchRecursive(vector<string> &data, string query, int lowerBound, int upperBound);
int searchIterative(vector<string> &data, string query);

#endif