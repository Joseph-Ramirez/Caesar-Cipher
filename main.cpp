#include <iostream>
#include <string> 
using namespace std; 



string cipher (int shift, string message);
char shiftLeft(char letter, int shift);
char shiftRight(char letter, int shift);

int main() {
 
  string message;
  int shift;

  cout << "Please enter a message: " << endl;

  getline(cin, message);
  

  cout << "Enter a positive or negative number (no decimals) \nfor your message to shift by" << endl;

  cin >> shift;

  message = cipher(shift, message);

 cout << "Your hidden message: " << message << endl;


  cout << "Save your message and your shift number.\n"; 
  cout << "\n"; 
  cout << "Hide your messages, or else your cover will be blown!\n"; 
  
}


string cipher(int shift, string message){
  for (int i = 0; i < message.length(); i++){
    message[i] = tolower(message[i]);

    if (shift < 0){
      message[i] = shiftLeft(message[i], shift);
    }
    else if (shift > 0){
      message[i] = shiftRight(message[i], shift);
    }
  }
  return message;
}

char shiftLeft(char letter, int shift){
  for (int i = shift; i < 0; i++){
    if (letter == 'a'){
      letter = 'z';
    }
    else if(isblank(letter)){
      return ';';
    }
    else if(letter == ':'){
      return ' ';
    }
    else if(ispunct(letter)){
      return letter;
    }
    else{
      letter--;
    }
  }
  return letter;
}

char shiftRight(char letter, int shift){
  for (int i = shift; i > 0; i--){
    if (letter == 'z'){
      letter = 'a';
    }
    else if (isblank(letter)){
      return ';';
    }
    else if (letter == ':'){
      return ' ';
    }
    else if (ispunct(letter)){
      return letter;
    }
    else {
      letter++;
    }
  }
  return letter;
}
