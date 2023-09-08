package scripting.funkinscript;

import WeekData;
import Highscore;
import Song;

import openfl.Lib;
import openfl.utils.Assets;
import openfl.display.BitmapData;
import flixel.FlxBasic;
import flixel.FlxObject;
import flixel.addons.transition.FlxTransitionableState;

#if (!flash && sys)
import flixel.addons.display.FlxRuntimeShader;
#end

#if sys
import sys.FileSystem;
import sys.io.File;
#end

import Note;
import NoteSplash;
import Character;

import MainMenuState;
import StoryMenuState;
import FreeplayState;

import PauseSubState;
import GameOverSubstate;
import GameOverState;
import hscript.HScript;

class FunkinScript 
{
    #if (SScript >= "3.0.0")
	public var hscript:HScript = null;
	#end

	public function new(scriptName:String) 
    {
        #if (SScript >= "3.0.0") HScript.implement(this); #end
		call('onCreate', []);
		#end
    }

	public function stop() 
    {
		#if (SScript >= "3.0.0")
		if(hscript != null)
		{
			hscript.active = false;
			hscript = null;
		}
		#end
	}

} 