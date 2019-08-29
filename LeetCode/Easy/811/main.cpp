/**
 * A website domain like "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com", and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
 * Now, call a "count-paired domain" to be a count (representing the number of visits this domain received), followed by a space, followed by the address. An example of a count-paired domain might be "9001 discuss.leetcode.com".
 * We are given a list cpdomains of count-paired domains. We would like a list of count-paired domains, (in the same format as the input, and in any order), that explicitly counts the number of visits to each subdomain.
*/

#include "../headers/leetcode.h"
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h> 

using namespace std;

int getNum(string s) {
    int index = 0;
    while(s[index] != '_' && index < s.length() - 1) {
        index++;
    }
    return stoi(s.substr(0, index));
}

vector<string> split(string s, char c) {
    vector<string> result;
    if (s.find(c) != string::npos) {
        int i = s.find(c);
        result.push_back(s.substr(0, i));
        result.push_back(s.substr(i + 1, s.length() - i - 1));
    }
    else {
        result = {s};
    }
    return result;
}

//TODO: Find a easier way, remove redundant code
vector<string> subdomainVisits(vector<string>& cpdomains) {

    vector<string> result = cpdomains, visited;
    map<string, int> domainLists;

    for (string domain : cpdomains) {
        int prefix = getNum(domain);
        vector<string> sub_domains = split(split(domain, '.')[1], '.');
        int size = sub_domains.size();

        for (int i = 0; i < size; i++) {
            if (domainLists.find(sub_domains[i]) == domainLists.end()) {
                domainLists.insert(pair<string, int>(sub_domains[i], prefix));
            }
            else {
                domainLists[sub_domains[i]] += prefix;
            }
        }
    }

    for (int i = 0; i < cpdomains.size(); i++) {

        string suffix = split(cpdomains[i], '.')[1];
        if (find(visited.begin(), visited.end(), suffix) == visited.end()) {
            visited.push_back(suffix);
        }
        else {
            continue;
        }

        vector<string> sub_domains = split(split(cpdomains[i], '.')[1], '.');
        int size = sub_domains.size();
        int num = domainLists[sub_domains[0]];

        if (size > 1) {
            string d = to_string(num) + " " + sub_domains[0] + "." + sub_domains[1];
            result.push_back(d);

            num = domainLists[sub_domains[1]];
            string m = to_string(num) + " " + sub_domains[1];
            result.push_back(m);

            visited.push_back(sub_domains[1]);
        }
        else {
            string d = to_string(num) + " " + sub_domains[0];
            result.push_back(d);
        }

    }
    return result;
}

int main (int argc, char const *argv[])
{
    #ifndef ONLINEJUDGE
    freopen("main.in", "r", stdin);
    #endif
    int m = readNumber();
    for (int i = 0; i < m; ++i) {
        int n = readNumber();
        vector<string> cpdomains = readStringVector(n);
        printVector(subdomainVisits(cpdomains));
    }
    return 0;
}