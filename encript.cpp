#include <iostream>
#include <fstream>
#include <string>
#include <json.hpp>

using namespace std;
using json = nlohmann::json;

ifstream cipher_file("cipher.json");
json cipher = json::parse(cipher_file);

string encript(string raw_text){
  string temp_cipher;
  for(char char_to_encode : raw_text){
    string str = string(1, toupper(char_to_encode));
    temp_cipher = temp_cipher + cipher[str].get<string>();
  }
  return temp_cipher;
}

int main(){
    string cipher_text, raw_text;
    cout << "Input Text: ";
    getline(cin, raw_text);

    cipher_text = encript(raw_text);
    cout << "Output Text: " << cipher_text << endl;

    system("pause");

    return 0;
}