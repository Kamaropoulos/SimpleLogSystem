#include <iostream>
#include <fstream>
#include "Log.h"
#include <time.h>
#include <string>

using namespace std;

class Log {
private:
	ofstream LogFile;
	char buff[20];
	struct tm *sTm;

public:
	bool Initialize(char LogFileName[]);
	void LogWrite(char level[], char message[]);
	~Log();
};

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