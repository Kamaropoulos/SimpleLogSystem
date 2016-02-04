#include "Log.h"

bool Log::Initialize(char LogFileName[]) {
	LogFile.open(LogFileName, std::ios_base::app);
	LogWrite("INFO", "The Event Log service was started.");
	return true;
}

void Log::LogWrite(char level[], char message[]) {
	time_t now = time(0);
	sTm = gmtime(&now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
	LogFile << buff << " " << level << ": " << message << endl;
}

Log::~Log() {
	LogWrite("INFO", "The Event log service was stopped.");
	LogFile.close();
}