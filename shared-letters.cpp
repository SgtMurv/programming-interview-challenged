#include <iostream>
#include <vector>
using namespace std;

int sharedLettersFaster(string word1, string word2)
{
	//
	return 0;
}

int sharedLettersSlow(string word1, string word2)
{
	vector<char> sharedLetters;

	// go through each letter of the shortest word and see if it is present in the longest word.
	for (int i = 0; i < word1.length(); i++)
	{
		for (int j = 0; j < word2.length(); j++)
		{
			// check if it is in the
			if (sharedLetters)
				if (word1[i] == word2[j])
				{
					// if it is then add it to the vector.
					sharedLetters.push_back(word1[i]);
					break;
				}
		}
	}
	return sharedLetters.size();
}

int main()
{
	// cout << sharedLettersSlow("bcda", "cbad") << endl;
	// cout << sharedLettersSlow("dcba", "abcd") << endl;
	cout << sharedLettersSlow("f", "fff") << endl;

	return 0;
}