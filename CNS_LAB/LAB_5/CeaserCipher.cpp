#include <bits/stdc++.h>
using namespace std;

string ceaserCipher(int key, string text) {
   int idx;
   string encryptedText;

   for(char c :text) {
      if(c >= 'a' && c <= 'z') {
         idx = c - 'a';
         idx = (idx + key) % 26;
         c = 'a' + idx;
      }
      else if(c >= 'A' && c <= 'Z') {
         idx = c - 'A';
         idx = (idx + key) % 26;
         c = 'A' + idx;
      }

      encryptedText.push_back(c);
   }

   return encryptedText;
}

int main() {
   int key;
   string text;
   
   cout<<"Enter key : ";
   cin>>key;

   cout<<"Enter message : ";
   cin>>text;

   cout<<"Encrypted message : "<<ceaserCipher(key, text)<<endl;
}