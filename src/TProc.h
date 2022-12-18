#ifndef __TProc_H__
#define __TProc_H__

#include "TQueue.h"
#include <cstdlib>

class TProc
{
private:
  double procRate;
  TQueue<int> jobs;
  int jobsDone;
  int overflowTimes;
  int noJobTimes;
public:
  TProc(double rate, int maxJobs);
  double GetRate() const;
  bool IsProcBusy() const;
  bool IsProcFull() const;
  int RunNewJob(int jobId);
  int DoJob();
  int GetJobsDone() const;
  int GetOverflowTimes() const;
  int GetNoJobTimes() const;
};
#endif
