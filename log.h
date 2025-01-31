
#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <time.h>
#include <string.h>

#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_YELLOW  "\x1b[33m"
#define COLOR_BLUE    "\x1b[34m"
#define COLOR_MAGENTA "\x1b[35m"
#define COLOR_CYAN    "\x1b[36m"
#define COLOR_RESET   "\x1b[0m"

#define LOG(caller,color,...){{  \
        printf(color);\
        time_t now = time(NULL);\
        struct tm *local_time = localtime(&now);\
        char* ctime = asctime(local_time); \
        ctime[strlen(ctime) - 1] = 0; \
        printf("[%s] [%s] ",caller,ctime); \
        printf(__VA_ARGS__);\
        printf(COLOR_RESET);\
    }}

#define RESET_COLOR() printf(COLOR_RESET);

#ifdef ENABLE_LOGGING

#define CORE_INFO(...) LOG("CORE",COLOR_GREEN,__VA_ARGS__);
#define CORE_WARNING(...) LOG("CORE",COLOR_YELLOW,__VA_ARGS__);
#define CORE_ERROR(EXIT,...) {{ \
                            LOG("CORE",COLOR_RED,__VA_ARGS__); \
                            LOG("CORE",COLOR_RED,"Aborting With %d\n",EXIT); \
                             exit(EXIT); \
                            }}
#define CORE_TRACE(...) LOG("CORE",COLOR_BLUE,__VA_ARGS__);

#define INFO(caller,...) LOG(caller,COLOR_GREEN,__VA_ARGS__);
#define WARNING(caller,...) LOG(caller,COLOR_YELLOW,__VA_ARGS__);
#define ERROR(caller,EXIT,...) {{ \
                            LOG(caller,COLOR_RED,__VA_ARGS__); \
                            LOG(caller,COLOR_RED,"Aborting With %d",EXIT); \
                             exit(EXIT); \
                            }}
#define TRACE(caller,...) LOG(caller,COLOR_BLUE,__VA_ARGS__);

#else

#define CORE_INFO(...) 
#define CORE_WARNING(...)
#define CORE_ERROR(...) 
#define CORE_TRACE(...) 

#define INFO(...) 
#define WARNING(...)
#define ERROR(...) 
#define TRACE(...) 

#endif // ENABLE_LOGGING
#endif // LOG_H
