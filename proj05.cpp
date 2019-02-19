// beaufort cipher, http://practicalcryptography.com/ciphers/classical-era/beaufort/

#include<iostream>
using std::cout; using std::cin; using std::endl;
#include<string>
using std::string;
#include<algorithm>
using std::rotate;


const string alphabet = "abcdefghijklmnopqrstuvwxyz";


string rotate_left(int move, string init_string){
  for (int i=0; i < move; i++){
      rotate(init_string.begin(), init_string.begin()+1,init_string.end());
  }//End of For loop
  return init_string;
}//End of rotate_left function


char beaufort_letter(char p_text, char key){
    if(isalpha(p_text) and isalpha(key)){
        if(islower(p_text) and islower(key)){
         int x = alphabet.find(p_text);
         string string_alpha = alphabet;
         string rotated_alpha = rotate_left(x,string_alpha);
         int y = rotated_alpha.find(key);
         return
            alphabet[y];
        }
        else
        return p_text;
    }
    else
    return p_text;
}//End of beaufort_letter function

char vigenere_letter(char p_text, char key){
    if(isalpha(p_text) and isalpha(key)){
        if(islower(p_text) and islower(key)){
         int x = alphabet.find(p_text);
         string string_alpha = alphabet;
         string rotated_alpha = rotate_left(x,string_alpha);
         int y = alphabet.find(key);
         return
            rotated_alpha[y];
        }
        else
        return p_text;
    }
    else
    return p_text;
}//End of vigenere_letter function

string encode_beaufort(string p_text, string key_s){
    string cipher_text = "";
    for (int i=0; i<p_text.length(); i++){
        if (isalpha(p_text[i]))
            cipher_text += p_text[i]; 
    }
    int length = cipher_text.length();
    int count_i = key_s.length();
    int count_loop = 0;
    while(key_s.length() != length){
        if (count_loop == count_i)
            count_loop = 0;
        else{
            key_s = key_s + key_s[count_loop];
            count_loop++;
        }
    }
    for (int i=0; i< length; i++){
        if (isalpha(cipher_text[i]) and islower(cipher_text[i])){
            cipher_text[i] = beaufort_letter(cipher_text[i],key_s[i]);
        }
        else
            break;
    }
    return cipher_text;
}//End of encode_beaufort function

string encode_vigenere(string p_text, string key_s){
string cipher_text = "";
    for (int i=0; i<p_text.length(); i++){
        if (isalpha(p_text[i]))
            cipher_text += p_text[i]; 
    }
    int length = cipher_text.length();
    int count_i = key_s.length();
    int count_loop = 0;
    while(key_s.length() != length){
        if (count_loop == count_i)
            count_loop = 0;
        else{
            key_s = key_s + key_s[count_loop];
            count_loop++;
        }
    }
    for (int i=0; i< length; i++){
        if (isalpha(cipher_text[i]) and islower(cipher_text[i])){
            cipher_text[i] = vigenere_letter(cipher_text[i],key_s[i]);
        }
        else
            break;
    }
    return cipher_text;
}//End of encode_vigenere function


int main (){
  int case_number;
  cin >> case_number;

  switch (case_number){

  case 1: {
    int rotations;
    cin >> rotations;
    string s;
    cin >> s;
    cout << rotate_left(rotations, s) << endl;
    break;
  }
 
  case 2: {
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << beaufort_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 3:{
    char plain_letter;
    char key_letter;
    cin >> plain_letter >> key_letter;
    cout << vigenere_letter(plain_letter, key_letter) << endl;
    break;
  }

  case 4:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_beaufort(plain_text, key) << endl;
    break;
  }

  case 5:{
    string plain_text;
    string key;
    cin.ignore(100, '\n');
    getline(cin, plain_text);
    getline(cin, key);
    cout << encode_vigenere(plain_text, key) << endl;
    break;
  }

  } // of switch
} // of main
