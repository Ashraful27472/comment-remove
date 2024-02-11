#include <bits/stdc++.h>
using namespace std;

int multi_line_comments_conter{0}, single_line_comment_conter{0};

string removeComments(string src)
{

    string result;
    bool single_line_comment{false}, multi_line_comment{false};

    for (int i = 0; i < src.length(); i++)
    {

        if (src[i] == '/' and src[i + 1] == '/')
            single_line_comment = true, i++;

        else if (src[i] == '/' and src[i + 1] == '*')
            multi_line_comment = true, i++;

        else if (src[i] == '\n' and single_line_comment)
            single_line_comment = false, single_line_comment_conter++;

        else if (src[i] == '*' and src[i + 1] == '/' and multi_line_comment)
            multi_line_comment = false, i++, multi_line_comments_conter++;

        else if (single_line_comment or multi_line_comment)
            continue;

        else
            result.push_back(src[i]);
    }

    return result;
}

int main()
{

    ifstream file("Input.cpp");
    string source;

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
            source += line + "\n";
        file.close();
    }

    cout << "sor" << endl;
    cout << source << endl;

    cout << endl;
    cout << removeComments(source) << endl;
    cout << "filter:" << endl;

    cout << endl;
    cout << "Single Line Comments: " << single_line_comment_conter << endl;
    cout << "Multi  Line Comments: " << multi_line_comments_conter << endl;

    return 0;
}
