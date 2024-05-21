#ifndef FASTFIND_H
#define FASTFIND_H

#include <windows.h>
#include "User.h"

typedef int (*f_SnapShot)(int aLeft, int aTop, int aRight, int aBottom, int NoSnapShot);
typedef int (*f_GenericColorSearch)(int SizeSearch, int* NbMatchMin, int* XRef, int* YRef, int ColorToFind, int ShadeVariation, int NoSnapShot);

typedef struct {
    User* user;
    HINSTANCE dllHandle;
    f_SnapShot SnapShot;
    f_GenericColorSearch GenericColorSearch;
} FastFind;

void FastFind_init(FastFind* fastFind, User* user);
int FastFind_ScreenShoot(FastFind* fastFind);
int FastFind_ColorSearch(FastFind* fastFind, int* x, int* y);
void FastFind_cleanup(FastFind* fastFind);

#endif
