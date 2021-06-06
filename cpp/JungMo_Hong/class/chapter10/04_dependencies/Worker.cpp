#include "Worker.h"

// cpp 파일에만 선언해도 됨.
#include "Timer.h"

void Worker::doSomething()
{

    Timer timer;

    // do some work here

    timer.elapsed();
}