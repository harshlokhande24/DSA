//Assignment 5 DSA
//Harshwardhan Lokhande


#include <iostream>
#include <map>
using namespace std;

int main()
{
    int amount, i=0, count;
    cout<<"Enter amount to be paid: ";
    cin>>amount;
    int x[] = {500, 200, 100, 50, 20, 10, 5, 2, 1};
    map<int, int> set;
    
    while (amount > 0) {
        count = 0;
        while(amount >= x[i]) {
            amount = amount - x[i];
            set[x[i]] = ++count;
        }
        i++;
    }
    
    cout<<"Amount: "<<amount<<endl;
    
    map<int, int> :: iterator it = set.begin();
    
    while(it != set.end()) {
        cout<<"Currency: "<<it->first<<" Qty: "<<it->second<<endl;
        it++;
    }
    
    return 0;
}
