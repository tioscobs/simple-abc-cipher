#include <iostream>
#include <string>
#include <vector>

using namespace std;

string cipher_text, raw_text;

void encript(int char_int){
  string cipher_char;
  switch (char_int)
  {
    case 65:
      cipher_char = "0A";
      break;
    case 66:
      cipher_char = "0B";
      break;
    case 67:
      cipher_char = "0C";
      break;
    case 68:
      cipher_char = "0AB";
      break;
    case 69:
      cipher_char = "0AC";
      break;
    case 70:
      cipher_char = "0BA";
      break;
    case 71:
      cipher_char = "0BC";
      break;
    case 72:
      cipher_char = "0CA";
      break;
    case 73:
      cipher_char = "0CB";
      break;
    case 74:
      cipher_char = "1A";
      break;
    case 75:
      cipher_char = "1B";
      break;
    case 76:
      cipher_char = "1C";
      break;
    case 77:
      cipher_char = "1AB";
      break;
    case 78:
      cipher_char = "1AC";
      break;
    case 79:
      cipher_char = "1BA";
      break;
    case 80:
      cipher_char = "1BC";
      break;
    case 81:
      cipher_char = "1CA";
      break;
    case 82:
      cipher_char = "1CB";
      break;
    case 83:
      cipher_char = "2A";
      break;
    case 84:
      cipher_char = "2B";
      break;
    case 85:
      cipher_char = "2C";
      break;
    case 86:
      cipher_char = "2AB";
      break;
    case 87:
      cipher_char = "2AC";
      break;
    case 88:
      cipher_char = "2BA";
      break;
    case 89:
      cipher_char = "2BC";
      break;
    case 90:
      cipher_char = "2CA";
      break;
    case 32:
      cipher_char = "2CB";
      break;
    default:
      cipher_char = "*";
      break;
  }
  cipher_text = cipher_text + cipher_char;
}

vector<int> format_input(string raw_text){
  for(char letter : raw_text){
    encript(int(toupper(letter)));
  }
  cout << "Cipher Text: " << cipher_text << endl;
}

int main(){
    cout << "Input Text: ";
    cin >> raw_text;

    format_input(raw_text);

    return 0;
}