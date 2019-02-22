# aquantia
Porting AQC drivers to ESXi

This is a project aiming to port drivers for Aquantia's AQC line of ethernet devices to ESXi.

This requires a few components from the toolchain - see the files starting with `build` to see which components are used. 
I've been working on this on a CentOS 5.6 32-bit install, since I could compile most components of VWMware's ESXi toolchain compiled there. Compiling on a newer setup proved to be harder and the compilation didn't work so well. It could be that VMWare's instructions were not very accurate. The compilation of `binutils` proved to be complicate because VMWare didn't update all the versions with the necessary links to required components.

This porting has been started based on this tutorial: http://www.vm-help.com/forum/viewtopic.php?f=34&t=4340

Changes on the original code are usually marked with a 
```
#if defined (___VMKLNX___)
```

`aqc` is the public available source code on Atlantia's website.
`aqc2` is the development source code used by Atlantia.

I will try to maintain a list of most issues found when compiling.
