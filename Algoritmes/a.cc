#include <iostream>
#include <vector>

using namespace std;

int main () {
    string sintoma;
    vector <string> tots (0);
    while(cin>>sintoma){
        int size = tots.size();
        bool fi = 0;
        for(int i = 0; i<size; i++){
            if(tots[i] == sintoma){
                fi = 1;
            }            
        }
        if(not fi){
            tots.push_back(sintoma);
        }
    }
    for(int i = 0; i<tots.size(); i++){
        cout<<tots[i]<<", ";
    }
}