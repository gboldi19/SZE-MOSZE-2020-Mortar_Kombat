#include "Words.h"

Words::Words(string input)
{
    string word = "";
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] != ' ')
        {
            word += input[i];
        }
        else if (word != "")
        {
            wordVector.push_back(word);
            word = "";
        }
    }
    if (word != "")
    {
        wordVector.push_back(word);
    }
}

string Words::getWord(int pos)
{
    return wordVector[pos];
}
