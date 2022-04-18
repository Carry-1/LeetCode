#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string >segment(string s)
{
	int length = s.size();
	string word;
	vector<string> result;
	for(int i=0; i<=length; i++)
	{
		if(i<length&&isalpha(s[i]))
		{
			word += s[i];
		}
		else if(word.size()>0)
		{
			result.push_back(word);
			word = "";
		}
	}
    return result;
}

int main()
{
    string s = "I am a poor     guy from a        poor    family.......";
    vector<string> list = segment(s);
    cout<<1<<endl;
    return 0;
}