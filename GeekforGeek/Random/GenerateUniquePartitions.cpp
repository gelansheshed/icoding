//http://www.geeksforgeeks.org/generate-unique-partitions-of-an-integer/
//比较着用generate parentheses 的递归方法。
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
vector<vector<int>> printAllUniqueParts(int n)
{
	vector<vector<int>>result;
	if (n < 1)
		return result;
	if (n == 1)return vector<vector<int>>{{1}};
	if (n == 2)return vector<vector<int>>{{2}, { 1, 1 }};
	for (int i = 1; i < n; i++)
	{
		for (auto &a : printAllUniqueParts(i))
		{
			vector<int>cur = a;
			cur.push_back(n - i);
			sort(cur.begin(), cur.end(), greater<int>());
			if (find(result.begin(), result.end(), cur) == result.end())
				result.push_back(cur);
		}
	}
	result.push_back(vector<int>(1, n));
	return result;
}
void print(vector<vector<int>>&result)
{
	for (auto& a : result)
	{
		for (auto& i : a)
		{
			cout << i << " ";
		}
		cout << endl;
	}
}
int main()
{
	vector<vector<int>>result = printAllUniqueParts(4);
	print(result);

	return 0;
}

//Geeksforgeeks
#include<iostream>
using namespace std;
 
// A utility function to print an array p[] of size 'n'
void printArray(int p[], int n)
{
    for (int i = 0; i < n; i++)
       cout << p[i] << " ";
    cout << endl;
}
 
void printAllUniqueParts(int n)
{
    int p[n]; // An array to store a partition
    int k = 0;  // Index of last element in a partition
    p[k] = n;  // Initialize first partition as number itself
 
    // This loop first prints current partition, then generates next
    // partition. The loop stops when the current partition has all 1s
    while (true)
    {
        // print current partition
        printArray(p, k+1);
 
        // Generate next partition
 
        // Find the rightmost non-one value in p[]. Also, update the
        // rem_val so that we know how much value can be accommodated
        int rem_val = 0;
        while (k >= 0 && p[k] == 1)
        {
            rem_val += p[k];
            k--;
        }
 
        // if k < 0, all the values are 1 so there are no more partitions
        if (k < 0)  return;
 
        // Decrease the p[k] found above and adjust the rem_val
        p[k]--;
        rem_val++;
 
 
        // If rem_val is more, then the sorted order is violeted.  Divide
        // rem_val in differnt values of size p[k] and copy these values at
        // different positions after p[k]
        while (rem_val > p[k])
        {
            p[k+1] = p[k];
            rem_val = rem_val - p[k];
            k++;
        }
 
        // Copy rem_val to next position and increment position
        p[k+1] = rem_val;
        k++;
    }
}
 
// Driver program to test above functions
int main()
{
    cout << "All Unique Partitions of 2 \n";
    printAllUniqueParts(2);
 
    cout << "\nAll Unique Partitions of 3 \n";
    printAllUniqueParts(3);
 
    cout << "\nAll Unique Partitions of 4 \n";
    printAllUniqueParts(4);
 
    return 0;
}