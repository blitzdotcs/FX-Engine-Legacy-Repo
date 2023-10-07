### THIS IS ON HOLD UNTIL I DECIDE TO FINISH IT

# FX Engine

This is the repository for FX Engine. A modification of a game that was originally made for Ludum Dare 47 "Stuck In a Loop".

# Links

* [Gamebanana Page](https://gamebanana.com/mods/447020)

* [Gamejolt Page](https://gamejolt.com/games/fnffxenginelmao/812241)  (not getting updated anymore on here)

# Features of FX Engine

- Ghost Tapping
- Custom Controls!
- Working settings menu
- Psych Modding Support!
- Character Selection!
- Icon bopping!
- Custom Credits Menu
- Downscroll
- Restored Dialogue!
- And more!

# FX Engine Main Credits
- [BlitzEX](https://twitter.com/BlitzEXlmao) - Main FX Engine Programmer
- [TyDev](https://twitter.com/TyDev_) - Original Main FX Engine Programmer
- [Chocolate Engine Team](https://github.com/Joalor64GH/Chocolate-Engine) - Better Credits
- [Funkin' Crew](https://github.com/FunkinCrew/) - Original Game Devs
- [Kade Engine Team](https://github.com/KadeDev/Kade-Engine) - I Stole some code
- [Psych Engine Team](https://github.com/ShadowMario/FNF-PsychEngine/) - I stole some code + modding system :3
- [EliteMasterEric](https://github.com/EliteMasterEric) - Modcore (used in older versions of FX Engine)
- FNF Restored Team - Dialogue code and assets
- OS Engine Devs - Icon bops and TitleState bg thing

### Build instructions

## Installing the Required Programs

First, you need to install Haxe and HaxeFlixel. I'm too lazy to write and keep updated with that setup (which is pretty simple). 
1. [Install Haxe 4.2.5](https://haxe.org/download/version/4.2.5/) (or latest)
2. [Install HaxeFlixel](https://haxeflixel.com/documentation/install-haxeflixel/) - Do this after downloading Haxe
3. Look at the shit that's in the workflow lmao

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
