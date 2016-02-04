#include "Log.h"

using namespace std;

bool Log::Initialize(char LogFileName[]) {
	LogFile.open(LogFileName, std::ios_base::app);
	time_t now = time(0);
	sTm = gmtime(&now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
	LogFile << buff << " " << "INFO" << ": " << "The Event log service was started." << endl;
	return true;
}

void Log::LogWrite(char level[], char message[]) {
	time_t now = time(0);
	sTm = gmtime(&now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
	LogFile << buff << " " << level << ": " << message << endl;
}

Log::~Log() {
	time_t now = time(0);
	sTm = gmtime(&now);
	strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
	LogFile << buff << " " << "INFO" << ": " << "The Event log service was stopped." << endl;
	LogFile.close();
}