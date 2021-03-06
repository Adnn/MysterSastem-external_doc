//-----------------------------------------------------------------------------
// MEKA - lightgun.c
// Light Phaser Emulation - Code
//-----------------------------------------------------------------------------

#include "shared.h"
#include "beam.h"
#include "lightgun.h"

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

void    LightPhaser_Init(void)
{
    LightPhaser.Enabled = FALSE;
    LightPhaser.LastSync = 0;
    LightPhaser.X [PLAYER_1] = LightPhaser.X [PLAYER_2] = 128;//cur_drv->x_res / 2;
    LightPhaser.Y [PLAYER_1] = LightPhaser.Y [PLAYER_2] = 96;//cur_drv->y_res / 2;
}

// Set mouse range - called in fullscreen mode only
void    LightPhaser_SetupMouseRange(bool left_most_column_masked)
{
    const int m = (left_most_column_masked ? 8 : 0);
    // Msg(MSGT_DEBUG, "ReRange %02X", ML8);
    set_mouse_range(m, 0, cur_drv->x_res - 1, cur_drv->y_res - 1);
}

u8		LightPhaser_GetX(void)
{
    const int r = LightPhaser.X [LightPhaser.LastSync] ; // + ((Mask_Left_8) ? 8 : 0);
    return (u8)(16 + (r / 2));
}

// FIXME: This old-fashioned code is incorrect. Light Phaser should be
// emulated using TH bit correctly and horizontal latch.
void    LightPhaser_Sync(int player, byte *v)
{
    int dx;
	int dy;

    *v |= ((player == PLAYER_1) ? 0x40 : 0x80);
    dx = LightPhaser.X[player] - Beam_Calc_X();
    dy = LightPhaser.Y[player] - tsms.VDP_Line;

    if (dy > -4 && dy < 4)                 // Arbitrary values found after
        if (dx > -48 && dx < 48)            // trying differents settings
        {
            *v &= (player == PLAYER_1) ? ~0x40 : ~0x80;
            LightPhaser.LastSync = player;
        }
}

// Light Phaser update function
// This is supposed to work with an analog mouse
// Fullscreen mode should be enabled to work properly
void    LightPhaser_Update(int player, int device_x, int device_y)
{
    LightPhaser.X[player] = device_x;
    LightPhaser.Y[player] = device_y;
    // LightGun_X = ((mouse_x + 28 + ((256 - mouse_x) >> 5)) & 0xFF) >> 1;
    // LightGun_Y = mouse_y + 1;
}

//-----------------------------------------------------------------------------

