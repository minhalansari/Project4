#include<iostream>
using std::cout; using std::cin; using std::endl; using std::boolalpha;
#include<string>
using std::string; using std::to_string;
#include<cmath>


const string the_chars = "0123456789abcdef";


string reverse_string (string str){ //this function reverses a given string
    string new_str;
    new_str = string(str.rbegin(),str.rend());
    return new_str;
    
}

bool is_palindrome(string arg){ //returns true or false if the string is a palindrome
    string rev;
    rev = reverse_string(arg); //call reverse_string then compare to original string
    if (arg == rev){
        return true;
    }
    else{
        return false;
    }
}

string long_to_base(long orig, long base){ //converts a longto the given base
    
    string result = ""; //empty string
    while(orig> 0){ //while loop that continues until original is reduced to zero 
        long remain = orig%base;
        orig = orig/base;
        result+=the_chars[remain];
        
    }
   return reverse_string(result); 
}
bool is_prime(long argument){ //checks if the given long is prime returns true or false
    int i;
    for (i=2; i<argument; i++){
       if(argument % i==0){
           return false;
       }
    }
    
    return true; 
}
string is_pal_prime(long number){ //checks if given long is prime then converts to all three bases and checks which base it is a palindrome in
    string newbase2;
    string newbase3;
    string newbase4;
    newbase2 = long_to_base(number,2);
    newbase3 = long_to_base(number,16);
    newbase4 = long_to_base(number,10);
    if (is_prime(number) and is_palindrome(newbase2)) {
        return "binary-pal-prime";
    }
    else if(is_prime(number) and is_palindrome(newbase3)){
        return "hex-pal-prime";
    }
    else if(is_prime(number) and is_palindrome(newbase4)){
        return "decimal-pal-prime";
    }
    else{
        return "not-pal-prime";
    }
    
    
}

int main (){
  long test_num;
  cin >> test_num;
  cout << boolalpha;

  switch(test_num) {

  case 1: {
    string input;
    cin >> input;
    cout << reverse_string(input);
    break;
  }

 case 2:{
     string input;
     cin >> input;
     cout << is_palindrome(input);
     break;
     }

  case 3:{
      long n, base;
      cin >> n >> base;
      cout << long_to_base(n,base);
      break;
      
  }

  case 4:{
      long n;
      cin >> n;
      cout << is_prime(n);
      break;
  }
  case 5:{
      long n;
      cin >> n;
      cout << is_pal_prime(n);
      break;
      
  }
    
  } // of switch
}  // of main
  
