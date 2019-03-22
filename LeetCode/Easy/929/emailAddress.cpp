/**
 * Every email consists of a local name and a domain name, separated by the @ sign.
 * For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.
 * Besides lowercase letters, these emails may contain '.'s or '+'s.
 * If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  
 * For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)
 * If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. 
 * This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)
 * It is possible to use both of these rules at the same time.
 * Given a list of emails, we send one email to each address in the list.  
 * How many different addresses actually receive mails?
*/

#include <iostream>
#include "../headers/leetcode.h"
#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

int numUniqueEmails(vector<string>& emails) {
    // for(int i = 0; i < emails.size(); i++) {
    //     cout << emails[i] << endl;
    // }
    // cout << endl;
    set<string> purified;

    for(string email : emails) {
        int at_index = email.find("@", 0);
        string local = email.substr(0, at_index);
        string domain = email.substr(at_index, email.length() - at_index);
        for(int i = 0; i < local.length(); i++) {
            if(local[i] == '.') {
                local.erase(i, 1);
                i--;
            }
            if(local[i] == '+') {
                local.erase(i, at_index);
            }
        }
        purified.insert(local + domain);
    }
    return purified.size();
}

int main(int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int size = readNumber();
        vector<string> emails = readStringVector(size);
        cout << numUniqueEmails(emails) << endl;
    }
    return 0;
}
