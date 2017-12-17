#include <bits/stdc++.h>
using namespace std;

string ones[10] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
string tens[10] = {"-", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
string lastDigit_zero[10] = {"-", "Ten", "Twenty", "Thirty", "Fourty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

string printNumbers(int n){
    int dup = n;
    int isNotEleven = 1;
    string s;
    
    if(dup/1000){
        int thousandth = dup/1000;
        if(thousandth){
            s += ones[thousandth] + " Thousand";
            dup = dup % 1000;
        }
    }
    
    if(dup/100){
        int hund = dup/100;
        if(hund){
            s += " " + ones[hund] + " Hundered";
            dup = dup % 100;
        }
    }
    
    if(dup/10){
        int ten = dup/10;
        if(ten){
            if(ten == 1 && dup % 10 != 0){
                s += " " + tens[dup%10];
                isNotEleven = 0;
            }else{
                s += " " + lastDigit_zero[ten];
            }
            dup = dup%10;
        }
    }
    
    if(dup && isNotEleven){
        s += " " + ones[dup];
    }
    
    s += ".";
    
    return s;
}

int main() {
	int n;
	cin >> n;
	//for(int i=1; i<=n; i++){
    	string s = printNumbers(n);
    	
    	cout << n << ": " + s << endl << endl;
	//}
	
	return 0;
}