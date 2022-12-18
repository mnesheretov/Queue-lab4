#include "TProc.h"

TProc::TProc(double rate, int maxjobs)
{
  if (rate >= 0.0 && rate <= 1.0)
  {
	jobs = TQueue<int>(maxjobs);
	procRate = rate;
	jobsDone = 0;
	overflowTimes = 0;
	noJobTimes = 0;
  } else { throw "Proc rate is not correct"; }
}

double TProc::GetRate() const
{
  return procRate;
}

bool TProc::IsProcBusy() const
{
  if (jobs.IsEmpty()) { return false; }
  else { return true; }
}

bool TProc::IsProcFull() const
{
  return jobs.IsFull();
}

int TProc::RunNewJob(int jobId)
{
  if (jobId > 0)
  {
	if (IsProcFull())
	{
	  overflowTimes++;
	  return 0;
	}
	else
	{
	  jobs.Push(jobId);
	  return jobId;
	}
  }
  else { return 0; }
}

int TProc::DoJob()
{
  if (!(IsProcBusy()))
  {
	noJobTimes++;
	return 0;
  }
  else if (static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX) <= procRate && IsProcBusy())
  {
	int LastJob = jobs.TopPop();
	jobsDone++;
	return LastJob;
  }
  else { return jobs.Top(); }
}

int TProc::GetJobsDone() const
{
  return jobsDone;
}

int TProc::GetOverflowTimes() const
{
  return overflowTimes;
}

int TProc::GetNoJobTimes() const
{
  return noJobTimes;
}
