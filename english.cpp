#include<bits/stdc++.h>
using namespace std;
unordered_map<string,int>big={
        {"thousand",1000},
        {"million",1000000},
        {"billion",1000000000},
};
unordered_map<string,int>small={
    {"zero",0},
    {"one",1},
    {"two",2},
    {"three",3},
    {"four",4},
    {"five",5},
    {"six",6},
    {"seven",7},
    {"eight",8},
    {"nine",9},
    {"ten",10},
    {"eleven",11},
    {"twelve",12},
    {"thirteen",13},
    {"fourteen",14},
    {"fifteen",15},
    {"sixteen",16},
    {"seventeen",17},
    {"eighteen",18},
    {"nineteen",19},
    {"twenty",20},
    {"thirty",30},
    {"forty",40},
    {"fifty",50},
    {"sixty",60},
    {"seventy",70},
    {"eighty",80},
    {"ninety",90},
    };
int stringToInteger(string input) {
    stringstream ss(input);
    int temp=0;
    int final=0;
    string token;
    while(ss>>token){
          if(small.find(token)!=small.end()){
            temp+=small[token];
          }
          else if(token=="hundred")
            temp*=100;
          else if(big.find(token)!=big.end()){
            temp*=big[token];
            final+=temp;
            temp=0;
          }
    }
    final+=temp;
    return final;


}
int main()
{
    string input;
    cout<<"Enter the number: "<<endl;
    getline(cin,input);
    cout<<stringToInteger(input)<<endl;


}