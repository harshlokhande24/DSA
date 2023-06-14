//Assignment 4 DSA
//Harshwardhan Lokhande


#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main()
{
    map<int, int> knap;
    map<int, int> sack;
    
    int profit[50], weight[50], pr[50];
    int i = 0, n, W, finalcost=0;
    cout<<"Enter maximum capacity: ";
    cin>>W;
    cout<<"Enter number of items: ";
    cin>>n;
    for(i=0; i<n; i++) {
        cout<<"Profit: ";
        cin>>profit[i];
        cout<<"Weight: ";
        cin>>weight[i];
        pr[i] = profit[i]/weight[i];
        knap[profit[i]] = weight[i];
        sack[pr[i]] = profit[i];
    }
    
    sort(begin(pr), end(pr), greater<int>());
    
    cout<<"----------------------"<<endl;
    i=0;
    while (knap[sack[pr[i]]] < W) {
        finalcost = finalcost + sack[pr[i]];
        W = W - knap[sack[pr[i]]];
        cout<<"Weight: "<<knap[sack[pr[i]]]<<" Profit: "<<sack[pr[i]]<<endl;
        i++;
    }
    
    if(W) {
        cout<<"Weight: "<<W<<" Profit: "<<(W*pr[i])<<endl;
        finalcost = finalcost + (W*pr[i]);
        W = 0;
    }
    cout<<"----------------------"<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout<<"FinalCost: "<<finalcost<<"\nWeight remaining: "<<W<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~~~"<<endl;

    return 0;
}
