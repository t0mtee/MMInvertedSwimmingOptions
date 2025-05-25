#include "modding.h"
#include "global.h"
#include "recomputils.h"
#include "recompconfig.h"

extern Input* sPlayerControlInput;
s8 bStickX;
s8 bStickY;

RECOMP_HOOK("Player_Action_56") void Player_Action_56_Init(Player* this, PlayState* play) {
    bStickX = sPlayerControlInput->rel.stick_x;
    sPlayerControlInput->rel.stick_x = ((recomp_get_config_u32("invert_x") * -2) + 1) * bStickX;

    bStickY = sPlayerControlInput->rel.stick_y;
    sPlayerControlInput->rel.stick_y = ((recomp_get_config_u32("invert_y") * 2) - 1) * bStickY;
}

RECOMP_HOOK_RETURN("Player_Action_56") void Player_Action_56_Return() {
    sPlayerControlInput->rel.stick_x = bStickX;

    sPlayerControlInput->rel.stick_y = bStickY;
}