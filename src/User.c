#include "User.h"

void User_init(User* user) {
    user->searchSettings.refX = 100;
    user->searchSettings.refY = 100;
    user->searchSettings.color = 0x00FF00; // Example color (green)
    user->searchSettings.colorVariation = 10;
    user->searchSettings.sizeSearch = 10;
    user->searchSettings.minMatch = 5;
}
