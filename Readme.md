# Compiling and Building
## Windows
There are 2 shell script, build.ps1 (ps1 is powershell) and compile.ps1. If you did any change in ring_buffer files,
build all the project, for that run build.ps1 script. If you did any change in only main file, run compile.ps1 script.
You can adapt the compile and build script easily to linux. For windows, you should use below commands to run scripts:
If you want to run the scripts directly, it will give error
```
powershell -ExecutionPolicy Bypass -File compile.ps1
powershell -ExecutionPolicy Bypass -File build.ps1
```

## Linux
You will change script files extensions with .sh, and it will be much easier to run. If you didn't make the scripts executable
use following commands:
```
sh compile.sh
sh build.sh
```
Otherwise:
```
./compile.sh
./build.sh
```