#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<string> msg{"Namaste","its","Harsh","Pandey","Testing 123"};

    for(const string& word:msg)
    {
        cout<<word<<" ";
    }
    cout<<endl;
}