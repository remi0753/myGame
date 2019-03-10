#include "timeUtils.h"

#include <time.h>
#include <sys/time.h>

static struct timeval start;

void timeUtilsInit(){
  gettimeofday(&start, NULL);
}

unsigned int timeUtilsGetMilliSeconds(){
  struct timeval tv;
  gettimeofday(&tv, NULL);
  time_t diffsec = difftime(tv.tv_sec, start.tv_sec);
  suseconds_t diffusec = tv.tv_usec - start.tv_usec;
  return (unsigned int)diffsec * 1000 + (unsigned int)(diffusec / 1000);
}

