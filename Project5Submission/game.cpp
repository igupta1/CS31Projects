#include "utilities.h"
#include <iostream>
#include <iomanip>
#include <cstring>
#include <cctype>

using namespace std;

const char WORDFILENAME[] = "/Users/ishaangupta/Desktop/Project5/words.txt";
const int MAXWORDS = 9000;

int playOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum);

int main()
{
    char wordList[MAXWORDS][MAXWORDLEN + 1];
    int nWords = getWords(wordList, MAXWORDS, WORDFILENAME);
    int numRounds;
	double average = 0;
	int min = 0;
	int max = 0;
	int totalAttempts = 0;
    
    //if the number of words is zero or negative, terminate the program
	if (nWords <= 0)
    {
        cout << "No words were loaded, so I can't play the game." << endl;
        return 0;
    }
    
    cout << "How many rounds do you want to play? ";
    cin >> numRounds;
	
	cin.ignore(10000, '\n');
	
	//if the user enters an invalid number of rounds terminate the program
	if (numRounds <= 0)
	{
		cout << "The number of rounds must be positive." << endl;
		return 0;
	}
	
    cout << endl;
	
	
    for (int i = 1; i <= numRounds; i++)
    {
        cout << "Round " << i << endl;
		int randNum = randInt(0, nWords - 1);
        int randWordLength = (int)(strlen(wordList[randNum]));
		cout << "The hidden word is " << randWordLength << " letters long." << endl;
		
		cerr << "HIDDEN WORD IS " << wordList[randNum] << endl;
        
		//call playOneRound to get the score
		int tries = playOneRound(wordList, nWords, randNum);
		
		if (tries == -1)
		{
			cout << "ERROR" << endl;
			return 0;
		}
		
		if (tries == 1)
		{
			cout << "You got it in 1 try." << endl;
		}
		else
		{
			cout << "You got it in " << tries << " tries." << endl;
		}
		
		totalAttempts += tries;
		average = (totalAttempts * 1.0) / i;
		if (i == 1)
		{
			min = tries;
		}
		if (tries < min)
		{
			min = tries;
		}
		if (tries > max)
		{
			max = tries;
		}
		
		cout << fixed << setprecision(2) << "Average: " << average << ", minimum: " << min << ", maximum: " << max << endl;
		cout << endl;
    }
	
	
    
}

//this method plays one round of the game and returns the score
int playOneRound(const char words[][MAXWORDLEN + 1], int nWords, int wordnum)
{
	//if the number of words is not positive, the index of the word chosen is negative or greater than the number of words then terminate the method
	if ((nWords <= 0) || (wordnum < 0) || (wordnum >= nWords))
    {
        return -1;
    }
	
	char probeWord[110];
	
	probeWord[0] = '\0';
	
	int tries = 0;
	
	//while the probe word is not the same as the hidden word
    while (strcmp(probeWord, words[wordnum]) != 0)
    {
		bool foundInHidden[6] = {false, false, false, false, false, false};
		bool foundInProbe[6] = {false, false, false, false, false, false};
		int goldCount = 0;
		int silverCount = 0;
		bool rightSizeAndLowercase = false;
		bool validWordInArray = false;
		
		cout << "Probe word: ";
		cin.getline(probeWord, MAXWORDS);
		
		
		//look in the list of words for the probeWord and if its there set validWordInArray to be true
		for (int i = 0; i < nWords; i++)
		{
			if (strcmp(words[i], probeWord) == 0)
			{
				validWordInArray = true;
			}
		}
		
		//check to see if the length of the probe word is correct
		if ((int)strlen(probeWord) >= 4 && (int)strlen(probeWord) <= 6)
		{
			rightSizeAndLowercase = true;
		}
		
		//check to see if the words is all lowercase
		for (int i = 0; i < strlen(probeWord); i++)
		{
			if (!islower(probeWord[i]))
			{
				rightSizeAndLowercase = false;
			}
		}
		
		//if its not the right size and all lowercase print error message
		if (!rightSizeAndLowercase)
		{
			cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
		}
		
		//if its not a valid word in the word list print error message
		else if (!validWordInArray)
		{
			cout << "I don't know that word." << endl;
		}
		
		
		if (rightSizeAndLowercase && validWordInArray)
		{
			//find length of shorter word
			int minLen;
			if (strlen(words[wordnum]) < strlen(probeWord))
			{
				minLen = (int)strlen(words[wordnum]);
			}
			else
			{
				minLen = (int)strlen(probeWord);
			}
			
			//look for the golds by iterating through the array and looking for matches in the same indices and once a match is found set the flag to true
			for (int i = 0; i < minLen; i++)
			{
				if (words[wordnum][i] == probeWord[i])
				{
					foundInHidden[i] = true;
					foundInProbe[i] = true;
					goldCount ++;
				}
			}
			
			//look for silvers by iterating through the hidden word
			for (int i = 0; i < strlen(words[wordnum]); i++)
			{
				//if a gold was not found for that character
				if (!foundInHidden[i])
				{
					//iterate through all the characters for the probe word
					for (int j = 0; j < strlen(probeWord); j++)
					{
						//if a silver was already found
						if (!foundInProbe[j])
						{
							//if a match is found set the flag to true and break so it doesnt look for a duplicate
							if (words[wordnum][i] == probeWord[j])
							{
								foundInHidden[i] = true;
								foundInProbe[j] = true;
								silverCount++;
								break;
							}
						}
					}
				}
			}
	
			tries++;
		}
		//if its the right word, exit the method and return the score
		if (strcmp(probeWord, words[wordnum]) == 0)
		{
			return tries;
		}
		
		if ((validWordInArray) && (rightSizeAndLowercase))
		{
			cout << "Golds: " << goldCount << ", Silvers: " << silverCount << endl;
		}

    }
	
	return 1;
												
	
}
