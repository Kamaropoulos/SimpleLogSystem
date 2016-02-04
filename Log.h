#pragma once

class Log {
public:
	bool Initialize();
	~Log();
	void LogWrite(char level[], char message[]);
};