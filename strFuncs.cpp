#include "strFuncs.h"
#include <cctype>

using namespace std;


/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 *
 * Palindromes are NOT case-sensitive - "RaCecaR" is a valid palindrome
 *
 *You should provide a recursive solution*/
bool isPalindrome(const string s1){
    // base case 1: string only contains one character, always return true.
    if (s1.length() == 1) {
        return true;
    }
    // base case 2: string only contains two characters.
    if (s1.length() == 2) {
        if (tolower(s1[0]) == tolower(s1[1])) {
            return true;
        }
        return false;
    }
    // return false if head and tail do not match.
    if(tolower(s1[0]) != tolower(s1[s1.length()-1])) {
        return false;
    }
    // recursive case: check the substring containing middle elements.
    return isPalindrome(s1.substr(1,s1.length()-2));
}
