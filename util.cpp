#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;

std::string convToLower(std::string src) {
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

std::set<std::string> parseStringToWords(string rawWords) {
    // Define a set to store the parsed keywords
    set<string> keywords;

    // Convert the string to lowercase
    rawWords = convToLower(rawWords);

    // Use stringstream to tokenize the string by whitespace
    std::stringstream ss(rawWords);
    std::string word;
    while (ss >> word) {
        // Remove leading and trailing spaces from each word
        word = trim(word);

        // If the word has at least 2 characters, add it to the set of keywords
        if (word.length() >= 2) {
            keywords.insert(word);
        } else {
            // If the word has less than 2 characters, continue to the next word
            continue;
        }

        // Split the word by punctuation and add resulting substrings (with at least 2 characters) to keywords
        std::string substring;
        for (char& c : word) {
            if (std::isalnum(c)) {
                // Append alphanumeric characters to the substring
                substring += c;
            } else {
                // If a punctuation character is encountered, add the substring to keywords if it has at least 2 characters
                if (substring.length() >= 2) {
                    keywords.insert(substring);
                }
                // Clear the substring for the next sequence of characters
                substring.clear();
            }
        }
        // Add the remaining substring if it has at least 2 characters
        if (substring.length() >= 2) {
            keywords.insert(substring);
        }
    }

    return keywords;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
        std::find_if(s.begin(), 
            s.end(), 
            std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
        std::find_if(s.rbegin(), 
            s.rend(), 
            std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
        s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}
