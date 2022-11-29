#include <iostream>
#include <string> 
using namespace std; 


string cipher(int number, string message);

char changeLeft(char letter, int shift);

char changeRight(char letter, int shift);



int main() {
  
  string m;
  int s;

  cout << "Enter a message: " << endl;
  getline(cin,m);
  

  cout << "Enter a negative or postive number" << endl;

  cin >> s;

  m = cipher(s,m);

  cout << "\n";

  cout << "Your shifted message is: " << flush;

  cout << m << endl;

  cout << "\n";

  cout << "Your shifted number is: " << flush;

  cout << s << endl;
  
  cout << "If you want to decode the message then enter coded message but with a opposite sign shift number." << endl;

  cout << "Save your message and your shift number.\n"; 
  cout << "\n"; 
  cout << "Hide your messages, or else your cover will be blown!\n"; 
  
}

string cipher(int number, string message){
  for (int i = 0;i < message.length(); i++)
    {
      message[i] = tolower(message[i]);
      if (number < 0){
      message[i] = changeLeft(message[i], number);
      }
      else if (number > 0)
      {
      message[i] = changeRight(message[i],number);
      }
    }
  return message;
}

char changeLeft(char letter, int shift){
  for (int i = shift; i < 0; i++)
  {
    if(letter == 'a')
    {
    letter = 'z';  
    }
    else if(isblank(letter))
    {
      return ':';
    }
    else if(letter == ':')
    {
      return ' ';
    }
    else if (ispunct(letter))
    {
      return letter;
    }
    else
    {
      letter--;
    }
  }
  return letter;
}

char changeRight(char letter, int shift){
  for (int i = shift; i > 0; i--)
  {
    if(letter == 'z')
    {
    letter = 'a';  
    }
    else if(isblank(letter))
    {
      return ':';
    }
    else if(letter == ':')
    {
      return ' ';
    }
    else if (ispunct(letter))
    {
      return letter;
    }
    else
    {
      letter++;
    }
  }
  return letter;
}