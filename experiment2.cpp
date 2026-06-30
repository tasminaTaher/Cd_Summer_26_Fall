

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void lexical(string input)
{
    string keyword[] = {"int","float","char","double","if","else","for","while","return","cout","cin","else if","switch","do"};
    string op[] = {"+","-","*","/","%","=","<<",">>","==","!=","<",">","<=",">="};
    string punc[] = {"(",")","{","}",";",",","\""};

    input += " ";

    int start = 0;

    for(int end = 0; end < input.length(); end++)
    {
        if(input[end] == ' ')
        {
            string token = "";

            // Store token
            for(int i = start; i < end; i++)
            {
                token += input[i];
            }

            if(token != "")
            {
                bool found = false;

                // Keyword
                for(int i = 0; i < 11; i++)
                {
                    if(token == keyword[i])
                    {
                        cout << token << " -> Keyword\n";
                        found = true;
                        break;
                         }
                }

                // Operator
                if(!found)
                {
                    for(int i = 0; i < 14; i++)
                    {
                        if(token == op[i])
                        {
                            cout << token << " -> Operator\n";
                            found = true;
                            break;
                        }
                    }
                }

                // Punctuation
                if(!found)
                {
                    for(int i = 0; i < 7; i++)
                    {
                        if(token == punc[i])
                        {
                            cout << token << " -> Punctuation\n";
                            found = true;
                            break;
                        }
                    }
                }

                // Identifier
                if(!found)
                {
                    bool id = true;

                    if(!(isalpha(token[0]) || token[0] == '_'))
                        id = false;

                    for(int i = 1; i < token.length() && id; i++)
                    {
                        if(!(isalnum(token[i]) || token[i] == '_'))
                            id = false;
                    }

                    if(id)
                    {
                        cout << token << " -> Identifier\n";
                        found = true;
                    }
                }

                // Numeric Constant
                if(!found)
                {
                    bool num = true;
                    int dot = 0;

                    for(int i = 0; i < token.length(); i++)
                    {
                        if(token[i] == '.')
                            dot++;
                        else if(!isdigit(token[i]))
                            num = false;
                    }

                    if(dot > 1)
                        num = false;

                    if(num)
                    {
                        cout << token << " -> Numeric Constant\n";
                        found = true;
                    }
                }

                // Invalid Token
                if(!found)
                {
                    cout << token << " -> It is not lexical.";
                    return;
                }
            }

            start = end + 1;
        }
    }

    cout << "\nAll tokens are valid.";
}

int main()
{
    string input;

    cout << "Enter Statement: ";
    getline(cin, input);

    lexical(input);

    return 0;
}

