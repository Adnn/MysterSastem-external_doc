//-----------------------------------------------------------------------------
// MEKA - inputs_t.h
// Inputs Tools - Headers
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
// Data
//-----------------------------------------------------------------------------

// FIXME: rename/clean/remove/...
#define NUM_ALPHA_KEYS  (26)
int     Key_Alpha_Table [NUM_ALPHA_KEYS];
char    Alpha_Table [NUM_ALPHA_KEYS];

//-----------------------------------------------------------------------------
// Functions
//-----------------------------------------------------------------------------

void    Inputs_Key_Eat                  (int keycode);

void    Inputs_KeyPressQueue_Remove     (t_key_press *keypress);
void    Inputs_KeyPressQueue_Clear      (void);

int     Inputs_KeyPressed               (int keycode, bool eat);
int     Inputs_KeyPressed_Repeat        (int keycode, bool eat, int delay, int rate);

//-----------------------------------------------------------------------------
