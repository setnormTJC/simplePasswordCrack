//the 

#include <iostream>

#include<string>

#include<algorithm>

#include<vector> 


using std::vector; 
using std::string; 
using std::cout; 

static long long guessCount = 0; 



/*modified version of GeeksForGeeks approach:*/
/*a recursive function
complexity is stringLength^characterSetSize 
(approximately O(N^N)) 
*/
void printAllString_OfGivenLength_WithGivenCharSet
(vector<char> characterSet, string outputString,
    int characterSetSize, int stringLength, 
    const string& correctPassword)
{
    //******
    guessCount++; 

    if (stringLength == 0)
    {
        //only display every 50,000 guesses - for "long" passwords 
        //if (guessCount % 50'000 == 0)
        //{
            cout << outputString << "\n"; 

        //}

        if (outputString == correctPassword)
        {
            cout << outputString << "\n";

            cout << "Found!\n";
            system("pause");
        }

        return; //to previous function call in stack (not "to OS")
    }

    //implied else 
    for (int i = 0; i < characterSetSize; i++)
    {
        string newOutputString; 

        newOutputString = outputString + characterSet[i]; 

        //recursive call: (note that this call is inside a loop) 
        printAllString_OfGivenLength_WithGivenCharSet
            (characterSet, newOutputString, characterSetSize, stringLength - 1, 
                correctPassword);
    }

}
int main()
{

    //std::locale l("");
    //cout.imbue(l);

    //cout << LLONG_MAX << "\n";


    //vector<char> firstFourLetters = { 'a', 'b', 'c', 'd' }; 
    vector<char> lowercaseLetters; 
    
    //small test case: 
    //for (char i = 'a'; i <= 'd'; i++)
    //{
    //    lowercaseLetters.push_back(i); 
    //}

    for (char i = 'a'; i <= 'z'; i++)
    {
        lowercaseLetters.push_back(i); 
    }
    //add characters 0 - 9
    for (char i = '0'; i <= '9'; i++)
    {
        lowercaseLetters.push_back(i); 
    }


    //std::next_permutation(firstFourLetters.begin(), firstFourLetters.end());

    //for (auto& letter : firstFourLetters)
    //{
    //    std::cout << letter << "\n";
    //}

    std::string correctPassword = "pswd";
    //cout << "Enter lowercase 4 letter word (or 4 letter nonsense): \n";
    cout << "Enter a password \n";
    std::getline(std::cin, correctPassword);

    system("cls");

    cout << "Finding via brute force ...\n";

    printAllString_OfGivenLength_WithGivenCharSet(lowercaseLetters, "", lowercaseLetters.size(),
        correctPassword.length(), correctPassword); 


    //the "dumb" approach -> nested for loops 
    //LIMITED to 4 chars 
    for (char i = 'a'; i <= 'z'; i++)
    {
        std::string guessedPassword = "____"; //assumes known-length password 
        
        guessedPassword[0] = i;
        //O(N^M) -> N is the password length and M is the number of allowed characters

        for (int j = 'a'; j <= 'z'; j++)
        {
            guessedPassword[1] = j;

            for (int k = 'a'; k <= 'z'; k++)
            {
                guessedPassword[2] = k;

                for (int l = 'a'; l <= 'z'; l++)
                {
                    guessedPassword[3] = l;

                    //std::cout << guessedPassword << "\n";

                    if (guessedPassword == correctPassword)
                    {
                        //return 1;
                    }
                }
            }
        }
    }



    std::cout << "Hello World!\n";
}

