#include <iostream>  
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;  



int hexaToDeci(string hexaDeci){

    int intNum = 0;
    int totalInt = 0;
    int length = hexaDeci.length(); 

    for(int i = 0; i < hexaDeci.length(); i++){
        switch(hexaDeci.at(i)){
            case '0':
                intNum = 0;
                totalInt += intNum * pow(16, length-1);
                break;
            case '1':
                intNum = 1;
                totalInt += intNum * pow(16, length-1);
                break;
            case '2':
                intNum = 2;
                totalInt += intNum * pow(16, length-1);
                break;
            case '3':
                intNum = 3;
                totalInt += intNum * pow(16, length-1);
                break;
            case '4':
                intNum = 4;
                totalInt += intNum * pow(16, length-1);
                break;
            case '5':
                intNum = 5;
                totalInt += intNum * pow(16, length-1);
                break;
            case '6':
                intNum = 6;
                totalInt += intNum * pow(16, length-1);
                break;
            case '7':
                intNum = 7;
                totalInt += intNum * pow(16, length-1);
                break;
            case '8':
                intNum = 8;
                totalInt += intNum * pow(16, length-1);
                break;
            case '9':
                intNum = 9;
                totalInt += intNum * pow(16, length-1);
                break;
            case 'A':
                intNum = 10;
                totalInt += intNum * pow(16, length-1);
                break;
            case 'B':
                intNum = 11;
                totalInt += intNum * pow(16, length-1);
                break;
            case 'C':
                intNum = 12;
                totalInt += intNum * pow(16, length-1);
                break;
            case 'D':
                intNum = 13;
                totalInt += intNum * pow(16, length-1);
                break;
            case 'E':
                intNum = 14;
                totalInt += intNum * pow(16, length-1);
                break;
            case 'F':
                intNum = 15;
                totalInt += intNum * pow(16, length-1);
                break;
        }                                                
        length--;
    }
    cout << totalInt << endl;
    
    return totalInt;
}

void IntToHexa(int x){

    int temp = x;
    int remainNum = 0;
    string strNum = "";

    while(temp > 0){

        remainNum = temp % 16;
    
        if(remainNum >= 10) {
            switch(remainNum) {
                case 10:
                    strNum += "A";
                    break;
                case 11:
                    strNum += "B";
                    break;
                case 12:
                    strNum += "C";
                    break;
                case 13:
                    strNum += "D";
                    break;
                case 14:
                    strNum += "E";
                    break;
                case 15:
                    strNum += "F";
                    break;
            }
        } 
        
        if(remainNum < 10) {
            switch(remainNum) {
                case 9:
                    strNum += "9";
                    break;
                case 8:
                    strNum += "8";
                    break;
                case 7:
                    strNum += "7";
                    break;
                case 6:
                    strNum += "6";
                    break;
                case 5:
                    strNum += "5";
                    break;
                case 4:
                    strNum += "4";
                    break;
                case 3:
                    strNum += "3";
                    break;
                case 2:
                    strNum += "2";
                    break;
                case 1:
                    strNum += "1";
                    break;
                case 0:
                    strNum += "0";
                    break;
            }
        }
        temp = temp / 16;
    }

    reverse(strNum.begin(), strNum.end());
    cout << strNum << endl;
}

int main(){

    long long int total = 0;
    long long int num1 = 0;
    long long int num2 = 0;
    
    num1 = hexaToDeci("FFFFF");
    num2 = hexaToDeci("123ABC");


    total = num1 * num2;
    cout << total << endl;

    hexaToDeci("FFFFF");
    hexaToDeci("123ABC");
    IntToHexa(1048575);
    IntToHexa(1194684);

    return 0;
}  