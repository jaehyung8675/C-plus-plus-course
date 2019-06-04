#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>

using namespace std;

void IntToString(int x){

    int temp = x;
    int remainNum = 0;
    string strNum = "";

    while(temp > 0){

        remainNum = temp % 2;
    
        if(remainNum == 0){
            strNum += "0";
        } else {
            strNum += "1";
        }
        temp = temp / 2;
    }

    reverse(strNum.begin(), strNum.end());
    cout <<  strNum << endl;
}

int stringToInt(string binNum){

    int intNum = 0;
    int totalInt = 0;
    int length = binNum.length();

    for(int i = 0; i < binNum.length(); i++){

        if(binNum.at(i) == '1'){
            intNum = 1;
            totalInt += intNum * pow(2, length-1);
        }

        length--;
    }

    return totalInt;
}


int main(){

    string inputOne =  "1011000101";
    string inputTwo =  "11010001";

    int num1 = stringToInt(inputOne);
    int num2 = stringToInt(inputTwo);
    int total = num1 + num2;

    IntToString(total);

    return 0;
}


