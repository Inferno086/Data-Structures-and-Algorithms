#include <bits/stdc++.h>
#include <iostream>
using namespace std;

void display(vector<int> v)
{
    cout << "Size of the vector is : " << v.size() << endl;
    cout << "The vector is : ";
    for(vector<int> :: iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
}

void display(vector<pair<int, int>> v)
{
    cout << "The vector<pair<int,int>> is (using iterator): \n";
    for(auto it = v.begin(); it != v.end(); it++)
    {
        cout << it -> first << " " << it -> second << endl;    
    }
    cout << endl;

    cout << "The vector<pair<int,int>> is (using range): \n";
    for(pair<int, int> value : v)
    {
        cout << value.first << " " << value.second << endl;
    }
    cout << endl;
    
    cout << "The vector<pair<int,int>> is (using simple for loop): \n";
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << " " << v[i].second << endl;
    }
    cout << endl;
}

void display(vector<vector<int>> v)
{
    cout << "The vector<vector<int>> is : \n";
    for(auto value : v)
    {
        for(auto val : value)
        {
            cout << val << " ";
        }
        cout << endl;
    }
}
/*The auto keyword is a simple way to declare a variable that
has a complicated type.*/

int main()
{
    vector<int> v0;

    int n0;
    cout << "Enter the no. of elements : ";
    cin >> n0;
    cout << "\n";

    for(int i = 0; i < n0; i++)
    {
        int k;
        cin >> k;
        v0.push_back(k);
    }

    display(v0);

    // vector<pair<int,int>>
    vector<pair<int, int>> v1 = {{1,2}, {3,4}, {5,6}};

    display(v1);
    
    // vector<vector<int,int>>
    vector<vector<int>> v2;

    cout << "Enter the number of input vectors : ";
    int k2;
    cin >> k2;

    for(int i = 0; i < k2; i++)
    {
        int k3;
        cin >> k3;
        vector<int> temp;
        for(int j = 0; j < k3; j++)
        {
            int val;
            cin >> val;
            temp.push_back(val);
        }
        v2.push_back(temp);
    }
    /*
    When we first created the vector v2, it is made with zero elements.
    Therefore, if while taking input from the user we try to assign the
    elements like v2[i].push_back(val), the code does not work properly 
    because v2[i] does not exist yet. Due to this reason, we first take 
    the element vector in temp, and then use v2.push_back(temp)
    */

    display(v2);

    return 0;
}