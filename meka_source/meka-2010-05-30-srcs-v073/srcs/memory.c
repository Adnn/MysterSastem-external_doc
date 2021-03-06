//-----------------------------------------------------------------------------
// MEKA - memory.c
// Memory Tools - Code
//-----------------------------------------------------------------------------

#include "shared.h"

//-----------------------------------------------------------------------------
// Memory_Alloc (int size)
// Allocate memory using malloc(), abort if unavailable
//-----------------------------------------------------------------------------
void    *Memory_Alloc (int size)
{
 byte   *p;

 if ((p = malloc (size)) == NULL)
    {
    meka_errno = MEKA_ERR_MEMORY;
    Quit_Msg (meka_strerror());
    }
 return (p);
}

//-----------------------------------------------------------------------------

