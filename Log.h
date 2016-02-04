#pragma once

class Log {
public:
	bool Initialize(char LogFileName[]);
	~Log();
	void LogWrite(char level[], char message[]);
};