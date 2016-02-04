#ifndef Log_H
#define Log_H

#include <iostream>
#include <fstream>
#include <time.h>

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

#endif