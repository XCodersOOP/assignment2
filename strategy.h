//Date        ID       Description
//--------------------------------------
//20150216   13208316  Added indentation to code to make it more readable.
//--------------------------------------

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

#define MAX_LINE_LEN 80
#define MIN_LINE_LEN 10

/* Formatter is a class that provides a function called justify() that will write out a line 
   using a particular type of justification.  Its subclasses, LeftFormatter, RightFormatter and CenterFormatter
   implement the three different types of justification */

class Formatter
{
    public:
        Formatter()
        {
        };
        virtual ~Formatter() 
        {
        };
        virtual void justify(char *line, int width) = 0;
private:
};


/* FileProcessor is a class that provides the following functions:

   inputLine() : reads a line of an input file.
   justify() : applies an appropriate Formatter to a line read from the file, to format with left, right or centre justification
   outputFile() : uses inputLine() to read each line in turn from the file, pass the line to justify() and finally write the
                  formatted line to the console.

   Subclasses of FileProcessor input the line from the file in different ways:

   UpperCaseFileProcessor implements inputLine() to read a line of words and covert the words to uppercase.

*/

class FileProcessor
{
    public:
        void outputFile();
          public:  FileProcessor(char *fname, int width) : width_(max(MIN_LINE_LEN ,min(width,MAX_LINE_LEN))), filename_(fname),formatter(0) 
        {
        };
        virtual ~FileProcessor() 
        {
        };
    protected:
        virtual int inputLine(ifstream& fp, char *line);
        void justify(char *line);
        int width_;
        string filename_;
	Formatter *formatter;
};


/* UpperCaseFileProcessor is the subclass of FileProcessor that implements inputLine
   so that the next line is read from the file and converted to UpperCase. */

class UpperCaseFileProcessor : public FileProcessor
{
    public:
        UpperCaseFileProcessor(char *fname, int width) : FileProcessor(fname, width) 
        {
        };
        virtual ~UpperCaseFileProcessor() 
        {
        };
    private:
	int inputLine(ifstream& inFile, char *line);
};

/* LeftFormatter implements the justify() function so that lines are written out with
   left justification */

class LeftFormatter : public Formatter
{
    public:
        LeftFormatter() 
        {
        };
        ~LeftFormatter() 
        {
        };
        void justify(char *line, int width);
};

/* RightFormatter implements the justify() function so that lines are written out with
   right justification */

class RightFormatter: public Formatter
{
    public:
        RightFormatter() 
        {
        };
        ~RightFormatter() 
        {
        };
	void justify(char *line, int width);
};


/* CenterFormatter implements the justify() function so that lines are written out with
   center justification */

class CenterFormatter: public Formatter
{
	public:
            CenterFormatter() 
            {
            };
            ~CenterFormatter() 
            {
            };
            void justify(char *line, int width);
};

class ProcessorLeft : public FileProcessor
{
	public:
            ProcessorLeft(char *fname, int width) : FileProcessor(fname, width) 
            { 
                formatter = new LeftFormatter; 
            };
            ~ProcessorLeft()  {
                if (formatter)
                    delete (LeftFormatter *)formatter;
            };
};

class ProcessorRight : public FileProcessor
{
	public:
		ProcessorRight(char *fname, int width) : FileProcessor(fname, width) 
		{ 
                    formatter = new RightFormatter; 
		}
		~ProcessorRight() 
		{
                    if (formatter)
			delete (RightFormatter *)formatter;
		};
};

class ProcessorCenter : public FileProcessor
{
	public:
            ProcessorCenter(char *fname, int width) : FileProcessor(fname, width) 
            { 
                formatter = new CenterFormatter; 
            }
            ~ProcessorCenter() 
            {
                if (formatter)
                    delete (CenterFormatter *)formatter;
            };
};

/*  TO BE COMPLETED:  DEFINE THE THREE CLASSES ProcessorUpperCaseLeft, ProcessorUpperCaseRight and ProcessorUpperCaseCentre 
    so that the TestBed code can write out the given file in upper case using the specified justification */






