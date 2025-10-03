# dwm-pyromorphite

![Recoloured dwm logo](dwm-pyromorphite.png)

dwm-pyromorphite (formerly dwm-neo64) is a heavily customized build of dwm (currently based on dwm-6.5) and a part of Pyromorphite Desktop. Since I have used this build without any new customization for at least two years and I'm quite comfortable with it, do not ever expect it to have frequent updates and new patches applied. I may keep it up to date to the latest upstream version when I feel the need to though.  

## Screenshot

![Screenshot as of 2025-07-27](dwm.png)

## Patches used in this build

* actualfullscreen (a1ef02f9dedf91fdc41b873594b46d5965e4bf4f)
* alternativetags (97115d2ab782bd62004cb912dfdc1ec528ee5bc2)
* alwayscenter (71a8d47cbc283ba9140d11f9070a1b5c7de53cd7)
* aspectresize (a455a5a73b31aa9e5e2f7e8b00600b6c13019dc4)
* attachaside (38898c9fe0eb02f978ec98df728fc53dc4ed8328)
* awesomebar (668ef6b48b041767eba686326f6a26d09b95ab0b) 
* bar height (97d04c08fe63d3b743e442818042047b2e1b058d)
* centeredmaster (d568d93a94370023bb038ebf49045f975deed534)
* clientindicatorshidevacant (modified) (80d3af4d9a494338ef592c7212c586e07554758a & 3bd0e36d409f4a2aa2b37e3449948555e222d94e)
* decorhints (773f331eb8204e61d90a793a8d50b393a9873ff9)
* ewmhtags (fb9f9acfd47f5634f88e2c10532bf7ca3f682db7)
* fixborders (c4ede6631654bc3f6c660b84d765ccfbfac68dec)
* gaplessgrid (f80ec85e3e391f51258e2e9b8db79eca079753b4)
* nodmenu (9023f4a855fe08fb08f99f7716ba478f9c935b99)
* restartsig (4541e9fc7b430d6feff1c9eeeee86f1a7f139e3d)
* savefloats (18b65cb79afbefedd308e1a68f4fa4292065eaca)
* setenvvars (f8cc12a9da323a4aa693cd6410bf2ad675d793b7)
* steam (7008d414615b42e4e67018422e0ed89b7ac71c61)
* ~swallow (804ee0033a1c7f11826e4982f1567931378c98f9)~ (Use [devour](https://github.com/salman-abedin/devour) instead)
* systray (83764e710376532d771501a84dc0eb8096e9cc45)
* underlinetags (modified) (6fb931c92e7f0ec8525c988c2a5ed4f9b36505f4)
* urgentborder (ea95c96edb18346a565db885b63e341c0d6ba6af)
* winicon (2815ce38c5e8ed13f8200851992bc10c4dfe3dfa)

## Dependencies

* Xlib
* Imlib2
* libxft
* libxinerama
* JetBrains Mono font
* Material Design Icons font

## Installation guide

### 1. Cloning this repository

Run this command:

```bash
git clone https://codeberg.org/neo64yt/dwm-pyromorphite
```

### 2. Installing dwm

You can either run the installation script (`install.sh`) or run this in the terminal:

```bash
sudo make install 
```

### 3. Running dwm and autostarting applications

#### Autostarting

Autostart applications must be put in `$XDG_CONFIG_HOME/dwm/autostart.sh`. It will automatically be executed by `/usr/local/bin/dwm-session`.

This is a sample of `autostart.sh`:

```bash
#!/bin/sh
# This example script starts mate-polkit and sxhkd with a custom config file
/usr/lib/mate-polkit/polkit-mate-authentication-agent-1 &
sxhkd -c $XDG_CONFIG_HOME/dwm/sxhkdrc &
```

#### Environment variables

To load environment variables, put them under the `Env envs` array in `config.def.h`. For example, I have set the `XDG_CURRENT_DESKTOP` variable like below:

```c
static const Env envs[] = {
	/* variable			        value */
	{ "XDG_CURRENT_DESKTOP",	"dwm" },
};
```

#### Running dwm (with a display manager)

"Dynamic Window Manager (dwm)" should be an option available after installation.

#### Running dwm (using `startx`)

Put `exec /usr/local/bin/dwm-session` at the bottom of your `.xinitrc` file.

## dwm on HiDPI screens

My dwm build is adapted to be used with the screen DPI set to 192. To you use it at 96 DPI, you may want to set everything related to the appearance of the bar and border (except for the font size) to half of their original set values.    

## Making new customizations

You may want to make customizations on this dwm build to have it as your own. Just like the upstream build of dwm (or any other suckless software), customizations are made by editing the source code (mainly `config.def.h`) and applying patches. For a patching guide, refer to https://dwm.suckless.org/customisation/patches_in_git/ (the recommended method) or if you prefer not to use git, the method to do it (used by many dwm users, including me with this build) is:

```bash
patch -p1 < /path/to/patch.diff
```

When all the customizations you want to make are done, run the `cleandir.sh` script before reinstalling dwm again just like in the installation guide above.

## Keybindings

Will be updated soon in the man page!
