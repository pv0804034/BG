#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ofstream out;
    out.open("output.txt", std::ofstream::out | std::ofstream::trunc);
    out<<"["<<endl;
    for(int i = 1;i<=18;i++){
        ifstream in("chapter"+to_string(i)+".txt");
        string s;
        while(getline(in,s)){
            if(s == "")continue;
            out<<"    [";
            if(s.substr(0,13) == "Bhagavad Gita"){
                string temp = "";
                for(int i = 13;i<s.size();i++){
                    temp += s[i];
                }
                // cout<<temp<<endl;
                string a = "";
                string b = "";
                bool dot = false;
                for(int i = 0;i<temp.size();i++){
                    if(dot && temp[i] >= '0' && temp[i] <= '9'){
                        a += temp[i];
                    }else if(dot && (temp[i] < '0' || temp[i] > '9'))break;
                    if(temp[i] == '.')dot = true;
                }
                for(int i = temp.size()-1;i>=0;i--){
                    if(temp[i] == '.')break;
                    b += temp[i];
                }
                reverse(b.begin(),b.end());
                // cout<<(a == b?a:(a + " " + b))<<endl;
                out<<"\""<<i<<"\",";
                if(a == b){
                    out<<"\""<<a<<"\"";
                }else{
                    out<<"\""<<a<<"-"<<b<<"\"";
                }
                getline(in,s);
                out<<", \""<<s<<"\"";
            }
            out<<"],"<<endl; 
        }
    }
    out<<"];"<<endl;
    return 0;
}