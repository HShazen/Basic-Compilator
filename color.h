#ifndef COLOR_H
#define COLOR_H


#define GRI         "\x1b[45m"
#define RED         "\x1b[31m"
#define GREEN       "\x1b[32m"
#define YELLOW      "\x1b[33m"
#define BLUE        "\x1b[34m"
#define PURPULE     "\x1b[35m"
#define LIGHT_BLUE  "\x1b[36m"
#define WHITE       "\x1b[0m"
/*
char* typeColor (char *type) {
    if (!strcmp(type, "VAL"))                                               return YELLOW;
    else if (!(strcmp(type, "INT") && strcmp(type, "BOOL") && strcmp(type, "FLOAT") && strcmp(type, "CHAR") && strcmp(type, "STRING")))                                                      return LIGHT_BLUE;
    else if (!(strcmp(type, "opLOGIC") && strcmp(type, "opARITHMETIC")))    return PURPULE ;
    else if (!strcmp(type, "SEPARATOR"))                                    return GRI;
    else if (!strcmp(type, "KEY_WORD"))                                     return GREEN;
    else                                                                    return WHITE;
}*/

#endif