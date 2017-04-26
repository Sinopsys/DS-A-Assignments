//
// KUPRIYANOV KIRILL BSE151
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "dictionary.h"
#include <set>
#include <cstring>

std::string get_alphabet(void);

set<std::string> trasposing_check(std::string, Dictionary &);

set<std::string> removal_check(std::string, Dictionary &);

set<std::string> replacement_check(std::string, Dictionary &);

set<std::string> insertion_check(std::string, Dictionary &);

void lower(std::string &s);

std::string stripPunct(const std::string &s);

void checkSpelling(ifstream &in, Dictionary &dict);


int main(int argc, char *argv[])
{
    // Output usage message if improper command line args were given.
    if (argc != 3)
    {
        std::cerr << "Usage: " << argv[0] << " wordlist_filename input_file\n";
        return EXIT_FAILURE;
    }

    ifstream inf(argv[2]);
    if (!inf)
    {
        std::cerr << "Could not open " << argv[2] << "\n";
        return EXIT_FAILURE;
    }

    // Read dictionary, but let user know what we are working on.
    std::cout << "Loading dictionary, this may take awhile...\n";

    Dictionary d(argv[1]);

    checkSpelling(inf, d);

    inf.close();

    return EXIT_SUCCESS;
}

void checkSpelling(ifstream &in, Dictionary &dict)
{
    int line_number = 0;

    while (in)
    {
        ++line_number;
        std::string line;
        getline(in, line);

        stringstream ss(stringstream::in | stringstream::out);
        ss << line;

        std::string word;
        while (ss >> word)
        {
            // preprocess the word
            //
            word = stripPunct(word);
            lower(word);
            if (!dict.search(word))
            {
                // initialize a set of possible suggestions
                //
                set<std::string> suggestions;

                std::cout << "Line " << line_number << ": \'" << word << "\'"
                          << std::endl << "\tsuggestions:" << std::endl;

                // check with every method
                //
                set<std::string> check_1 = trasposing_check(word, dict);
                suggestions.insert(check_1.begin(), check_1.end());

                set<std::string> check_2 = removal_check(word, dict);
                suggestions.insert(check_2.begin(), check_2.end());

                set<std::string> check_3 = insertion_check(word, dict);
                suggestions.insert(check_3.begin(), check_3.end());

                set<std::string> check_4 = replacement_check(word, dict);
                suggestions.insert(check_4.begin(), check_4.end());

                // print all suggestions
                //
                for (const std::string &s : suggestions)
                    std::cout << "\t\t\t" << s << std::endl;
            }
        }
    }
}

set<std::string> trasposing_check(std::string word, Dictionary &dict)
{
    // save initial word
    //
    const std::string tmp(word);
    set<std::string> res;
    for (int i = 0; i < tmp.length() - 1; ++i)
    {
        word = tmp;

        // swap each letter with the next one
        //
        std::swap(word[i], word[i + 1]);

        // add to suggestions if the word appears in a dictionary
        //
        if (dict.search(word))
            res.insert(word);
    }
    return res;
}

set<std::string> removal_check(std::string word, Dictionary &dict)
{
    // save initial word
    //
    const std::string tmp(word);
    set<std::string> res;
    for (int i = 0; i < tmp.length(); ++i)
    {
        word = tmp;

        // remove every i-th char
        //
        word = word.erase(i, 1);

        // add to suggestions if the word appears in a dictionary
        //
        if (dict.search(word))
            res.insert(word);
    }
    return res;
}

set<std::string> replacement_check(std::string word, Dictionary &dict)
{
    // get alphabet string (represents like "abcd..yz")
    //
    const std::string alphabet(get_alphabet());

    // save initial word
    //
    const std::string tmp(word);
    set<std::string> res;

    // iterate through every char in word
    //
    for (int i = 0; i < tmp.length(); ++i)
        // and foreach char in the word iterate
        // through every char in the alphabet
        //
        for (const char &ch : alphabet)
        {
            word = tmp;
            word[i] = ch;

            // add to suggestions if the word appears in a dictionary
            //
            if (dict.search(word))
                res.insert(word);
        }
    return res;
}

set<std::string> insertion_check(std::string word, Dictionary &dict)
{
    const std::string alphabet(get_alphabet());

    // save initial word
    //
    const std::string tmp(word);
    set<std::string> res;

    // for every position
    //
    for (int i = 0; i < tmp.length() + 1; ++i)
        // check every alphabetical char to fit in the position
        //
        for (const char &ch : alphabet)
        {
            word = tmp;
            word.insert(i, 1, ch);

            // add to suggestions if the word appears in a dictionary
            //
            if (dict.search(word))
                res.insert(word);
        }
    return res;
}

/**
 * a function to get an alphabet string
 * @return "abcde..xyz"
 */
std::string get_alphabet(void)
{
    char curr_letter = 'a';
    std::string alphabet = "";
    while (curr_letter <= 'z')
    {
        alphabet += curr_letter;
        curr_letter++;
    }
    return alphabet;
}


void lower(std::string &s)
{
    // Ensures that a word is lowercase
    for (unsigned int i = 0; i < s.length(); ++i)
        s[i] = (char) tolower(s[i]);
}

std::string stripPunct(const std::string &s)
{
    // Remove any single trailing
    // punctuation character from a word.
    if (ispunct(s[s.length() - 1]))
        return s.substr(0, s.length() - 1);

    return s;
}


// EOF
