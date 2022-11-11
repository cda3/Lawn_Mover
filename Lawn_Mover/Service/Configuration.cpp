#include "Configuration.h"

Configuration::Configuration(std::shared_ptr<Cleaner> businessLogic, int runTime, int parallelismLevel)
{
	Runtime = runTime;
	ParallelismLevel = parallelismLevel;
	BusinessLogic = businessLogic;
}
