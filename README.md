# dwm-neo64
dwm (Dynamic Window Manager) is a lightweight dynamic window manager by suckless.org. It is written in C to get great performance with little usage of resources. It is customized by editing the source code which keeps it simple, fast and lightweight. This is my heavily patched dwm build which is used on my daily driver. Still a work in progress.

### Screenshot
![screenshot](dwm.png)

### Patches that I currently using for this build:
* activetagindicatorbar (modified)
* actualfullscreen
* alternativetags
* aspectresize
* attachaside
* awesomebar
* bar height
* colorbar
* extrabar
* gridmode
* nodmenu
* resizecorners
* systray
* statusbutton
* swallow

### These files are installed on the system:
* /usr/local/bin/dwm (binary file)
* /usr/local/bin/dwm-session (shell script for detecting autostart file)
* /usr/share/xsessions/dwm.desktop (desktop entry)
* $XDG_CONFIG_HOME/dwm/autostart.sh (autostart file)

## Installation guide

### 1. Cloning this repository
Run this command:
```
git clone https://github.com/neo64yt/dwm-neo64.git
```

### 2. Dependencies
Required:
* libxcb
* Xlib-libxcb
* xcb-res
* ttf-jetbrains-mono (JetBrains Mono font)
* ttf-material-design-icons-extended (Material Icons font)

Optional (Probably for full experience of my rice):
* [My dotfiles](https://github.com/neo64yt/dwm-neo64)
* [My build of dwm](https://github.com/neo64yt/dmenu-neo64)
* [My build of slstatus](https://github.com/neo64yt/slstatus-neo64)

### 3. Installing dwm
You can either execute the install.sh script or run this in the terminal:
```
sudo make install 
```

### 4. Running dwm at startup & autostart applications
Autostart applications must be put into "$XDG_CONFIG_HOME/dwm/autostart.sh". It will be automatically detected by "/usr/local/bin/dwm-session".

This is a sample of autostart.sh:
```
#!/bin/sh
/usr/lib/mate-polkit/polkit-mate-authentication-agent-1 &
sxhkd -c $XDG_CONFIG_HOME/dwm/sxhkdrc &
# This example script starts mate-polkit and sxhkd with a custom config file
```

#### With display manager
A desktop entry file for dwm will be automatically installed to "/usr/share/xsessions/".

#### Without display manager
Put "exec /usr/local/bin/dwm-session" into your .xinitrc file.

## Customizing dwm
dwm is customized by editing the source code or patching it. To apply a patch, go to this build directory and execute:
```
patch < /directory/to/patch/file.diff
# Change the placeholder with a valid file location
```
If the patch has failed hunks, manually patch by reading the REJ files in this build directory to guide you.
Make sure you executed cleandir.sh file before recompiling dwm (executing install.sh)

## Keybindings
Will be updated soon in the man page!

## Start menu 
Please put your choice of start menu in the .xprofile file by setting the environment variable for $STARTPROMPT
Example:
```
export STARTPROMPT=rofi
```

