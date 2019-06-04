#include <iostream>
#include <fstream>
#include <string>
#include <math.h> // pow
#include <algorithm> // reverse

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
    
    return totalInt;
}

void IntToHexa(long long int x){

    long long int temp = x;
    long long int remainNum = 0;
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

int stringToInt(string binNum){

    int intNum = 0;
    int totalInt = 0;
    int length = binNum.length(); // 2

    for(int i = 0; i < binNum.length(); i++){

        if(binNum.at(i) == '1'){
            intNum = 1;
            totalInt += intNum * pow(2, length-1);
        }

        length--;
    }

    return totalInt;
}

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
    cout << strNum << endl;
}

void decimalCal(int x, string typeCal, int y){

    if(typeCal == "+"){
        cout << x + y <<endl;
    } 

    if(typeCal == "*"){
        cout << x * y <<endl;
    }
}

int main(){

    ifstream inFile;

    int lineNumbers;
    long long int num1, num2;
    long long int total;
    char typeNum;
    string typeCal;

    inFile.open("input.txt");

    if(!inFile.is_open()){
        cout << "Could not open file." << endl;return -1;
    }

    inFile >> lineNumbers;

    for(int i = 0; i < lineNumbers; i++){

        inFile >> typeNum;

        if(typeNum == 'B'){
            
            string inputOne = "";
            string inputTwo = "";

            inFile >> inputOne;
            inFile >> typeCal;
            inFile >> inputTwo;

            if(typeCal == "*"){
                num1 = stringToInt(inputOne);
                num2 = stringToInt(inputTwo);

                IntToString(num1 * num2);

            } else {
                num1 = stringToInt(inputOne);
                num2 = stringToInt(inputTwo);

                IntToString(num1 + num2);     
            }
        }

        if(typeNum == 'D'){

            inFile >> num1;
            inFile >> typeCal;
            inFile >> num2;
            
            decimalCal(num1, typeCal, num2);
        }

        if(typeNum == 'H'){

            string inputOne = "";
            string inputTwo = "";

            inFile >> inputOne;
            inFile >> typeCal;
            inFile >> inputTwo;

            if(typeCal == "*"){
                num1 = hexaToDeci(inputOne);
                num2 = hexaToDeci(inputTwo);
                total = num1 * num2;

                IntToHexa(total);

            } else {
                num1 = hexaToDeci(inputOne);
                num2 = hexaToDeci(inputTwo);

                IntToHexa(num1 + num2);     
            }
        }
    }

    inFile.close();
    return 0;
}
