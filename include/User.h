#ifndef USER_H
#define USER_H

typedef struct {
    int refX;
    int refY;
    int color;
    int colorVariation;
    int sizeSearch;
    int minMatch;
} SearchSettings;

typedef struct {
    SearchSettings searchSettings;
} User;

void User_init(User* user);

#endif
