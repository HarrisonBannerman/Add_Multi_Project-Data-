//==========================================
//Roosevelt Bannerman
//Data Structures
//Addition & Mutliplcation Program
//==========================================

//==========================================
//REVIEW INPUT VALIDATION
//FINISH DISPLAY FUNCTION
//ADD COMMENT BOXES ABOVE FUNCTIONS
//==========================================
#include <iostream>
#include <string>

using namespace std;

const int MAX_NUMBERS = 12;

string obtainNumbers(int);
int obtainAmountNumbers();
string sumNumbers(string[],int);
string sumTwo(string,string);
void displayStuff(string[],int,string,string[],string);
string multiplyStuff(string[],string,string);

int main(){

    const int AMOUNT_NUMBERS = obtainAmountNumbers();

    string theNumbers[AMOUNT_NUMBERS];

    for(int i=0;i<AMOUNT_NUMBERS;i++){
        string temp = obtainNumbers(i);
        if(temp == ""){
            break;
        }
        else{
            theNumbers[i] = temp;
        }
    }
    string multiSteps[theNumbers[1].length()];
    string sumTotal = sumNumbers(theNumbers,AMOUNT_NUMBERS);
    string multiTotal = multiplyStuff(multiSteps,theNumbers[0],theNumbers[1]);

    displayStuff(theNumbers,AMOUNT_NUMBERS,sumTotal,multiSteps,multiTotal);

    //system(pause);
}

//==========================
//Obtains the amount of numbers the user will enter
//Returns the amount
//==========================
int obtainAmountNumbers(){

string amountNumbers;
bool notValid = false;

do{
    cout << "\n\nHow many numbers would you like to enter: ";
    getline(cin,amountNumbers);

    int length = amountNumbers.length();

    if(length < 1 || length > 2){
        cout << "\nInvalid Input.";
        notValid = true;
        continue;
    }
    else if(length == 1){
        int temp = amountNumbers[0] - '0';
        if(temp < 2 || temp > 12){
            cout << "\nInvalid Input.";
            notValid = true;
            continue;
        }
        else{
            return temp;
        }
    }
    else{
        int temp = ((amountNumbers[0] - '0') * 10) + (amountNumbers[1] - '0');
        if(temp < 2 || temp > 15){
            cout << "\n\tInvalid Input.";
            notValid = true;
            continue;
        }
        else{
            return temp;
        }
    }
} while (notValid);

    return 0;
}

//==========================
//Obtains the current user number
//Returns the current number
//==========================
string obtainNumbers(int current){

    string theNumber;
    bool isValid = true;

    do{
        cout << "\nPlease enter #" << current+1 << ": ";
        getline(cin,theNumber);

        if(theNumber == ""){
            return theNumber;
        }
        for(unsigned int i = 0;i < theNumber.length();i++){
            if(theNumber[i] > '9' || theNumber[i] < '0' || theNumber.length() > 20){
                isValid = false;
                cout << "\nInvalid Input.";
                break;
            }
            else{
                isValid = true;
            }
        }
    }while(isValid == false);
    return theNumber;
}

//==========================
//Recieves the list of numbers the user entered
//Calculates the total of the numbers
//Returns the total
//==========================
string sumNumbers(string numbers[],int amount){
    string total = numbers[0];

    for(int i=1;i<amount;i++){
        total = sumTwo(total,numbers[i]);
    }

    return total;

}

//==========================
//Recieves two numbers
//Calculates the sum of the two numbers
//Returns the sum
//==========================
string sumTwo(string x,string y){

    if(y.length() > x.length()){
        swap(x,y);
    }

    string temp;

    for(int i=(x.length()-1);i>-1;i--){
        temp += x[i];
    }
    x = temp;
    temp = "";

    for(int i=(y.length()-1);i>-1;i--){
        temp += y[i];
    }
    y = temp;
    temp = "";


    const int difference = x.length() - y.length();

    string result;
    int carry = 0;

    for(unsigned int i = 0; i < (x.length() - difference);i++){
        int temp = x[i] + y[i] - '0' - '0' + carry;
        if(temp > 9){
            result += temp - 10 + '0';
            carry  = 1;
        }
        else{
            result += temp + '0';
            carry = 0;
        }
    }

    for(unsigned int i = (x.length() - difference); i < x.length();i++){
        int temp = x[i] + carry - '0';
        if(temp > 9){
            result += temp - 10 + '0';
            carry = 1;
        }
        else{
            result += temp + '0';
            carry = 0;
        }
    }

    if(carry == 1){
        result += '1';
    }

    for(int i=(result.length()-1);i>-1;i--){
        temp += result[i];
    }

    result = temp;

    return result;
}

//==========================
//Recieves the first two numbers the user entered
//Calculates the product of the two
//Returns the product
//==========================
string multiplyStuff(string steps[],string x,string y){

    const int ORGINAL_X_LENGTH = x.length();
    const int ORGINAL_Y_LENGTH = y.length();

    int xNumbers[ORGINAL_X_LENGTH];

    for(int i=ORGINAL_X_LENGTH-1;i>-1;i--){
        xNumbers[i] = x[i] - '0';
    }

    int yNumbers[ORGINAL_Y_LENGTH];

    for(int i=ORGINAL_Y_LENGTH-1;i>-1;i--){
        yNumbers[i] = y[i] - '0';
    }

    string temp;

    int counter = 0;
    for(int i = ORGINAL_X_LENGTH - 1; i > -1 ;i--){
        counter++;
        temp+= x[i];
        if(counter == 3 && i != 0){
            temp += ",";
            counter = 0;
        }
    }

    x = "";

    for(int i = temp.length();i>-1;i--){
            x += temp[i];
    }

    temp = "";
    counter = 0;

    for(int i = ORGINAL_Y_LENGTH - 1; i > -1 ;i--){
        counter++;
        temp+= y[i];
        if(counter == 3 && i != 0){
            temp += ",";
            counter = 0;
        }
    }

    y = "";

    for(int i = temp.length();i>-1;i--){
            y += temp[i];
    }

    int carry = 0;
    counter = 0;

    for(int i = ORGINAL_Y_LENGTH-1;i>-1;i--){
        for(int ii=0;ii<counter;ii++){
            steps[i] += '0';
        }
        for(int ii = ORGINAL_X_LENGTH-1;ii>-1;ii--){
            int temp = (yNumbers[i] * xNumbers[ii]) + carry;
            if(temp > 9){
                carry = temp / 10;
                temp = temp % 10;
                steps[i] += temp + '0';
                if(ii == 0){
                    steps[i] += carry + '0';
                    carry = 0;
                }
            }
            else{
                carry = 0;
                steps[i] += temp + '0';
            }
        }
        counter++;
    }

    for(int i=0;i<ORGINAL_Y_LENGTH;i++){
        string temp = steps[i];
        steps[i] = "";
        for(int ii=temp.length()-1;ii>-1;ii--){
            steps[i] += temp[ii];
        }
    }

    string temps[ORGINAL_Y_LENGTH];
    for(int i=0;i<ORGINAL_Y_LENGTH;i++){
        temps[i] = steps[i];
    }
    counter = 0;
    for(int i=ORGINAL_Y_LENGTH-1;i>-1;i--){
        steps[i] = temps[counter];
        counter++;
    }

    string total = sumNumbers(steps,ORGINAL_Y_LENGTH);

    return total;
}


//==========================
//Recieves all the results
//Places commas in all the strings
//Displays the results
//===========
void displayStuff(string numbers[],int amountNumbers,string sum, string steps[],string product){

//=============================
//Find longest string
//Display results in correct format
//===============================

    int numberSteps = numbers[1].length();


    for(int i=0;i<amountNumbers;i++){
        string temp = numbers[i];
        int length = temp.length();
        for(int ii = length - 3; ii > 0; ii -= 3){
            temp.insert(ii,",");
        }
        numbers[i] = temp;
    }

    for(int i=0;i<numberSteps;i++){
        string temp = steps[i];
        int length = temp.length();
        for(int ii = length - 3; ii > 0; ii -= 3){
            temp.insert(ii,",");
        }
        steps[i] = temp;
    }

    for(int i = sum.length()-3; i > 0; i -= 3){
            sum.insert(i,",");
    }

    for(int i = product.length()-3; i > 0; i -= 3){
            product.insert(i,",");
    }

    int longest = product.length();

    if(sum.length() > longest){
        longest = sum.length();
    }

    for(int i = 0; i < amountNumbers;i++){
        if(numbers[i].length() > longest){
            longest = numbers[i].length();
        }
    }

    longest += 3;

    string dashes(longest,'-');

    cout << "The sum of : " << endl << endl;

    for(int i=0;i<amountNumbers;i++){
        string temp(longest-numbers[i].length(),' ');
        if(i==amountNumbers-1){
            temp[0] = '+';
            temp[1] = ')';
        }
        cout << temp << numbers[i] << endl;
    }
    cout << dashes << endl;

    string temp(longest-sum.length(),' ');
    cout << temp << sum << endl << endl;

    cout << "The product of : " << endl<< endl;

    string temp2(longest-numbers[0].length(),' ');
    string temp3(longest-numbers[1].length(),' ');
    temp3[0] = '*';
    temp3[1] = ')';

    cout << temp2 << numbers[0] << endl;
    cout << temp3 << numbers[1] << endl;
    cout << dashes << endl;

    for(int i=0;i<numberSteps;i++){
        string temp(longest-steps[i].length(),' ');
        if(i==numberSteps-1){
            temp[0] = '+';
            temp[1] = ')';
        }
        cout << temp << steps[i] << endl;
    }
    cout << dashes << endl;

    string temp4(longest-product.length(),' ');
    cout << temp4 << product << endl << endl;

}

