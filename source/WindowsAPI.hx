package feather.core.backend;

#if windows
@:buildXml('
<target id="haxe">
    <lib name="dwmapi.lib" if="windows" />
    <lib name="shell32.lib" if="windows" />
    <lib name="gdi32.lib" if="windows" />
    <lib name="uxtheme.lib" if="windows" />
</target>
')
@:cppFileCode('
	#include <iostream>
	#include <Windows.h>
	#include <dwmapi.h>
	#include <shellapi.h>
	#include <uxtheme.h>
')
#end
/*
 * Custom Windows API
 * @author YoshiCrafter29
 */
class WindowsAPI {
	#if windows
	@:functionCode('
		int darkMode = active ? 1 : 0;
		HWND window = GetActiveWindow();
		if (S_OK != DwmSetWindowAttribute(window, 19, &darkMode, sizeof(darkMode)))
			DwmSetWindowAttribute(window, 20, &darkMode, sizeof(darkMode));
	')
	public static function setDarkBorder(active:Bool):Void {}
	#end
}