/* See LICENSE file for copyright and license details. */

/* Window icon */
#define ICONSIZE 15   /* icon size */
#define ICONSPACING 5 /* space between icon and title */

/* appearance */
static const unsigned int borderpx       = 3;        /* border pixel of windows */
static const unsigned int snap           = 32;       /* snap pixel */
static const unsigned int systraypinning = 0;        /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */ 
static const unsigned int systrayonleft  = 0;        /* 0: systray in the right corner, >0: systray on left of status text */ 
static const unsigned int systrayspacing = 1;        /* systray spacing */ 
static const int systraypinningfailfirst = 1;        /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor */
static const int showsystray             = 1;        /* 0 means no systray */
static const int swallowfloating         = 0;        /* 1 means swallow floating windows by default */
static const int showbar                 = 1;        /* 0 means no bar */
static const int topbar                  = 1;        /* 0 means bottom bar */
static const int user_bh                 = 25;       /* 0 means that dwm will calculate bar height, >= 1 means dwm will user_bh as bar height */
static const char *fonts[]               = { "JetBrains Mono:size=11",
                                             "Material Design Icons:size=13" };
/* Color variables */
static const char grey[]            = "#272a34";
static const char white[]           = "#ffffff";
static const char teal[]        = "#12846e";
static const char black[]           = "#000000";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { white, grey, grey },
	[SchemeSel]  = { white, teal, teal  },
	[SchemeStatus]  = { white, teal,  black  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { teal, grey,  black  }, // Tagbar left selected {text,background,not used but cannot be empty}
	[SchemeTagsNorm]  = { white, black,  black  }, // Tagbar left unselected {text,background,not used but cannot be empty}
	[SchemeInfoSel]  = { teal, grey,  black  }, // infobar middle  selected {text,background,not used but cannot be empty}
	[SchemeInfoNorm]  = { white, black,  black  }, // infobar middle  unselected {text,background,not used but cannot be empty}
	[SchemeHid] = { teal, black, black },
};

/* tagging */
static const char *tags[] = { " 󰋜 ", " 󰺶 ", " 󰆍 ", " 󰆌 "," 󰐋 ", " 󰠔 " };
static const char *tagsalt[] = { " 󰎦 ", " 󰎩 ", " 󰎬 ", " 󰎮 ", " 󰎰 ", " 󰎵 " };

/* underline tags */
static const unsigned int ulinepad     = 5;    /* horizontal padding between the underline and tag */
static const unsigned int ulinestroke  = 2;    /* thickness / height of the underline */
static const unsigned int ulinevoffset = 1;    /* how far above the bottom of the bar the line should appear */

/* Default apps (Please input the window class or the window title of the app, can be determined using xprop) */
static const char web_browser[] = "Firefox";
static const char terminal[] = "Alacritty";
static const char img_editor[] = "Gimp";
static const char nested_x[] = "Xephyr";

/* Window rules */
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class                instance    title             tags mask     isfloating   isterminal  noswallow   monitor */
	/* Image editor */
	{ img_editor,           NULL,       NULL,             0,            0,           0,          0,          -1 },
	/* Web browser */
	{ web_browser,          NULL,       NULL,             1 << 3,       0,           0,          1,          -1 },
	/* Terminal */
	{ terminal,             NULL,       NULL,             0,            0,           1,          0,          -1 },
	/* Event Tester */
	{ NULL,                 NULL,       "Event Tester",   0,            0,           0,          1,          -1 },
	/* Xeypher */
	{ nested_x,             NULL,       NULL,             0,            0,           0,          1,          -1 },
	{ "anbox",		        NULL,	    NULL,    	      0,            0,           0, 	     1,          -1 },
	{ "Yad",		        NULL,       NULL,             0,            1,		     0,	         1,          -1 },
	{ "scrcpy",		        NULL,	    NULL,             0,            0,           0,          1,          -1 },
	{ "MEGAsync",		    NULL,	    NULL,	          0,    	    1,		     0,	         1, 		 -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int decorhints  = 1;    /* 1 means respect decoration hints */

#include "gaplessgrid.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󰙀",      tile },    /* first entry is default */
	{ "󱂬",      NULL },    /* no layout function means floating behavior */
	{ "󰼬",      monocle },
	{ "󰝘",      gaplessgrid },
    { "󱒅",      centeredmaster },
    { "󱒆",      centeredfloatingmaster },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *menucmd[] = { "rofi", "-show", "drun", NULL };
static const char *run_prompt[] = { "rofi", "-show", "run", NULL };
static const char *emojipick[] = { "rofi", "-modi", "emoji", "-show", "emoji", NULL };
static const char *prefapps[] = { "prefapps", NULL };

/* commands loaded from environment variables */
/* use the SHCMD macro when setting keybinds for them */
#define TERMCMD "$TERMINAL"
#define QUICKMENU "$QUICKMENU"
#define SETMGR "$SETTINGS_MGR"
#define SCRSHOT "$SCREENSHOOTER"
#define SESSIONMGR "$SESSION_MGR"
#define BROWSER "$BROWSER"

static Key keys[] = {
	/* modifier                     key        function        argument */
    
    /* dwm-related keybinds */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstackvis,  {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstackvis,  {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_j,      focusstackhid,  {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_k,      focusstackhid,  {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_h,      aspectresize,   {.i = -24} },
	{ MODKEY|ShiftMask,             XK_l,      aspectresize,   {.i = +24} },
	{ MODKEY|ShiftMask,             XK_x,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_g,      setlayout,      {.v = &layouts[3]} },
    { MODKEY,                       XK_u,      setlayout,      {.v = &layouts[4]} },
    { MODKEY,                       XK_o,      setlayout,      {.v = &layouts[5]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	{ MODKEY,                       XK_s,      show,           {0} },
	{ MODKEY,		                XK_x,      hide,           {0} },
	{ MODKEY,                       XK_a,      togglealttag,   {0} },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} },

    /* command keybinds */
    /* direct commands */
    { MODKEY,                       XK_r,               spawn,          {.v = menucmd } },
    { MODKEY,                       XK_p,               spawn,          {.v = run_prompt } },
    { MODKEY,                       XK_e,               spawn,          {.v = emojipick } },
    { MODKEY|ShiftMask,             XK_r,               spawn,          {.v = prefapps } },

    /* commands loaded from environment variables */
    { MODKEY|ShiftMask,             XK_Return,          spawn,          SHCMD(TERMCMD) },
    { MODKEY|ShiftMask,             XK_m,               spawn,          SHCMD(QUICKMENU) },
    { MODKEY|ShiftMask,             XK_s,               spawn,          SHCMD(SETMGR) },
    { 0,                            XK_Print,           spawn,          SHCMD(SCRSHOT) },
    { 0,                            XF86XK_PowerOff,    spawn,          SHCMD(SESSIONMGR) },
    { MODKEY,                       XK_w,               spawn,          SHCMD(BROWSER) }
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button1,        togglewin,      {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
