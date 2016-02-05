#SimpleLogSystem (SLS) [![Build Status](https://travis-ci.org/KostasLifeboy/SimpleLogSystem.svg?branch=master)](https://travis-ci.org/KostasLifeboy/SimpleLogSystem)
This is a very simple library for logging information into files.

##How to Use
Using SLS is really easy.  
You can check `example.cpp` for a sample program.

1. Download the `Log.h` header file.    
2. Copy and paste it on your project.    
3. Include the `Log.h` file in your program by using:  
   ```
   #include "Log.h"
   ```    
4. Create an Event Log object by using:  
   ```
   Log* EventLog = new Log();
   ```  
5. Initialize the log object:  
   ```
   EventLog->Initialize("test.log");
   ```  
   You can change the "test.log" to whatever you like.  
6. You are now ready to use the library. To write a log record use:  
   ```
   EventLog->LogWrite("INFO", "Example", "This is a simple log message.");
   ```  
   You can change "INFO" to whatever level of log you like. "Example" is the module that you log from.  
7. When you don't need SLS anymore delete the object by using:  
   ```
   delete EventLog;
   ```  
