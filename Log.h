#ifndef Log_H
#define Log_H

#include <iostream>
#include <fstream>
#include <time.h>

class Log {
private:
	std::ofstream LogFile;
	char buff[20];
	struct tm *sTm;

public:
	bool Initialize(char LogFileName[]) {
		LogFile.open(LogFileName, std::ios_base::app);
		LogWrite("INFO", "EventLog", "The Event Log service was started.");
		return true;
	}
	void LogWrite(char level[], char module[], char message[]) {
		time_t now = time(0);
		sTm = gmtime(&now);
		strftime(buff, sizeof(buff), "%Y-%m-%d %H:%M:%S", sTm);
		LogFile << buff << " " << level << ": [" <<  module << "] "<< message << std::endl;
	}
	~Log() {
		LogWrite("INFO", "EventLog", "The Event log service was stopped.");
		LogFile.close();
	}
};

#endif
