//Date        ID       Description
//--------------------------------------
//20150216   13208316  Added indentation to code to make it more readable.
//--------------------------------------
#include "strategy.h"

class TestBed
{
    public:
        enum ProcessorType
        {
            Dummy, Left, Right, Center, ULeft, URight, UCenter
        };
        TestBed(const char fname[]) : processor_(0) 
        {
            strcpy(filename_, fname);
        };
        void setProcessor(int type, int width);
        void doIt();
    private:
        char filename_[256];
        FileProcessor *processor_;
};

void TestBed::setProcessor(int type, int width)
{
    if (processor_) 
            delete processor_;

    switch (type)
    {
        case Left:
            processor_ = new ProcessorLeft(filename_, width);
            break;
        case Right:
            processor_ = new ProcessorRight(filename_, width);
            break;
        case Center:
            processor_ = new ProcessorCenter(filename_, width);
            break;

#if 0
    case ULeft:
      processor_ = new ProcessorUpperCaseLeft(filename_, width);
      break;

    case URight:
      processor_ = new ProcessorUpperCaseRight(filename_, width);
      break;

    case UCenter:
      processor_ = new ProcessorUpperCaseCenter(filename_, width);
      break;
#endif

        default:
           processor_ = new ProcessorLeft(filename_, width);
    }
}

void TestBed::doIt()
{
    processor_ -> outputFile();
}

int main()
{
    TestBed test("quote.txt");
    int answer, width;
    cout << "Exit(0) Left(1) Right(2) Center(3) ULeft(4) URight(5) UCentre(6): ";
    cin >> answer;
    while (answer)
    {
        cout << "Width: ";
        cin >> width;
        test.setProcessor(answer, width);
        test.doIt();
        cout << "Exit(0) Left(1) Right(2) Center(3) ULeft(4) URight(5) UCentre(6): ";
        cin >> answer;
    }
    return 0;
}
