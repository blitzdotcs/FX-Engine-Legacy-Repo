package;

import flixel.FlxG;
import flixel.graphics.frames.FlxAtlasFrames;
import openfl.utils.AssetType;
import openfl.utils.Assets as OpenFlAssets;
import flixel.graphics.FlxGraphic;
import haxe.Json;

using StringTools;

class ModPaths
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
		return OpenFlAssets.getText('mod/data/$string/haxeModchart.hx');
	}

	static public function loadJSON(key:String, ?library:String):Dynamic
	{
		var rawJson = OpenFlAssets.getText(ModPaths.json(key, library)).trim();

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
		return '$library:mods/$library/$file';
	}

	inline static function getPreloadPath(file:String)
	{
		return 'mods/$file';
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
		return 'songs:mods/songs/${song.toLowerCase()}/Voices.$SOUND_EXT';
	}

	inline static public function inst(song:String)
	{
		return 'songs:mods/songs/${song.toLowerCase()}/Inst.$SOUND_EXT';
	}

	inline static public function image(key:String, ?library:String)
	{
		return getPath('images/$key.png', IMAGE, library);
	}

	inline static public function video(key:String)
	{
		return 'mods/videos/$key';
	}

	inline static public function font(key:String)
	{
		return 'mods/fonts/$key';
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