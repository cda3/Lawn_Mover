#include "Configuration_Prova.h"

Configuration_Prova::Configuration_Prova(std::shared_ptr<Cleaner2> businessLogic, int runTime, int parallelismLevel)
{
	Runtime = runTime;
	ParallelismLevel = parallelismLevel;
	BusinessLogic = businessLogic;
}
