#ifndef __TJobStream_H__
#define __TJobStream_H__

#include <cstdlib>

class TJobStream
{
private:
  double jobIntens;
  int lastJobId;
public:
  TJobStream(double _jobIntens);
  double GetJobIntens() const;
  int GetNewJob();
  int GetLastJobId() const;
};

#endif