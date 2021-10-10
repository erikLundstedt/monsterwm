/* see LICENSE for copyright and license */

#ifndef CONFIG_H
#define CONFIG_H

/** modifiers **/
#define MOD1            Mod1Mask    /* ALT key */
#define MOD4            Mod4Mask    /* Super/Windows key */
#define CONTROL         ControlMask /* Control key */
#define SHIFT           ShiftMask   /* Shift key */
#define SUPER           Mod4Mask    /* Super/Windows key */
/** generic settings **/
#define MASTER_SIZE     0.52
#define SHOW_PANEL      True      /* show panel by default on exec */
#define TOP_PANEL       True      /* False means panel is on bottom */
#define PANEL_HEIGHT    18        /* 0 for no space for panel, thus no panel */
#define DEFAULT_MODE    TILE      /* initial layout/mode: TILE MONOCLE BSTACK GRID FLOAT */
#define ATTACH_ASIDE    True      /* False means new window is master */
#define FOLLOW_WINDOW   False     /* follow the window when moved to a different desktop */
#define FOLLOW_MOUSE    False     /* focus the window the mouse just entered */
#define CLICK_TO_FOCUS  True      /* focus an unfocused window when clicked  */
#define FOCUS_BUTTON    Button3   /* mouse button to be used along with CLICK_TO_FOCUS */
#define BORDER_WIDTH    2         /* window border width */
#define FOCUS           "#ff950e" /* focused window border color    */
#define UNFOCUS         "#444444" /* unfocused window border color  */
#define MINWSZ          50        /* minimum window size in pixels  */
#define DEFAULT_DESKTOP 0         /* the desktop to focus initially */
#define DESKTOPS        4         /* number of desktops - edit DESKTOPCHANGE keys to suit */
#define NMASTER         1         /* number of windows in master area by default */

/**
 * open applications to specified desktop with specified mode.
 * if desktop is negative, then current is assumed
 */
static const AppRule rules[] = { \
    /*  class     desktop  follow  float */
    { "MPlayer",     3,    True,   False },
    { "Gimp",        0,    False,  True  },

};

/* helper for spawning shell commands */
#define SHCMD(cmd) {.com = (const char*[]){"/bin/sh", "-c", cmd, NULL}}

/**
 * custom commands
 * must always end with ', NULL };'
 */
static const char *termcmd[] = { "st",     NULL };
static const char *menucmd[] = { "dmenu_run", NULL };

#define DESKTOPCHANGE(K,N) \
    {  SUPER,             K,              change_desktop, {.i = N}}, \
    {  SUPER|ShiftMask,   K,              client_to_desktop, {.i = N}},

/**
 * keyboard shortcuts
 */
static Key keys[] = {
    /* modifier          key            function           argument */
    {  SUPER,            XK_b,          togglepanel,       {NULL}},
    {  SUPER,            XK_BackSpace,  focusurgent,       {NULL}},
    {  SUPER|SHIFT,      XK_c,          killclient,        {NULL}},
    {  SUPER,            XK_j,          next_win,          {NULL}},
    {  SUPER,            XK_k,          prev_win,          {NULL}},
    {  SUPER,            XK_d,          nmaster,           {.i = -1}},
    {  SUPER,            XK_i,          nmaster,           {.i = +1}},
    {  SUPER,            XK_h,          resize_master,     {.i = -10}}, /* decrease size in px */
    {  SUPER,            XK_l,          resize_master,     {.i = +10}}, /* increase size in px */
    {  SUPER,            XK_o,          resize_stack,      {.i = -10}}, /* shrink   size in px */
    {  SUPER,            XK_q,          resize_stack,      {.i = +10}}, /* grow     size in px */
    {  SUPER|CONTROL,    XK_h,          rotate,            {.i = -1}},
    {  SUPER|CONTROL,    XK_l,          rotate,            {.i = +1}},
    {  SUPER|SHIFT,      XK_h,          rotate_filled,     {.i = -1}},
    {  SUPER|SHIFT,      XK_l,          rotate_filled,     {.i = +1}},
    {  SUPER,            XK_Tab,        last_desktop,      {NULL}},
    {  SUPER|SHIFT,      XK_Return,     swap_master,       {NULL}},
    {  SUPER|SHIFT,      XK_j,          move_down,         {NULL}},
    {  SUPER|SHIFT,      XK_k,          move_up,           {NULL}},
    {  SUPER|SHIFT,      XK_t,          switch_mode,       {.i = TILE}},
    {  SUPER|SHIFT,      XK_m,          switch_mode,       {.i = MONOCLE}},
    {  SUPER|SHIFT,      XK_b,          switch_mode,       {.i = BSTACK}},
    {  SUPER|SHIFT,      XK_g,          switch_mode,       {.i = GRID}},
    {  SUPER|SHIFT,      XK_f,          switch_mode,       {.i = FLOAT}},

    {  SUPER|CONTROL,    XK_r,          quit,              {.i = 0}}, /* quit with exit value 0 */
    {  SUPER|CONTROL,    XK_q,          quit,              {.i = 1}}, /* quit with exit value 1 */




    {  SUPER,            XK_Return,     spawn,             {.com = termcmd}},
    {  SUPER,            XK_p,          spawn,             {.com = menucmd}},
    {  MOD1,             XK_j,          moveresize,        {.v = (int []){   0,  25,   0,   0 }}}, /* move down  */
    {  MOD1,             XK_k,          moveresize,        {.v = (int []){   0, -25,   0,   0 }}}, /* move up    */
    {  MOD1,             XK_l,          moveresize,        {.v = (int []){  25,   0,   0,   0 }}}, /* move right */
    {  MOD1,             XK_h,          moveresize,        {.v = (int []){ -25,   0,   0,   0 }}}, /* move left  */
    {  MOD1|SHIFT,       XK_j,          moveresize,        {.v = (int []){   0,   0,   0,  25 }}}, /* height grow   */
    {  MOD1|SHIFT,       XK_k,          moveresize,        {.v = (int []){   0,   0,   0, -25 }}}, /* height shrink */
    {  MOD1|SHIFT,       XK_l,          moveresize,        {.v = (int []){   0,   0,  25,   0 }}}, /* width grow    */
    {  MOD1|SHIFT,       XK_h,          moveresize,        {.v = (int []){   0,   0, -25,   0 }}}, /* width shrink  */
       DESKTOPCHANGE(    XK_F1,                             0)
       DESKTOPCHANGE(    XK_F2,                             1)
       DESKTOPCHANGE(    XK_F3,                             2)
       DESKTOPCHANGE(    XK_F4,                             3)
};
//st sysMenu
/**
 * mouse shortcuts
 */
static Button buttons[] = {
    {  super,    Button1,     mousemotion,   {.i = MOVE}},
    {  super,    Button3,     mousemotion,   {.i = RESIZE}},
    {  super,    Button3,     spawn,         {.com = menucmd}},
};
#endif

/* vim: set expandtab ts=4 sts=4 sw=4 : */
