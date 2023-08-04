package hxcodec.vlc;

#if (!(desktop || android) && macro)
#error "The current target platform isn't supported by hxCodec. If you're targeting Windows/Mac/Linux/Android and getting this message, please contact us."
#end
import haxe.io.Bytes;
import haxe.io.BytesData;
import haxe.io.Path;
import hxcodec.vlc.LibVLC;
import openfl.Lib;
import openfl.display.Bitmap;
import openfl.display.BitmapData;
import openfl.display3D.textures.RectangleTexture;
import openfl.events.Event;
import openfl.utils.ByteArray;

using StringTools;

/**
 * ...
 * @author Mihai Alexandru (M.A. Jigsaw).
 *
 * This class lets you to use LibVLC externs as a bitmap that you can displaylist along other items.
 */
@:cppNamespaceCode('
static unsigned format_setup(void **data, char *chroma, unsigned *width, unsigned *height, unsigned *pitches, unsigned *lines)
{
	VLCBitmap_obj *self = (VLCBitmap_obj*)(*data);

	unsigned _w = (*width);
	unsigned _h = (*height);

	(*pitches) = _w * 4;
	(*lines) = _h;

	memcpy(chroma, "RV32", 4);

	self->videoWidth = _w;
	self->videoHeight = _h;

	if (self->pixels != nullptr)
		delete self->pixels;

	self->pixels = new unsigned char[_w *_h * 4];
	return 1;
}

static void *lock(void *data, void **p_pixels)
{
	VLCBitmap_obj *self = (VLCBitmap_obj*) data;
	*p_pixels = self->pixels;
	return nullptr; /* picture identifier, not needed here */
}

static void callbacks(const libvlc_event_t *event, void *data)
{
	VLCBitmap_obj *self = (VLCBitmap_obj*) data;

	switch (event->type)
	{
		case libvlc_MediaPlayerOpening:
			self->flags[0] = true;
			break;
		case libvlc_MediaPlayerPlaying:
			self->flags[1] = true;
			break;
		case libvlc_MediaPlayerPaused:
			self->flags[2] = true;
			break;
		case libvlc_MediaPlayerStopped:
			self->flags[3] = true;
			break;
		case libvlc_MediaPlayerEndReached:
			self->flags[4] = true;
			break;
		case libvlc_MediaPlayerEncounteredError:
			self->flags[5] = true;
			break;
		case libvlc_MediaPlayerForward:
			self->flags[6] = true;
			break;
		case libvlc_MediaPlayerBackward:
			self->flags[7] = true;
			break;
	}
}')
@:keep
class VLCBitmap extends Bitmap
{
	// Variables
	public var videoWidth(default, null):cpp.UInt32 = 0;
	public var videoHeight(default, null):cpp.UInt32 = 0;

	public var time(get, set):Int;
	public var position(get, set):Float;
	public var length(get, never):Int;
	public var duration(get, never):Int;
	public var mrl(get, never):String;
	public var volume(get, set):Int;
	public var delay(get, set):Int;
	public var rate(get, set):Float;
	public var fps(get, never):Float;
	public var isPlaying(get, never):Bool;
	public var isSeekable(get, never):Bool;
	public var canPause(get, never):Bool;

	// Callbacks
	public var onOpening:Void->Void;
	public var onPlaying:Void->Void;
	public var onPaused:Void->Void;
	public var onStopped:Void->Void;
	public var onEndReached:Void->Void;
	public var onEncounteredError:String->Void;
	public var onForward:Void->Void;
	public var onBackward:Void->Void;

	// Declarations
	private var flags:Array<Bool> = [];
	private var pixels:cpp.RawPointer<cpp.UInt8>;
	private var buffer:BytesData = [];
	private var texture:RectangleTexture;

	// LibVLC
	private var instance:cpp.RawPointer<LibVLC_Instance_T>;
	private var mediaPlayer:cpp.RawPointer<LibVLC_MediaPlayer_T>;
	private var mediaItem:cpp.RawPointer<LibVLC_Media_T>;
	private var eventManager:cpp.RawPointer<LibVLC_EventManager_T>;

	public function new():Void
	{
		super(bitmapData, AUTO, true);

		for (event in 0...7)
			flags[event] = false;

		instance = LibVLC.create(0, null);
	}

	// Playback Methods
	public function play(?location:String = null, loop:Bool = false):Int
	{
		if (location.startsWith('https://') || location.startsWith('file://'))
		{
			#if HXC_DEBUG_TRACE
			trace("setting location to: " + location);
			#end

			mediaItem = LibVLC.media_new_location(instance, location);
		}
		else
		{
			final path:String = #if windows Path.normalize(location).split("/").join("\\") #else Path.normalize(location) #end;

			#if HXC_DEBUG_TRACE
			trace("setting path to: " + path);
			#end

			mediaItem = LibVLC.media_new_path(instance, path);
		}

		mediaPlayer = LibVLC.media_player_new_from_media(mediaItem);

		LibVLC.media_parse(mediaItem);
		LibVLC.media_add_option(mediaItem, loop ? "input-repeat=65535" : "input-repeat=0");
		LibVLC.media_release(mediaItem);

		if (texture != null)
		{
			texture.dispose();
			texture = null;
		}

		if (bitmapData != null)
		{
			bitmapData.dispose();
			bitmapData = null;
		}

		if (buffer != null && buffer.length > 0)
			buffer = [];

		LibVLC.video_set_format_callbacks(mediaPlayer, untyped __cpp__('format_setup'), null);
		LibVLC.video_set_callbacks(mediaPlayer, untyped __cpp__('lock'), null, null, untyped __cpp__('this'));

		eventManager = LibVLC.media_player_event_manager(mediaPlayer);

		LibVLC.event_attach(eventManager, LibVLC_EventType.MediaPlayerOpening, untyped __cpp__('callbacks'), untyped __cpp__('this'));
		LibVLC.event_attach(eventManager, LibVLC_EventType.MediaPlayerPlaying, untyped __cpp__('callbacks'), untyped __cpp__('this'));
		LibVLC.event_attach(eventManager, LibVLC_EventType.MediaPlayerPaused, untyped __cpp__('callbacks'), untyped __cpp__('this'));
		LibVLC.event_attach(eventManager, LibVLC_EventType.MediaPlayerStopped, untyped __cpp__('callbacks'), untyped __cpp__('this'));
		LibVLC.event_attach(eventManager, LibVLC_EventType.MediaPlayerEndReached, untyped __cpp__('callbacks'), untyped __cpp__('this'));
		LibVLC.event_attach(eventManager, LibVLC_EventType.MediaPlayerEncounteredError, untyped __cpp__('callbacks'), untyped __cpp__('this'));
		LibVLC.event_attach(eventManager, LibVLC_EventType.MediaPlayerForward, untyped __cpp__('callbacks'), untyped __cpp__('this'));
		LibVLC.event_attach(eventManager, LibVLC_EventType.MediaPlayerBackward, untyped __cpp__('callbacks'), untyped __cpp__('this'));

		return LibVLC.media_player_play(mediaPlayer);
	}

	public function stop():Void
	{
		if (mediaPlayer != null)
			LibVLC.media_player_stop(mediaPlayer);
	}

	public function pause():Void
	{
		if (mediaPlayer != null)
			LibVLC.media_player_set_pause(mediaPlayer, 1);
	}

	public function resume():Void
	{
		if (mediaPlayer != null)
			LibVLC.media_player_set_pause(mediaPlayer, 0);
	}

	public function dispose():Void
	{
		#if HXC_DEBUG_TRACE
		trace('disposing...');
		#end

		if (isPlaying)
			stop();

		if (stage.hasEventListener(Event.ENTER_FRAME))
			stage.removeEventListener(Event.ENTER_FRAME, onEnterFrame);

		if (texture != null)
		{
			texture.dispose();
			texture = null;
		}

		if (bitmapData != null)
		{
			bitmapData.dispose();
			bitmapData = null;
		}

		if (buffer != null && buffer.length > 0)
			buffer = [];

		onOpening = null;
		onPlaying = null;
		onStopped = null;
		onPaused = null;
		onEndReached = null;
		onEncounteredError = null;
		onForward = null;
		onBackward = null;

		#if HXC_DEBUG_TRACE
		trace('disposing done!');
		#end
	}

	// Internal Methods
	private var currentTime:Float = 0;

	private function onEnterFrame(?e:Event):Void
	{
		checkFlags();

		if (isPlaying && (videoWidth > 0 && videoHeight > 0) && pixels != null)
		{
			var time:Int = Lib.getTimer();
			var elements:Int = videoWidth * videoHeight * 4;
			render(Math.abs(time - currentTime), elements);
		}
	}

	private function render(deltaTime:Float, elementsCount:Int):Void
	{
		// Initialize the `texture` if necessary.
		if (texture == null)
			texture = Lib.current.stage.context3D.createRectangleTexture(videoWidth, videoHeight, BGRA, true);

		// Initialize the `bitmapData` if necessary.
		if (bitmapData == null && texture != null)
			bitmapData = BitmapData.fromTexture(texture);

		if (deltaTime > (1000 / (fps * rate)))
		{
			currentTime = deltaTime;

			cpp.NativeArray.setUnmanagedData(buffer, cpp.ConstPointer.fromRaw(pixels), elementsCount);

			if (texture != null && (buffer != null && buffer.length > 0))
			{
				var bytes:Bytes = Bytes.ofData(buffer);
				if (bytes.length >= elementsCount)
				{
					texture.uploadFromByteArray(ByteArray.fromBytes(bytes), 0);
					width++;
					width--;
				}
				#if HXC_DEBUG_TRACE
				else
					trace("Too small frame, can't render :(");
				#end
			}
		}
	}

	private function checkFlags():Void
	{
		if (flags[0])
		{
			flags[0] = false;
			if (onOpening != null)
				onOpening();
		}

		if (flags[1])
		{
			flags[1] = false;
			if (onPlaying != null)
				onPlaying();
		}

		if (flags[2])
		{
			flags[2] = false;
			if (onPaused != null)
				onPaused();
		}

		if (flags[3])
		{
			flags[3] = false;
			if (onStopped != null)
				onStopped();
		}

		if (flags[4])
		{
			flags[4] = false;
			if (onEndReached != null)
				onEndReached();
		}

		if (flags[5])
		{
			flags[5] = false;
			if (onEncounteredError != null)
				onEncounteredError(cast(LibVLC.errmsg(), String));
		}

		if (flags[6])
		{
			flags[6] = false;
			if (onForward != null)
				onForward();
		}

		if (flags[7])
		{
			flags[7] = false;
			if (onBackward != null)
				onBackward();
		}
	}

	// Get & Set Methods
	@:noCompletion private function get_time():Int
	{
		if (mediaPlayer != null)
		{
			#if (haxe >= "4.3.0")
			return LibVLC.media_player_get_time(mediaPlayer).toInt();
			#else
			return LibVLC.media_player_get_time(mediaPlayer);
			#end
		}

		return 0;
	}

	@:noCompletion private function set_time(value:Int):Int
	{
		if (mediaPlayer != null)
			LibVLC.media_player_set_time(mediaPlayer, value);

		return value;
	}

	@:noCompletion private function get_position():Float
	{
		if (mediaPlayer != null)
			return LibVLC.media_player_get_position(mediaPlayer);

		return 0;
	}

	@:noCompletion private function set_position(value:Float):Float
	{
		if (mediaPlayer != null)
			LibVLC.media_player_set_position(mediaPlayer, value);

		return value;
	}

	@:noCompletion private function get_length():Int
	{
		if (mediaPlayer != null)
		{
			#if (haxe >= "4.3.0")
			return LibVLC.media_player_get_length(mediaPlayer).toInt();
			#else
			return LibVLC.media_player_get_length(mediaPlayer);
			#end
		}

		return 0;
	}

	@:noCompletion private function get_duration():Int
	{
		if (mediaItem != null)
		{
			#if (haxe >= "4.3.0")
			return LibVLC.media_get_duration(mediaItem).toInt();
			#else
			return LibVLC.media_get_duration(mediaItem);
			#end
		}

		return 0;
	}

	@:noCompletion private function get_mrl():String
	{
		if (mediaItem != null)
			return cast(LibVLC.media_get_mrl(mediaItem), String);

		return null;
	}

	@:noCompletion private function get_volume():Int
	{
		if (mediaPlayer != null)
			return LibVLC.audio_get_volume(mediaPlayer);

		return 0;
	}

	@:noCompletion private function set_volume(value:Int):Int
	{
		if (mediaPlayer != null)
			LibVLC.audio_set_volume(mediaPlayer, value);

		return value;
	}

	@:noCompletion private function get_delay():Int
	{
		if (mediaPlayer != null)
		{
			#if (haxe >= "4.3.0")
			return LibVLC.audio_get_delay(mediaPlayer).toInt();
			#else
			return LibVLC.audio_get_delay(mediaPlayer);
			#end
		}

		return 0;
	}

	@:noCompletion private function set_delay(value:Int):Int
	{
		if (mediaPlayer != null)
			LibVLC.audio_set_delay(mediaPlayer, value);

		return value;
	}

	@:noCompletion private function get_rate():Float
	{
		if (mediaPlayer != null)
			return LibVLC.media_player_get_rate(mediaPlayer);

		return 0;
	}

	@:noCompletion private function set_rate(value:Float):Float
	{
		if (mediaPlayer != null)
			LibVLC.media_player_set_rate(mediaPlayer, value);

		return value;
	}

	@:noCompletion private function get_fps():Float
	{
		if (mediaPlayer != null)
			return LibVLC.media_player_get_fps(mediaPlayer);

		return 0;
	}

	@:noCompletion private function get_isPlaying():Bool
	{
		if (mediaPlayer != null)
			return LibVLC.media_player_is_playing(mediaPlayer);

		return false;
	}

	@:noCompletion private function get_isSeekable():Bool
	{
		if (mediaPlayer != null)
			return LibVLC.media_player_is_seekable(mediaPlayer);

		return false;
	}

	@:noCompletion private function get_canPause():Bool
	{
		if (mediaPlayer != null)
			return LibVLC.media_player_can_pause(mediaPlayer);

		return false;
	}

	@:noCompletion private override function set_height(value:Float):Float
	{
		if (__bitmapData != null)
			scaleY = value / __bitmapData.height;
		else if (videoHeight != 0)
			scaleY = value / videoHeight;
		else
			scaleY = 1;

		return value;
	}

	@:noCompletion private override function set_width(value:Float):Float
	{
		if (__bitmapData != null)
			scaleX = value / __bitmapData.width;
		else if (videoWidth != 0)
			scaleX = value / videoWidth;
		else
			scaleX = 1;

		return value;
	}

	@:noCompletion private override function set_bitmapData(value:BitmapData):BitmapData
	{
		__bitmapData = value;
		__setRenderDirty();
		__imageVersion = -1;
		return __bitmapData;
	}
}
