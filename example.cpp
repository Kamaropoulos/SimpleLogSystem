//Include SLS Header file
#include "Log.h"

int main() {

	//Create a Event Log Object
	Log* EventLog = new Log();

	//Initialize the Logger using the file name you want to use
	EventLog->Initialize("test.log");

	//Use Event Logger by applying the Log Level and the message you want to be logged
	EventLog->LogWrite("INFO", "This is a simple log message.");

	EventLog->LogWrite("WARNING", "This is a warning.");

	EventLog->LogWrite("ERROR", "This is an error.");

	//Finally, delete the Log object when you don't need it anymore
	delete EventLog;

	return 0;
}