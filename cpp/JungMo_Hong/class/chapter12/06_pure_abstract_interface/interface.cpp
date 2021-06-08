#include <iostream>
#include <string>

using namespace std;

// Interface Class
class IErrorLog
{
public:
    // 자식 클래스에서 반드시 구현해야함
    virtual bool reportError(const char *errorMessage) = 0;
    virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
    bool reportError(const char *errorMessage) override
    {
        cout << errorMessage << endl;
        cout << "Writing error to a file" << endl;
        return true;
    }
};

class ConsolErrorLog : public IErrorLog
{
public:
    bool reportError(const char *errorMessage) override
    {
        cout << errorMessage << endl;
        cout << "Printing error to a console" << endl;
        return true;
    }
};

// Interface 클래스가 매개변수가 된다.
// 재사용에 용이
void doSomething(IErrorLog &log)
{
    log.reportError("Runtime Error!!");
}

int main()
{
    FileErrorLog file_log;
    ConsolErrorLog consol_log;

    doSomething(file_log);
    doSomething(consol_log);

    return 0;
}