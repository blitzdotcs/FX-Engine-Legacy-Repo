#desktop
import openfl.events.UncaughtErrorEvent;
import haxe.CallStack;
import haxe.io.Path;
import sys.FileSystem;
import sys.io.File;
import sys.io.Process;

class CrashHandler {
    public static function main() {
        // Set up crash handler
        Sys.setCrashHandler(onCrash);
        
        // Run your game code here
        // ...
    }
    
    private static function onCrash(e: UncaughtErrorEvent): Void {
        var errMsg: String = "";
        var path: String;
        var callStack: Array<CallStackItem> = CallStack.exceptionStack(true);
        var dateNow: String = Date.now().toString();

        dateNow = dateNow.replace(" ", "_");
        dateNow = dateNow.replace(":", "'");

        path = "./crash/" + "FXEngine_" + dateNow + ".txt";

        for (stackItem in callStack) {
            switch (stackItem) {
                case FilePos(s, file, line, column):
                    errMsg += file + " (line " + line + ")\n";
                default:
                    errMsg += stackItem.toString();
            }
        }

        errMsg += "\nUncaught Error: " + e.error + "\nPlease report this error to the GitHub page: https://github.com/TyDevX/FX-Engine\n\n> Crash Handler written by: sqirra-rng";

        if (!FileSystem.exists("./crash/"))
            FileSystem.createDirectory("./crash/");

        File.saveContent(path, errMsg + "\n");

        Sys.println(errMsg);
        Sys.println("Crash dump saved in " + Path.normalize(path));
        Sys.exit(1);
    }
}
#end