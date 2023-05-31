# FX Engine

This is the repository for FX Engine. A modification of a game that was originally made for Ludum Dare 47 "Stuck In a Loop".

# NOTE

* I AM NOT IN THE FNF COMMUNITY I'M JUST CONTINUING THIS TO LEARN MORE ABOUT HAXE.

# Features of FX Engine

- Ghost Tapping
- Choose between WASD and ZXNM!
- Working settings menu
- W.i.p. Modding support without source
- W.i.p. Character Selection! Press 6 while in-game. (Doesn't fully work yet sadly but it's progress!)
- Icon bopping!
- Custom Credits Menu
- Downscroll
- Somewhat working Cutscene support!
- Psych Engine Icon Support (for credits and freeplay only, when I tried it for the in-game stuff, the game kept crashing)
- Ingame Options Menu (Check the pause menu)
- A game crasher (In the options menu)

# FX Engine Main Credits

- LOOK IN THE CREDITS MENU DORK

# FX Engine Extra Credits

* Eddsworld Team - You'll see :)

### Build instructions

## Installing the Required Programs

First, you need to install Haxe and HaxeFlixel. I'm too lazy to write and keep updated with that setup (which is pretty simple). 
1. [Install Haxe 4.1.5](https://haxe.org/download/version/4.1.5/) (Any ver should work but I prefer 4.1.5)
2. [Install HaxeFlixel](https://haxeflixel.com/documentation/install-haxeflixel/) after downloading Haxe

Other installations you'd need are the additional libraries, a fully updated list will be in `Project.xml` in the project root. Currently, these are all of the things you need to install:
```
flixel 4.11.0
flixel-addons 2.11.0
openfl
flixel-ui
hscript
actuate
hxCodec
lime 7.9.0
```
So for each of those type `haxelib install [library]` so shit like `haxelib install newgrounds`

You'll also need to install a couple things that involve Gits. To do this, you need to do a few things first.
1. Download [git-scm](https://git-scm.com/downloads). Works for Windows, Mac, and Linux, just select your build.
2. Follow instructions to install the application properly.
3. Run `haxelib git polymod https://github.com/larsiusprime/polymod.git` to install Polymod.
4. Run `haxelib git discord_rpc https://github.com/Aidan63/linc_discord-rpc` to install Discord RPC.
5. Run `haxelib git extension-webm https://github.com/KadeDev/extension-webm` to install extension-webm
6. After that run `lime rebuild extension-webm <ie. windows, macos, linux>`

You should have everything ready for compiling the game! Follow the guide below to continue!

At the moment, you can optionally fix the transition bug in songs with zoomed-out cameras.
- Run `haxelib git flixel-addons https://github.com/HaxeFlixel/flixel-addons` in the terminal/command-prompt.

## Compiling game
NOTE: If you see any messages relating to deprecated packages, ignore them. They're just warnings that don't affect compiling

Once you have all those installed, it's pretty easy to compile the game. You just need to run `lime test html5 -debug` in the root of the project to build and run the HTML5 version. (command prompt navigation guide can be found here: [https://ninjamuffin99.newgrounds.com/news/post/1090480](https://ninjamuffin99.newgrounds.com/news/post/1090480))
To run it from your desktop (Windows, Mac, Linux) it can be a bit more involved. For Linux, you only need to open a terminal in the project directory and run `lime test linux -debug` and then run the executable file in export/release/linux/bin. For Windows, you need to install Visual Studio Community 2019. While installing VSC, don't click on any of the options to install workloads. Instead, go to the individual components tab and choose the following:
* MSVC v142 - VS 2019 C++ x64/x86 build tools
* Windows SDK (10.0.17763.0)

Once that is done you can open up a command line in the project's directory and run `lime test windows -debug`. Once that command finishes (it takes forever even on a higher end PC), you can run FNF from the .exe file under export\release\windows\bin
As for Mac, 'lime test mac -debug' should work, if not the internet surely has a guide on how to compile Haxe stuff for Mac.

## Additional guides

- [Command line basics](https://ninjamuffin99.newgrounds.com/news/post/1090480)
