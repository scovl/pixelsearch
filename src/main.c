#include <stdio.h>
#include <windows.h>
#include "FastFind.h"
#include "User.h"

int main() {
    User user;
    User_init(&user);

    FastFind fastFind;
    FastFind_init(&fastFind, &user);

    int x = user.searchSettings.refX;
    int y = user.searchSettings.refY;

    if (!FastFind_ScreenShoot(&fastFind)) {
        fprintf(stderr, "Screenshot failed\n");
        return 1;
    }
    if (!FastFind_ColorSearch(&fastFind, &x, &y)) {
        fprintf(stderr, "Pixel search failed\n");
        return 1;
    }

    printf("Found color at (%d, %d)\n", x, y);

    FastFind_cleanup(&fastFind);
    return 0;
}
