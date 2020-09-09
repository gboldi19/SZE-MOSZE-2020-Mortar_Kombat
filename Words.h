#include <string>
#include <vector>

using namespace std;

class Words
{
private:
    vector<string> wordVector;
public:
    Words(string input);
    string getWord(int pos);
};
