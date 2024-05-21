#include "FastFind.h"
#include <stdio.h>

void FastFind_init(FastFind* fastFind, User* user) {
    fastFind->user = user;
    fastFind->dllHandle = LoadLibrary(TEXT(".\\FastFind64.dll"));
    if (!fastFind->dllHandle) {
        fprintf(stderr, "Could not load the DLL\n");
        return;
    }

    fastFind->SnapShot = (f_SnapShot)GetProcAddress(fastFind->dllHandle, "SnapShot");
    fastFind->GenericColorSearch = (f_GenericColorSearch)GetProcAddress(fastFind->dllHandle, "GenericColorSearch");

    if (!fastFind->SnapShot || !fastFind->GenericColorSearch) {
        fprintf(stderr, "Could not locate functions\n");
        FreeLibrary(fastFind->dllHandle);
    }
}

int FastFind_ScreenShoot(FastFind* fastFind) {
    int screenWidth = GetSystemMetrics(SM_CXSCREEN);
    int screenHeight = GetSystemMetrics(SM_CYSCREEN);
    int fov = 100; // Example FOV

    return fastFind->SnapShot(
        screenWidth / 2 - fov / 2,
        screenHeight / 2 - fov / 2,
        screenWidth / 2 + fov / 2,
        screenHeight / 2 + fov / 2,
        1
    );
}

int FastFind_ColorSearch(FastFind* fastFind, int* x, int* y) {
    int minMatch = fastFind->user->searchSettings.minMatch;

    return fastFind->GenericColorSearch(
        fastFind->user->searchSettings.sizeSearch,
        &minMatch,
        x,
        y,
        fastFind->user->searchSettings.color,
        fastFind->user->searchSettings.colorVariation,
        1
    );
}

void FastFind_cleanup(FastFind* fastFind) {
    FreeLibrary(fastFind->dllHandle);
}
