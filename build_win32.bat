set win32=.\build\win32
if exist %win32% (
    cd %win32%
    for /R %%s in (*.vcxproj,*.filters) do (
        del %%s
    )
    del CMakeCache.txt
    cd ..\..\
)

cmake.exe -S "./" -B "./build/win32" -G "Visual Studio 16 2019" -A Win32
pause