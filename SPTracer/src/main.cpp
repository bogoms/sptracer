#include "App.h"
#include "SPTracer/Log.h"

int main(int argc, char **argv)
{
	SPTracer::Log::Info("SPTracer started");

	// config file
	std::string configFile = argc > 1 ? argv[1] : "sptracer.cfg";
	SPTracer::Log::Info("Config file: " + configFile);

	// create application
	App app(configFile);
	
	// check that application is initialized
	if (!app.IsInitialized())
	{
		return 1;
	}

	// run the application
	return app.Run();
}