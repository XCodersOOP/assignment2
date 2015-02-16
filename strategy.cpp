//Date        ID       Description
//--------------------------------------
//20150216   13208316  Added indentation to code to make it more readable.
//--------------------------------------

#include "strategy.h"

void FileProcessor::outputFile()
{
    char line[MAX_LINE_LEN];
    ifstream inFile(filename_.c_str(), ios::in);
    line[0] = '\0';

    while (inputLine(inFile, line) != -1)
    {
            justify(line);
            cout << line;
    }
}

void FileProcessor::justify(char *line)
{
    formatter->justify(line, width_);
}


int FileProcessor::inputLine(ifstream& inFile, char *line)
{
    char word[MAX_LINE_LEN];
    bool success;
    inFile >> word;
    if (inFile.fail())
        return -1;

    strcat(line, word);
    strcat(line, " ");
    int len;
    while ((success = inFile >> word) && (len = strlen(line) + strlen(word) + 1) < width_)
    {
        strcat(line, word);
        strcat(line, " ");
    }
    if (success && len>=width_)
    {
        for (unsigned int i=0;i<strlen(word);i++)
            inFile.unget();
    }
    return 1;
}


int UpperCaseFileProcessor::inputLine(ifstream& inFile, char *line)
{
    char word[MAX_LINE_LEN];
    bool success;
    inFile >> word;
    if (inFile.fail())
        return -1;
    for (unsigned int i=0;i<strlen(word);i++)
        if ('a'<=word[i] && 'z'>=word[i])
            word[i] = word[i]+'A'-'a';

    strcat(line, word);
    strcat(line, " ");
    int len;
    while ((success = inFile >> word) && (len = strlen(line) + strlen(word) + 1) < width_)
    {
        for (unsigned int i=0;i<strlen(word);i++)
            if ('a'<=word[i] && 'z'>=word[i])
                word[i] = word[i]+'A'-'a';

        strcat(line, word);
        strcat(line, " ");
      }
    if (success && len>=width_)
    {
        for (unsigned int i=0;i<strlen(word);i++)
            inFile.unget();
    }
    return 1;
}


void LeftFormatter::justify(char *line, int width)
{
    cout << line << endl;
    line[0] = '\0';
}


void RightFormatter::justify(char *line, int width)
{
    char buf[MAX_LINE_LEN];
    int offset = width - strlen(line);
    memset(buf, ' ', MAX_LINE_LEN);
    strcpy(&(buf[offset]), line);
    cout << buf << endl;
    line[0] = '\0';
}


void CenterFormatter::justify(char *line, int width)
{
    char buf[MAX_LINE_LEN];
    int offset = (width - strlen(line)) / 2;
    memset(buf, ' ', MAX_LINE_LEN);
    strcpy(&(buf[offset]), line);
    cout << buf << endl;
    line[0] = '\0';
}

