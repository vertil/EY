#include "randDate.h"

randDate::randDate()
{
    
    for (int i = 65; i <= 90; i++) {
        g.push_back((char)i);
    }
    for (int i = 97; i <= 122; i++) {
        g.push_back((char)i);
    }

    for (int i = 192; i <= 255; i++) {
        h.push_back((char)i);
    }
    
}

std::string randDate::getRandDate()
{
    std::string answ;
    time_t rawtime;
    struct tm timeinfo;
    time(&rawtime);
    localtime_s(&timeinfo, &rawtime);
    
    year = rand() % 5 + (timeinfo.tm_year - 5);
    month = (rand() % 12 + 1);
    switch (month)
    {
        case 1:
            day = rand() % 31 + 1;
            break;
        case 2:
            if (year % 4 == 0) {
                day= rand() % 29 + 1;
            }
            else {
                day = rand() % 28 + 1;
            }
            break;
        case 3:
            day = rand() % 31 + 1;
            break;
        case 4:
            day = rand() % 30 + 1;
            break;
        case 5:
            day = rand() % 31 + 1;
            break;
        case 6:
            day = rand() % 30 + 1;
            break;
        case 7:
            day = rand() % 31 + 1;
            break;
        case 8:
            day = rand() % 31 + 1;
            break;
        case 9:
            day = rand() % 30 + 1;
            break;
        case 10:
            day = rand() % 31 + 1;
            break;
        case 11:
            day = rand() % 30 + 1;
            break;
        case 12:
            day = rand() % 31 + 1;
            break;
    
    }
    answ = std::to_string(day) + "." + std::to_string(month) +"."+ std::to_string(year+1900);

    return answ;
}

char randDate::randLat()
{
    
       
    return g[rand()%52];
}

char randDate::randRus()
{
   
    

    return h[rand()%63];
}

double randDate::randD()
{


    return (double)(rand()) / 20.0 * 1.0;
}

