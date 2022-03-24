# dwm-neo64

dwm (Dynamic Window Manager) is a lightweight dynamic window manager by suckless.org. It is written in C to get great performance with little usage of resources. It is customized by editing the source code which keeps it simple, fast and lightweight. This is my heavily patched dwm build which is used on my daily driver. Still a work in progress.

## Screenshot

![screenshot](dwm.png)

## Patches used in this build

* actualfullscreen
* alternativetags
* alwayscenter
* aspectresize
* attachaside
* awesomebar (2020-09-07 version)
* bar height
* centeredmaster
* clientindicators
* colorbar
* decorhints
* ewmhtags
* fixborders
* gaplessgrid
* monoclesymbol
* nodmenu
* resizecorners
* restartsig
* systray
* swallow
* tag preview
* underlinetags (modified)
* winicon

## Dependencies

* Xlib
* libxcb
* Xlib-libxcb
* xcb-res
* Imlib2
* libxft
* libxinerama
* ttf-jetbrains-mono (JetBrains Mono font)
* ttf-material-design-icons-extended (Material Icons font)

## Installation guide

### 1. Cloning this repository

Run this command:

```bash
git clone https://github.com/neo64yt/dwm-neo64.git
```

### 2. Installing dwm

You can either run the installation script (`install.sh`) or run this in the terminal:

```bash
sudo make install 
```

### 3. Running dwm and autostarting applications

#### Autostarting

Autostart applications must be put in `$XDG_CONFIG_HOME/dwm/autostart.sh`. It will be automatically detected by `/usr/local/bin/dwm-session`.

This is a sample of `autostart.sh`:

```bash
#!/bin/sh
# This example script starts mate-polkit and sxhkd with a custom config file
/usr/lib/mate-polkit/polkit-mate-authentication-agent-1 &
sxhkd -c $XDG_CONFIG_HOME/dwm/sxhkdrc &
```

#### Running dwm (with a display manager)

A desktop entry file for dwm will be automatically installed to `/usr/share/xsessions/`.

#### Running dwm (without a display manager)

Put `exec /usr/local/bin/dwm-session` into your `.xinitrc` file.

## Customizing dwm

dwm is customized by editing the source code or patching it. To apply a patch, go to this build directory and execute:

``` bash
patch < /directory/to/patch/file.diff
# Change the placeholder with a valid file location
```

If the patch has failed hunks, manually patch by reading the REJ files in this build directory to guide you.
Make sure you have ran `cleandir.sh` before recompiling dwm.

## Keybindings

Will be updated soon in the man page!
