/*
Extract Unique characters
Send Feedback
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

#include<unordered_map>
#include<string.h>
char* uniqueChar(char *s){
    // Write your code here
  unordered_map<char,int> exists; 
  int index = 0; 
    int n=strlen(s);
  for(int i=0;i<n;i++){ 
    if(exists[s[i]]==0) 
    { 
      s[index++] = s[i]; 
      exists[s[i]]++; 
    } 
  } 
	s[index]='\0';
  return s; 
}

/*
#include<unordered_map>
char* uniqueChar(char *str){
    // Write your code here
    unordered_map<char,int> mymap;
    char *output = new char[100000];
    int j=0;
    for(int i=0;str[i]!='\0';i++){
        if(!mymap.count(str[i])){
            mymap[str[i]]=1;
            output[j]=str[i];
            j++;
    	}
    }
        output[j]='\0';
    return output;
    
}
*/