#include "TJobStream.h"

TJobStream::TJobStream(double _jobIntens)
{
  if (_jobIntens >= 0.0 && _jobIntens <= 1.0)
  {
	jobIntens = _jobIntens;
	lastJobId = 1;
  }
  else { throw "Job intensivity is not correct"; }
}

double TJobStream::GetJobIntens() const 
{
  return jobIntens;
}

int TJobStream::GetNewJob()
{
  if (static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX) <= jobIntens)
  {
	lastJobId++;
	return (lastJobId - 1);
  }
  else { return 0; }
}

int TJobStream::GetLastJobId() const 
{
  return lastJobId;
}