package;

import flixel.FlxG;
import flixel.graphics.frames.FlxAtlasFrames;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;
import flixel.graphics.FlxGraphic;
import haxe.Json;

using StringTools;

class Paths
{
	inline public static var SOUND_EXT = #if web "mp3" #else "ogg" #end;

	static var currentLevel:String;

	static public function setCurrentLevel(name:String)
	{
		currentLevel = name.toLowerCase();
	}

	public static function getPath(file:String, type:AssetType, ?library:Null<String> = null)
	{
		if (library != null)
			return getLibraryPath(file, library);

		if (currentLevel != null)
		{
			var levelPath = getLibraryPathForce(file, currentLevel);
			if (OpenFlAssets.exists(levelPath, type))
				return levelPath;

			levelPath = getLibraryPathForce(file, currentLevel + '_high');
			if (OpenFlAssets.exists(levelPath, type))
				return levelPath;

			levelPath = getLibraryPathForce(file, "shared");
			if (OpenFlAssets.exists(levelPath, type))
				return levelPath;
		}

		return getPreloadPath(file);
	}

	static public function getHaxeScript(string:String)
	{
		return OpenFlAssets.getText('assets/data/$string/haxeModchart.hx');
	}

	static public function loadJSON(key:String, ?library:String):Dynamic
	{
		var rawJson = OpenFlAssets.getText(Paths.json(key, library)).trim();

		// Perform cleanup on files that have bad data at the end.
		while (!rawJson.endsWith("}"))
		{
			rawJson = rawJson.substr(0, rawJson.length - 1);
		}

		try
		{
			// Attempt to parse and return the JSON data.
			return Json.parse(rawJson);
		}
		catch (e)
		{
			Debug.logError("AN ERROR OCCURRED parsing a JSON file.");
			Debug.logError(e.message);

			// Return null.
			return null;
		}
	}

	static public function getLibraryPath(file:String, library = "preload")
	{
		return if (library == "preload" || library == "default") getPreloadPath(file); else getLibraryPathForce(file, library);
	}

	inline static function getLibraryPathForce(file:String, library:String)
	{
		return '$library:assets/$library/$file';
	}

	inline static function getPreloadPath(file:String)
	{
		return 'assets/$file';
	}

	inline static public function file(file:String, type:AssetType = TEXT, ?library:String)
	{
		return getPath(file, type, library);
	}

	inline static public function txt(key:String, ?library:String)
	{
		return getPath('data/$key.txt', TEXT, library);
	}

	inline static public function xml(key:String, ?library:String)
	{
		return getPath('data/$key.xml', TEXT, library);
	}

	inline static public function hx(key:String, ?library:String)
	{
		return getPath('data/$key.hx', TEXT, library);
	}

	inline static public function json(key:String, ?library:String)
	{
		return getPath('data/$key.json', TEXT, library);
	}

	static public function sound(key:String, ?library:String)
	{
		return getPath('sounds/$key.$SOUND_EXT', SOUND, library);
	}

	inline static public function soundRandom(key:String, min:Int, max:Int, ?library:String)
	{
		return sound(key + FlxG.random.int(min, max), library);
	}

	inline static public function music(key:String, ?library:String)
	{
		return getPath('music/$key.$SOUND_EXT', MUSIC, library);
	}

	inline static public function voices(song:String)
	{
		return 'songs:assets/songs/${song.toLowerCase()}/Voices.$SOUND_EXT';
	}

	inline static public function inst(song:String)
	{
		return 'songs:assets/songs/${song.toLowerCase()}/Inst.$SOUND_EXT';
	}

	inline static public function image(key:String, ?library:String)
	{
		return getPath('images/$key.png', IMAGE, library);
	}

	inline static public function video(key:String)
	{
		return 'assets/videos/$key';
	}

	inline static public function font(key:String)
	{
		return 'assets/fonts/$key';
	}

	inline static public function getSparrowAtlas(key:String, ?library:String)
	{
		return FlxAtlasFrames.fromSparrow(image(key, library), file('images/$key.xml', library));
	}

	inline static public function getPackerAtlas(key:String, ?library:String)
	{
		return FlxAtlasFrames.fromSpriteSheetPacker(image(key, library), file('images/$key.txt', library));
	}

	inline static public function getAnimateAtlas(key:String)
	{
		return animate.FlxAnimate.fromAnimate(loadImage('$key/spritemap1'), file('images/$key/spritemap1.json'));
	}
	
	static public function loadImage(key:String):FlxGraphic
	{
		var path = image(key);
	
		if (OpenFlAssets.exists(path))
		{
			var bitmap = OpenFlAssets.getBitmapData(path);
			return FlxGraphic.fromBitmapData(bitmap);
		}
		else
		{
			trace('Could not find image at path $path');
			return null;
		}
	}

	static public function listSongsToCache()
	{
		// We need to query OpenFlAssets, not the file system, because of Polymod.
		var soundAssets = OpenFlAssets.list(AssetType.MUSIC).concat(OpenFlAssets.list(AssetType.SOUND));
	
		// TODO: Maybe rework this to pull from a text file rather than scan the list of assets.
		var songNames = [];
	
		for (sound in soundAssets)
		{
			// Parse end-to-beginning to support mods.
			var path = sound.split('/');
			path.reverse();
	
			var fileName = path[0];
			var songName = path[1];
	
			if (path[2] != 'songs')
				continue;
	
			// Remove duplicates.
			if (songNames.indexOf(songName) != -1)
				continue;
	
			songNames.push(songName);
		}
	
		return songNames;
	}	
}

#if MODS_ALLOWED
class ModPaths extends Paths
{
        static final currentLevel:String = Paths.currentLevel;

	static public function file(file:String, mod:String)
	{
		var path = "";
		if (mod != null)
			path = 'mods/$mod/$file';
		else
			path = 'mods/$file';
		if (OpenFlAssets.exists(path))
			return path;

		return 'mods';
	}

	private static final SOUND_EXT = Paths.SOUND_EXT;

	inline static public function modIconImage(key:String, mod:String)
	{
		return file('$mod/_polymod_icon.png', mod);
	}

	inline static public function getModTxt(key:String, mod:String)
	{
		return file('data/$key.txt', mod);
	}

	inline static public function getModXml(key:String, mod:String)
	{
		return file('data/$key.xml', mod);
	}

	inline static public function getModGlobalTxt(key:String, mod:String)
	{
		return file('$key.txt', mod);
	}

	inline static public function getModGlobalXml(key:String, mod:String)
	{
		return file('$key.xml', mod);
	}

	inline static public function getModJson(key:String, mod:String)
	{
		return file('data/$key.json', mod);
	}

	inline static public function getModGlobalJson(key:String, mod:String)
	{
		return file('$key.json', mod);
	}

	static public function getModSound(key:String, mod:String)
	{
		return file('sounds/$key.$SOUND_EXT', mod);
	}

	inline static public function soundRandom(key:String, min:Int, max:Int, mod:String)
	{
		return getModSound(key + FlxG.random.int(min, max), mod);
	}

	inline static public function getModMusic(key:String, mod:String)
	{
		return file('music/$key.$SOUND_EXT', mod);
	}

	inline static public function getModVoices(song:String, mod:String)
	{
		return file('mods/$mod/songs/${song.toLowerCase()}/Voices.$SOUND_EXT', mod);
	}

	inline static public function getModInst(song:String, mod:String)
	{
		return file('mods/$mod/songs/${song.toLowerCase()}/Inst.$SOUND_EXT', mod);
	}

	inline static public function getModImage(key:String, mod:String)
	{
		return file('images/$key.png', mod);
	}

	inline static public function getModFont(key:String, mod:String)
	{
		return file('fonts/$key', mod);
	}

	inline static public function getModLua(key:String, mod:String)
	{
		return file('scripts/$key.lua', mod);
	}

	inline static public function getModGlobalLua(key:String, mod:String)
	{
		return file('$key.lua', mod);
	}

	inline static public function getModChar(key:String, mod:String)
	{
		return file('characters/$key.json', mod);
	}

	inline static public function getModLocales(key:String, mod:String)
	{
		return file('locales/$key/languageData.json', mod);
	}

	inline static public function getModFrag(key:String, mod:String)
	{
		return file('shaders/$key.frag', mod);
	}

	inline static public function getModVert(key:String, mod:String)
	{
		return file('shaders/$key.vert', mod);
	}

	inline static public function checkMod(mod:String)
	{
		return openfl.utils.Assets.exists('mods/$mod/_polymod_meta.json'); // THIS IS MANDATORY
	}

	inline static public function getModSparrowAtlas(key:String, mod:String)
	{
		return flixel.graphics.frames.FlxAtlasFrames.fromSparrow(getModImage(key, mod), file('images/$key.xml', mod));
	}

	inline static public function getModPackerAtlas(key:String, mod:String)
	{
		return FlxAtlasFrames.fromSpriteSheetPacker(getModImage(key, mod), file('images/$key.txt', mod));
	}
	
	inline static public function getModAnimateAtlas(key:String, mod:String)
	{
		return animate.FlxAnimate.fromAnimate(Paths.loadImage('$key/spritemap1'), file('images/$key/spritemap1.json', mod));
	}
}
#end